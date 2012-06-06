#include "colortracker.h"

ColorTracker::ColorTracker()
{

}

int _initialH = 48;
int _initialS = 81;
int _initialV = 59;

int _finalH = 95;
int _finalS = 255;
int _finalV = 255;

IplImage* ColorTracker::getThresholdedImage(IplImage* img) {
        // Converte a imagem em uma imagem com cores no padrão HSV
        IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
        cvCvtColor(img, imgHSV, CV_BGR2HSV);

        // Cria uma imagem de threshold a partir de img
        IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

        // Valores de 20,100,100 até 30,255,255 estão funcionando perfeitamente para o amarelo em torno das 6h
        cvInRangeS(imgHSV, cvScalar(_initialH, _initialS, _initialV), cvScalar(_finalH, _finalS, _finalV), imgThreshed);

        // Libera memória para o objeto imgHSV
        cvReleaseImage(&imgHSV);

        return imgThreshed;
}

IplImage* ColorTracker::doTracking(IplImage *frame) {
    IplImage* thresholdedImage = getThresholdedImage(frame);

    int minx=10000, miny=10000;
    int maxx=0, maxy=0;

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
    }

    cvRectangle(frame, cvPoint(minx, miny), cvPoint(maxx == 0 ? -10 : maxx, maxy == 0 ? -10 : maxy), CV_RGB(255,0,0), 3, 0, 0);

    return frame;
}
