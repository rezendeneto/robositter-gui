#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, MainWindow *mw) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    autoMode = false;
    connCam = false;
    connRobot = false;

    setStatusInfo();

    vp = new Phonon::VideoPlayer(Phonon::VideoCategory, ui->centralwidget );

    //connect(ui->buttonMA, SIGNAL(clicked()), ui->videoWidget, SLOT(play()));

    QGridLayout *grid = new QGridLayout(ui->videoWidget);
    grid->setSpacing(0);
    grid->addWidget(vp, 0, 0, 0, 0);
    setLayout(grid);

    cc = 1;
}

MainWindow::~MainWindow() {

    delete ui;

}

/*
 *
 * Private
 *
 */

void MainWindow::loadVideoFile(char *path){

    vp->load(Phonon::MediaSource(path));

}

void MainWindow::playVideo(){

    vp->play();

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
