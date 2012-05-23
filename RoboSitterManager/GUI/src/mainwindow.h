#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QString>
#include <QThread>
#include <QTimer>

#include "qopencvwidget.h"
#include "configwidget.h"
#include "colortracker.h"

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

        int cc;

    public:
        explicit MainWindow(CvCapture *cam, QWidget *parent = 0);
        ~MainWindow();
        void addAlertInfo(QString addedAlert);
        void setConnRobot(bool cr);
        bool getConnRobot();

    private slots:
        void on_actionChangeMode_triggered();
        void on_actionSair_triggered();
        void on_actionConfigura_o_triggered();

    protected:
        void timerEvent(QTimerEvent*);

    public slots:
        void update();

};

#endif // MAINWINDOW_H
