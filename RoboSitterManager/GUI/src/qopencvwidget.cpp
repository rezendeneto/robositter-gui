#include "qopencvwidget.h"

QOpenCVWidget::QOpenCVWidget(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout;
    imagelabel = new QLabel;
    QImage dummy(100,100,QImage::Format_RGB32);
    image = dummy;
    layout->addWidget(imagelabel);

    for (int x = 0; x < 100; x ++) {
        for (int y =0; y < 100; y++) {
            image.setPixel(x,y,qRgb(x, y, y));
        }
    }

    imagelabel->setPixmap(QPixmap::fromImage(image));

    setLayout(layout);
}

QOpenCVWidget::~QOpenCVWidget(void) {

}

void QOpenCVWidget::putImage(IplImage *cvimage) {
    int cvIndex, cvLineStart;
    //imageColor = cvimage;
    // switch between bit depths
    switch (cvimage->depth) {
        case IPL_DEPTH_8U:
            switch (cvimage->nChannels) {
                case 3:
                    if ((cvimage->width != image.width()) || (cvimage->height != image.height())) {
                        QImage temp(cvimage->width, cvimage->height, QImage::Format_RGB32);
                        image = temp;
                    }
                    cvIndex = 0; cvLineStart = 0;
                    for (int y = 0; y < cvimage->height; y++) {
                        unsigned char red,green,blue;
                        cvIndex = cvLineStart;
                        for (int x = 0; x < cvimage->width; x++) {
                            // DO it
                            red = cvimage->imageData[cvIndex+2];
                            green = cvimage->imageData[cvIndex+1];
                            blue = cvimage->imageData[cvIndex+0];

                            image.setPixel(x,y,qRgb(red, green, blue));
                            cvIndex += 3;
                        }
                        cvLineStart += cvimage->widthStep;
                    }
                    break;
                default:
                    printf("This number of channels is not supported\n");
                    break;
            }
            break;
        default:
            printf("This type of IplImage is not implemented in QOpenCVWidget\n");
            break;
    }
    imagelabel->setPixmap(QPixmap::fromImage(image));
}

void QOpenCVWidget::setImageColor(IplImage *ic){
    imageColor = ic;
}

CvScalar QOpenCVWidget::getPixelColor(int i, int j){

        //IplImage* imgHSV = cvCreateImage(cvGetSize(imageColor), 8, 3);
        //cvCvtColor(imageColor, imgHSV, CV_BGR2HSV);
        //CvScalar res = cvGet2D(imgHSV,i,j);
        //cvReleaseImage(&imgHSV);
        cvSetImageROI(imageColor, cvRect(j-4, i-4, 9, 9));
        IplImage *img2 = cvCreateImage(cvGetSize(imageColor),imageColor->depth,imageColor->nChannels);
        cvCopy(imageColor, img2, NULL);
        cvResetImageROI(imageColor);
        //cvSmooth(img2,img2,CV_MEDIAN);
        int h[18];
        int minS = 100;
        int minV = 100;
        for(int m =0;m < 18;m++){
            h[m] = 0;
        }
        for(int k = 0;k < 9;k++){
            for(int l = 0;l < 9;l++){
                int x = cvGet2D(img2,l,k).val[0];
                if(x >=   0 && x <  30) h[ 0]++;
                if(x >=  10 && x <  40) h[ 1]++;
                if(x >=  20 && x <  50) h[ 2]++;
                if(x >=  30 && x <  60) h[ 3]++;
                if(x >=  40 && x <  70) h[ 4]++;
                if(x >=  50 && x <  80) h[ 5]++;
                if(x >=  60 && x <  90) h[ 6]++;
                if(x >=  70 && x < 100) h[ 7]++;
                if(x >=  80 && x < 110) h[ 8]++;
                if(x >=  90 && x < 120) h[ 9]++;
                if(x >= 100 && x < 130) h[10]++;
                if(x >= 110 && x < 140) h[11]++;
                if(x >= 120 && x < 150) h[12]++;
                if(x >= 130 && x < 160) h[13]++;
                if(x >= 140 && x < 170) h[14]++;
                if(x >= 150 && x < 180) h[15]++;
                if(x >= 160 || x <  10) h[16]++;
                if(x >= 170 || x <  20) h[17]++;
                //if(minS > cvGet2D(img2,l,k).val[1]) minS = cvGet2D(img2,l,k).val[1];
                //if(minV > cvGet2D(img2,l,k).val[2]) minV = cvGet2D(img2,l,k).val[2];
            }
        }
        int n = 0;
        for(int m =0;m < 18;m++){
            if(h[m] > h[n]) n = m;
        }



        int hue = (n * 10) + 15;
        if(hue >= 180) hue - 180;


        return cvScalar(hue,minS,minV);

}
