#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(CvCapture *cam, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    autoMode = false;
    connCam = false;
    connRobot = false;
    camera = cam;

    setStatusInfo();

    QGridLayout *grid = new QGridLayout(ui->videoWidget);
    grid->setSpacing(0);
    cvwidget = new QOpenCVWidget(this);
    grid->addWidget(cvwidget);
    setLayout(grid);

    cc = 1;

    startTimer(10);
}

MainWindow::~MainWindow() {

    delete ui;

}

/*
 *
 * Private
 *
 */

void MainWindow::setStatusInfo(){

    status.clear();

    status.operator +=("Conexão de Vídeo:");
    if(connCam)status.operator +=("<font color=#00FF00>On</font> <br>");
    else status.operator +=("<font color=#FF0000>Off</font> <br>");

    status.operator +=("Conexão do Robô:");
    if(connRobot)status.operator +=("<font color=#00FF00>On</font> <br>");
    else status.operator +=("<font color=#FF0000>Off</font> <br>");

    status.operator +=("Modo:");
    if(autoMode)status.operator +=("Auto <br>");
    else status.operator +=("Manual <br>");

    ui->textStatus->setText(status);

}

void MainWindow::addAlertInfo(QString addedAlert){

    alert.operator +=(addedAlert);
    alert.operator +=(addedAlert.setNum(cc));
    cc++;
    ui->textAlert->setText(alert);
    ui->textAlert->scroll(10,10);
    ui->textAlert->update();

}

/*
 *
 * Action
 *
 */
void MainWindow::on_actionChangeMode_triggered() {

    autoMode = !autoMode;

    ui->buttonDOWN->setEnabled(!autoMode);
    ui->buttonLEFT->setEnabled(!autoMode);
    ui->buttonRIGHT->setEnabled(!autoMode);
    ui->buttonUP->setEnabled(!autoMode);

    setStatusInfo();

}


void MainWindow::on_actionConfigura_o_triggered()
{

    ConfigWidget cw;
    cw.show();

}


void MainWindow::on_actionSair_triggered()
{

}

int _initialH = 8;
int _initialS = 64;
int _initialV = 161;

int _finalH = 30;
int _finalS = 255;
int _finalV = 255;

IplImage* GetThresholdedImage(IplImage* img) {
        // Converte a imagem em uma imagem com cores no padrão HSV
        IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
        cvCvtColor(img, imgHSV, CV_BGR2HSV);

        // Cria uma imagem de threshold a partir de img
        IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

        // Valores de 20,100,100 até 30,255,255 estão funcionando perfeitamente para o amarelo em torno das 6h
        cvInRangeS(imgHSV, cvScalar(_initialH, _initialS, _initialV), cvScalar(_finalH, _finalS, _finalV), imgThreshed);

        // Libera memória para o objeto imgHSV
        cvReleaseImage(&imgHSV);

        return imgThreshed;
}

void MainWindow::timerEvent(QTimerEvent*) {
    IplImage *frame = cvQueryFrame(camera);

    // Holds the yellow thresholded image (yellow = white, rest = black)
    IplImage* imgYellowThresh = GetThresholdedImage(frame);

    int minx=10000, miny=10000;
    int maxx=0, maxy=0;

    for (int h = 0; h < imgYellowThresh->height; h++) {
            for (int w = 0; w < imgYellowThresh->width; w++) {
                    CvScalar currentColor = cvGet2D(imgYellowThresh,h,w);
                    if(currentColor.val[0] > 0 || currentColor.val[1] > 0 || currentColor.val[2] > 0) {
                            if (w > maxx)
                                    maxx = w;
                            if (h > maxy)
                                    maxy = h;
                            if (w < minx)
                                    minx = w;
                            if (h < miny)
                                    miny = h;
                    }
            }
    }

    cvRectangle(frame, cvPoint(minx,miny), cvPoint(maxx,maxy), CV_RGB(255,0,0), 3, 0, 0);

    cvwidget->putImage(frame);
}
