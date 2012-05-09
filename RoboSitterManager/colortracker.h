#ifndef COLORTRACKER_H
#define COLORTRACKER_H

#include <cv.h>

class ColorTracker
{
private:
    static IplImage* getThresholdedImage(IplImage *image);
public:
    ColorTracker();

    static IplImage* doTracking(IplImage *frame);
};

#endif // COLORTRACKER_H
