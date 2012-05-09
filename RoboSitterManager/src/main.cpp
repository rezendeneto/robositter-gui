#include <QtGui/QApplication>
#include "GUI/src/mainwindow.h"

int main(int argc, char *argv[]) {

    //CvCapture * camera = cvCreateCameraCapture(0);

    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow(cvCaptureFromCAM(0));
    mainWindow->show();

    return a.exec();

}
