#ifndef COLORTRACKER_H
#define COLORTRACKER_H

#include <cv.h>
#include <highgui.h>
#include <cvblob.h>

#include "src/kid.h"

using namespace std;
using namespace cvb;

class ColorTracker
{
private:
    static IplImage* getThresholdedImage(IplImage *image, int initialH, int initialS, int initialV, int finalH, int finalS, int finalV);

public:
    ColorTracker();
    static IplImage* doTracking(IplImage *frame,IplImage *frameHSV, int initialH, int initialS, int initialV, int finalH, int finalS, int finalV,Kid *k);
    static CvScalar convertRGBtoHSV(CvScalar cvs);

};

#endif // COLORTRACKER_H
