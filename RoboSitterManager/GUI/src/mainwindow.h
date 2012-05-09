#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QString>

#include "qopencvwidget.h"

#include "configwidget.h"

#include <cv.h>
#include <highgui.h>


namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;

        QOpenCVWidget *cvwidget;
        CvCapture *camera;

        bool autoMode;
        bool connCam;
        bool connRobot;

        QString status;
        QString alert;

        void setStatusInfo();
        void addAlertInfo(QString addedAlert);

        int cc;

    public:
        explicit MainWindow(CvCapture *cam, QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_actionChangeMode_triggered();
        void on_actionSair_triggered();
        void on_actionConfigura_o_triggered();

    protected:
        void timerEvent(QTimerEvent*);
};

#endif // MAINWINDOW_H
