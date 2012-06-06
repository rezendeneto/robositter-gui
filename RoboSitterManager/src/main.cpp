#include <QtGui/QApplication>
#include "GUI/src/mainwindow.h"
#include "connrobo.h"

#define CAM_INDEX 1

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CvCapture *camera = cvCaptureFromCAM(CAM_INDEX);

    if(!camera)
        return 0;

    MainWindow *mainWindow = new MainWindow(camera);
    mainWindow->show();

    ConnRobo cr(mainWindow);

    return a.exec();
}
