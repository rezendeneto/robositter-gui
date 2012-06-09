#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMouseEvent>
#include <QMainWindow>
#include <QGridLayout>
#include <QString>
#include <QThread>
#include <QTimer>

#include "qopencvwidget.h"
#include "configwidget.h"
#include "colortracker.h"
#include "src/kid.h"
#include "src/connrobo.h"

#include <cv.h>
#include <highgui.h>


using namespace std;

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
        Kid* kid;
        ConnRobo* cr;

        bool autoMode;
        bool connCam;
        bool connRobot;

        QString status;
        QString alert;

        void setStatusInfo();

        int cc;

        //intervalo de cores que será selecionado
        int initialH;
        int initialS;
        int initialV;
        int finalH;
        int finalS;
        int finalV;

    public:
        explicit MainWindow(CvCapture *cam, QWidget *parent = 0);
        ~MainWindow();
        void addAlertInfo(QString addedAlert);
        void setConnRobot(bool cr);
        bool getConnRobot();
        bool getAutoMode();
        void update();
        Kid* getKid();

        QObject* getUIButton(int i);



    private slots:
        void on_actionChangeMode_triggered();
        void on_actionSair_triggered();
        void on_actionConfigura_o_triggered();
        void mInitialH();
        void pInitialH();
        void mFinalH();
        void pFinalH();
        void mInitialS();
        void pInitialS();
        void mFinalS();
        void pFinalS();
        void mInitialV();
        void pInitialV();
        void mFinalV();
        void pFinalV();
        void resetColor();
        void setStart();

        void bMoveF();
        void bMoveB();
        void bMoveL();
        void bMoveR();
        void bRotL();
        void bRotR();
        void bStop();

protected:
        void timerEvent(QTimerEvent*);
        void mousePressEvent(QMouseEvent *event);





};

#endif // MAINWINDOW_H
