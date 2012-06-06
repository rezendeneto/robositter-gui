#include "colortracker.h"

ColorTracker::ColorTracker()
{

}

IplImage* ColorTracker::getThresholdedImage(IplImage* img, int initialH, int initialS, int initialV, int finalH, int finalS, int finalV) {
            // Converte a imagem em uma imagem com cores no padrão HSV
            IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
            cvCvtColor(img, imgHSV, CV_BGR2HSV);

            // Cria uma imagem de threshold a partir de img
            IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

            // Valores de 20,100,100 até 30,255,255 estão funcionando perfeitamente para o amarelo em torno das 6h
            if(initialH != -1){
                if(initialH <= finalH)
                    cvInRangeS(imgHSV, cvScalar(initialH, initialS, initialV), cvScalar(finalH, finalS, finalV), imgThreshed);
                else{
                    IplImage* imgThreshed2 = cvCreateImage(cvGetSize(img), 8, 1);
                    IplImage* imgThreshed3 = cvCreateImage(cvGetSize(img), 8, 1);

                    cvInRangeS(imgHSV, cvScalar(initialH, initialS, initialV), cvScalar(179, finalS, finalV), imgThreshed2);
                    cvInRangeS(imgHSV, cvScalar(0, initialS, initialV), cvScalar(finalH, finalS, finalV), imgThreshed3);

                    cvAdd(imgThreshed3, imgThreshed2, imgThreshed, NULL);

                    cvReleaseImage(&imgThreshed2);
                    cvReleaseImage(&imgThreshed3);
                }
            }

            //cvNamedWindow("My Window", CV_WINDOW_AUTOSIZE );
            //cvShowImage("My Window",imgThreshed);


            // Libera memória para o objeto imgHSV
            cvReleaseImage(&imgHSV);

            return imgThreshed;
}

IplImage* ColorTracker::doTracking(IplImage *frame, int initialH, int initialS, int initialV, int finalH, int finalS, int finalV,Kid *k) {
    IplImage* thresholdedImage = getThresholdedImage(frame,initialH,initialS,initialV,finalH,finalS,finalV);
        //imagem para o blob
        IplImage* labelImg = cvCreateImage(cvGetSize(frame),IPL_DEPTH_LABEL,1);
        CvBlobs blobs;
        //melhora a qualidade do Threshold
        cvSmooth(thresholdedImage,thresholdedImage,CV_MEDIAN,7,7);


        unsigned int result = cvLabel(thresholdedImage,labelImg,blobs);

        //int minx=10000, miny=10000;
        //int maxx=0, maxy=0;

        //cvNamedWindow("My Window", CV_WINDOW_AUTOSIZE );
        //cvShowImage("My Window",thresholdedImage);
        cvFilterByArea(blobs,250,500000);

        CvBlob *blob;

        if(cvGreaterBlob(blobs) != 0){
            blob=blobs[cvGreaterBlob(blobs)];
            cvRenderBlob(labelImg,blob,frame,frame);
            k->setX(blob->centroid.x);
            k->setY(blob->centroid.y);
            k->setWidth(blob->maxx - blob->minx);
            k->setHeight(blob->maxy - blob->miny);
            k->setArea(blob->area);
            if(k->getStart_area() == -1){
                k->setStartValues(blob->area,blob->maxx - blob->minx,blob->maxy - blob->miny,cvGetSize(frame).width,cvGetSize(frame).height);
            }
            k->setLost(false);
        } else {
            k->setX(-1);
            k->setY(-1);
            k->setArea(-1);
            k->setWidth(-1);
            k->setHeight(-1);
            k->setLost(true);
        }




        /*int screenx = GetSystemMetrics(SM_CXSCREEN);
        int screeny = GetSystemMetrics(SM_CYSCREEN);

        for (CvBlobs::const_iterator it=blobs.begin(); it!=blobs.end(); ++it){
            double moment10 = it->second->m10;
            double moment01 = it->second->m01;
            double area = it->second->area;
            //Variable for holding position
            int x1;
            int y1;
            //Calculating the current position
            x1 = moment10/area;
            y1 = moment01/area;
            //Mapping to the screen coordinates
            int x=(int)(x1*screenx/cvGetSize(frame).width);
            int y=(int)(y1*screeny/cvGetSize(frame).height);
            //Printing the position information
            cout<<"X: "<<x<<" Y: "<<y<<endl;



        }


        //Sem blob
        for (int h = 0; h < thresholdedImage->height; h++) {
                for (int w = 0; w < thresholdedImage->width; w++) {
                        CvScalar currentColor = cvGet2D(thresholdedImage,h,w);
                        if(currentColor.val[0] > 0 || currentColor.val[1] > 0 || currentColor.val[2] > 0) {
                                if (w > maxx)
                                        maxx = w;
                                if (h > maxy)
                                        maxy = h;
                                if (w < minx)
                                        minx = w;
                                if (h < miny)
                                        miny = h;


                        }
                }
        }*/

       // cvRectangle(frame, cvPoint(minx, miny), cvPoint(maxx == 0 ? -10 : maxx, maxy == 0 ? -10 : maxy), CV_RGB(255,0,0), 3, 0, 0);

        cvReleaseImage(&thresholdedImage);
        cvReleaseImage(&labelImg);

        return frame;

}

