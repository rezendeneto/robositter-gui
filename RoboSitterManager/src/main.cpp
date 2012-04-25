#include <QtGui/QApplication>
#include "GUI/src/mainwindow.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    MainWindow mw;
    mw.show();

    mw.loadVideoFile("");
    mw.playVideo();

    return a.exec();

}
