#include <QtGui/QApplication>
#include "GUI/src/mainwindow.h"
#include "connrobo.h"

#define CAM_INDEX 0

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CvCapture *camera = cvCaptureFromCAM(CAM_INDEX);
    //CvCapture *camera = cvCreateCameraCapture(CAM_INDEX);

    if(!camera)
        return 0;

    MainWindow *mainWindow = new MainWindow(camera);
    mainWindow->show();

    return a.exec();
}
