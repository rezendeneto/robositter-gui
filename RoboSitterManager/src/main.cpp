#include <QtGui/QApplication>
#include "GUI/src/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CvCapture *camera = cvCaptureFromCAM(1);

    if(!camera)
        return 0;

    MainWindow *mainWindow = new MainWindow(camera);
    mainWindow->show();

    return a.exec();
}
