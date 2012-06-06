#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(CvCapture *cam, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    autoMode = false;
    connCam = true;
    connRobot = false;
    camera = cam;

    setStatusInfo();

    QGridLayout *grid = new QGridLayout(ui->videoWidget);
    grid->setSpacing(0);
    cvwidget = new QOpenCVWidget(this);
    grid->addWidget(cvwidget);
    setLayout(grid);

    cc = 1;

    QTimer *t = new QTimer( this );
    t->setSingleShot(false);
    connect( t,  SIGNAL( timeout() ),this, SLOT( update() ));
    t->start(100);

    startTimer(10);
}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::setConnRobot(bool cr) {

    connRobot = cr;
}

bool MainWindow::getConnRobot() {

    return connRobot;

}

/*
 *
 * Private
 *
 */

void MainWindow::update(){

    setStatusInfo();
    repaint();

}

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

void MainWindow::timerEvent(QTimerEvent*) {
    IplImage *frame = cvQueryFrame(camera);

    cvwidget->putImage(ColorTracker::doTracking(frame));
}