CvScalar ColorTracker::convertRGBtoHSV(CvScalar cvs){

    float fR, fG, fB;
    float fH, fS, fV;
    const float FLOAT_TO_BYTE = 255.0f;
    const float BYTE_TO_FLOAT = 1.0f / FLOAT_TO_BYTE;
    // Get the RGB pixel components. NOTE that OpenCV stores RGB pixels in B,G,R order.

    int bB = cvs.val[0];	// Blue component
    int bG = cvs.val[1];	// Green component
    int bR = cvs.val[2];	// Red component

    // Convert from 8-bit integers to floats.
    fR = bR * BYTE_TO_FLOAT;
    fG = bG * BYTE_TO_FLOAT;
    fB = bB * BYTE_TO_FLOAT;

    // Convert from RGB to HSV, using float ranges 0.0 to 1.0.
    float fDelta;
    float fMin, fMax;
    int iMax;

    // Get the min and max, but use integer comparisons for slight speedup.
    if (bB < bG) {
       if (bB < bR) {
          fMin = fB;
          if (bR > bG) {
              iMax = bR;
              fMax = fR;
           }else {
               iMax = bG;
               fMax = fG;
           }
        } else {
            fMin = fR;
            fMax = fG;
            iMax = bG;
        }
    }else {
        if (bG < bR) {
            fMin = fG;
            if (bB > bR) {
                fMax = fB;
                iMax = bB;
            }else {
                fMax = fR;
                iMax = bR;
            }
        }else {
            fMin = fR;
            fMax = fB;
            iMax = bB;
        }
    }
            fDelta = fMax - fMin;
            fV = fMax;				// Value (Brightness).
            if (iMax != 0) {			// Make sure its not pure black.
                fS = fDelta / fMax;		// Saturation.
                float ANGLE_TO_UNIT = 1.0f / (6.0f * fDelta);	// Make the Hues between 0.0 to 1.0 instead of 6.0
                if (iMax == bR) {		// between yellow and magenta.
                    fH = (fG - fB) * ANGLE_TO_UNIT;
                }
                else if (iMax == bG) {		// between cyan and yellow.
                    fH = (2.0f/6.0f) + ( fB - fR ) * ANGLE_TO_UNIT;
                }
                else {				// between magenta and cyan.
                    fH = (4.0f/6.0f) + ( fR - fG ) * ANGLE_TO_UNIT;
                }
                // Wrap outlier Hues around the circle.
                if (fH < 0.0f)
                    fH += 1.0f;
                if (fH >= 1.0f)
                    fH -= 1.0f;
            }
            else {
                // color is pure Black.
                fS = 0;
                fH = 0;	// undefined hue
            }

            // Convert from floats to 8-bit integers.
            int bH = (int)(0.5f + fH * 255.0f);
            int bS = (int)(0.5f + fS * 255.0f);
            int bV = (int)(0.5f + fV * 255.0f);

            // Clip the values to make sure it fits within the 8bits.
            if (bH > 255)
                bH = 255;
            if (bH < 0)
                bH = 0;
            if (bS > 255)
                bS = 255;
            if (bS < 0)
                bS = 0;
            if (bV > 255)
                bV = 255;
            if (bV < 0)
                bV = 0;

            // Set the HSV pixel components.
            CvScalar hsv;
            hsv.val[0] = bH * 180 / 255;		// H component
            hsv.val[1] = bS;		// S component
            hsv.val[2] = bV;		// V component

    return hsv;
}


