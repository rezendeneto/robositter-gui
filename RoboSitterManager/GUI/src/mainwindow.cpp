#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(CvCapture *cam, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    autoMode = false;
    connCam = true;
    connRobot = false;
    camera = cam;
    kid = new Kid();
    cr = new ConnRobo(kid);

    initialH = -1;
    initialS = 100;
    initialV = 70;
    finalH = -1;
    finalS = 255;
    finalV = 255;

    setStatusInfo();

    QGridLayout *grid = new QGridLayout(ui->videoWidget);
    grid->setSpacing(0);
    cvwidget = new QOpenCVWidget(this);
    grid->addWidget(cvwidget);
    setLayout(grid);

    cc = 1;

    /*QTimer *t = new QTimer( this );
    t->setSingleShot(false);
    connect( t,  SIGNAL( timeout() ),this, SLOT( update() ));
    t->start(100);
    */
    startTimer(10);

    //qApp->installEventFilter(this);
    connect ( ui->buttonMMinH, SIGNAL( clicked() ), this, SLOT( mInitialH() )  );
    connect ( ui->buttonPMinH, SIGNAL( clicked() ), this, SLOT( pInitialH() )  );

    connect ( ui->buttonMMaxH, SIGNAL( clicked() ), this, SLOT( mFinalH() )  );
    connect ( ui->buttonPMaxH, SIGNAL( clicked() ), this, SLOT( pFinalH() )  );

    connect ( ui->buttonMMinS, SIGNAL( clicked() ), this, SLOT( mInitialS() )  );
    connect ( ui->buttonPMinS, SIGNAL( clicked() ), this, SLOT( pInitialS() )  );

    connect ( ui->buttonMMaxS, SIGNAL( clicked() ), this, SLOT( mFinalS() )  );
    connect ( ui->buttonPMaxS, SIGNAL( clicked() ), this, SLOT( pFinalS() )  );

    connect ( ui->buttonMMinV, SIGNAL( clicked() ), this, SLOT( mInitialV() )  );
    connect ( ui->buttonPMinV, SIGNAL( clicked() ), this, SLOT( pInitialV() )  );

    connect ( ui->buttonMMaxV, SIGNAL( clicked() ), this, SLOT( mFinalV() )  );
    connect ( ui->buttonPMaxV, SIGNAL( clicked() ), this, SLOT( pFinalV() )  );

    connect ( ui->buttonResetColor, SIGNAL( clicked() ), this, SLOT( resetColor() )  );
    connect ( ui->buttonSetStart,  SIGNAL( clicked() ), this,SLOT( setStart() ) );

    connect ( ui->buttonUP, SIGNAL( pressed() ), this, SLOT( bMoveF() )  );
    connect ( ui->buttonUP, SIGNAL( released() ), this, SLOT( bStop() )  );

    connect ( ui->buttonDOWN, SIGNAL( pressed() ), this, SLOT( bMoveB() )  );
    connect ( ui->buttonDOWN, SIGNAL( released() ), this, SLOT( bStop() )  );

    connect ( ui->buttonLEFT, SIGNAL( pressed() ), this, SLOT( bMoveL() )  );
    connect ( ui->buttonLEFT, SIGNAL( released() ), this, SLOT( bStop() )  );

    connect ( ui->buttonRIGHT, SIGNAL( pressed() ), this, SLOT( bMoveR() )  );
    connect ( ui->buttonRIGHT, SIGNAL( released() ), this, SLOT( bStop() )  );

    connect ( ui->buttonRotLEFT, SIGNAL( pressed() ), this, SLOT( bRotL() )  );
    connect ( ui->buttonRotLEFT, SIGNAL( released() ), this, SLOT( bStop() )  );

    connect ( ui->buttonRotRIGHT, SIGNAL( pressed() ), this, SLOT( bRotR() )  );
    connect ( ui->buttonRotRIGHT, SIGNAL( released() ), this, SLOT( bStop() )  );

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

bool MainWindow::getAutoMode(){
    return autoMode;
}

Kid* MainWindow::getKid(){
    return kid;
}

QObject* MainWindow::getUIButton(int i){
    switch(i){
        case(1):
            return ui->buttonUP;
        case(2):
            return ui->buttonDOWN;
        case(3):
            return ui->buttonLEFT;
        case(4):
            return ui->buttonRIGHT;
        case(5):
            return ui->buttonRotLEFT;
        case(6):
        default:
            return ui->buttonRotRIGHT;
            break;
    }

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
        /*if(connCam)*/status.operator +=("<font color=#00FF00>On</font> <br>");
        /*else status.operator +=("<font color=#FF0000>Off</font> <br>");*/

        connRobot = cr->getConnStatus();
        status.operator +=("Conexão do Robô:");
        if(connRobot)status.operator +=("<font color=#00FF00>On</font> <br>");
        else status.operator +=("<font color=#FF0000>Off</font> <br>");

        status.operator +=("Modo:");
        if(autoMode)status.operator +=("Auto <br>");
        else status.operator +=("Manual <br>");

        status.operator +=("<br>Cor: <br> ");

        status.operator +=("-H: ");
        status.operator +=(QString::number(initialH));
        status.operator +=(" - ");
        status.operator +=(QString::number(finalH));
        status.operator +=("<br>");

        status.operator +=("-S: ");
        status.operator +=(QString::number(initialS));
        status.operator +=(" - ");
        status.operator +=(QString::number(finalS));
        status.operator +=("<br>");

        status.operator +=("-V: ");
        status.operator +=(QString::number(initialV));
        status.operator +=(" - ");
        status.operator +=(QString::number(finalV));
        status.operator +=("<br>");

        status.operator +=("<br> PosX: ");
        status.operator +=(QString::number(kid->getX()));
        status.operator +=("<br> PosY: ");
        status.operator +=(QString::number(kid->getY()));
        status.operator +=("<br> area:");
        status.operator +=(QString::number(kid->getArea()));
        status.operator +=("<br> Largura:");
        status.operator +=(QString::number(kid->getWidth()));
        status.operator +=("<br> Altura");
        status.operator +=(QString::number(kid->getHeight()));
        status.operator +=("<br>");
        status.operator +=(QString::number(kid->getScreen_width()/2));
        status.operator +=("<br>");
        status.operator +=(QString::number(kid->getStart_width()));
        status.operator +=("<br>");

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

    cr->setAutoMode(autoMode);

    ui->buttonDOWN->setEnabled(!autoMode);
    ui->buttonLEFT->setEnabled(!autoMode);
    ui->buttonRIGHT->setEnabled(!autoMode);
    ui->buttonUP->setEnabled(!autoMode);
    ui->buttonRotLEFT->setEnabled(!autoMode);
    ui->buttonRotRIGHT->setEnabled(!autoMode);

    setStatusInfo();


}


void MainWindow::on_actionConfigura_o_triggered()
{

    //ConfigWidget cw;
    //cw.show();


}


void MainWindow::on_actionSair_triggered()
{

}

void MainWindow::timerEvent(QTimerEvent*) {
    IplImage *frame = cvQueryFrame(camera);
    IplImage *frameHSV = cvCreateImage(cvGetSize(frame), 8, 3);
    cvCvtColor(frame, frameHSV, CV_BGR2HSV);
    cvwidget->putImage(ColorTracker::doTracking(frame,frameHSV,initialH,initialS,initialV,finalH,finalS,finalV,kid));
    cvwidget->setImageColor(frameHSV);
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
  if ( initialH == -1)
  {

        //statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
        //QPoint qp = cvwidget->mapFromGlobal(QCursor::pos());
        CvScalar hsv = cvwidget->getPixelColor( event->pos().y(),event->pos().x());
        //cout << cvs.val[0] << "   " << cvs.val[1] << "    " << cvs.val[2] << endl;
        //CvScalar cvs = ColorTracker::convertRGBtoHSV(hsv);


        //cout << qp.x() << "   "<< qp.y()<< endl;
        //cout <<event->pos().x()<< "    " << event->pos().y()<<endl;

        initialH = hsv.val[0] - 15;
        if(initialH < 0) initialH += 180;
        finalH = hsv.val[0] + 15;
        if(finalH >= 180) finalH -= 180;
        //initialS = hsv.val[1];
        //initialV = hsv.val[2];



  }

}

void MainWindow::mInitialH(){
    if(initialH > 0)initialH--;
}
void MainWindow::pInitialH(){
    if(initialH < 179)initialH++;
}
void MainWindow::mFinalH(){
    if(finalH > 0)finalH--;
}
void MainWindow::pFinalH(){
    if(finalH < 179)finalH++;
}
void MainWindow::mInitialS(){
    if(initialS > 0)initialS--;
}
void MainWindow::pInitialS(){
    if(initialS < 255)initialS++;
}
void MainWindow::mFinalS(){
    if(finalS > 0)finalS--;
}
void MainWindow::pFinalS(){
    if(finalS < 255)finalS++;
}
void MainWindow::mInitialV(){
    if(initialV > 0)initialV--;
}
void MainWindow::pInitialV(){
    if(initialV < 255)initialV++;
}
void MainWindow::mFinalV(){
    if(finalV > 0)finalV--;
}
void MainWindow::pFinalV(){
    if(finalV < 255)finalV++;
}
void MainWindow::resetColor(){
    initialH = -1;
    finalH = -1;
    initialS = 100;
    finalS = 255;
    initialV = 70;
    finalV = 255;
    kid->setStartValues(-1,-1,-1);
    kid->setLostable(false);

}
void MainWindow::setStart(){
    if(initialH != -1){
    kid->setStartValues(kid->getArea(),kid->getWidth(),kid->getHeight());
    //if(initialH != -1){
        kid->setLostable(true);
    }
}

void MainWindow::bMoveF(){
    cr->send_MOVE_FORWARD();
}
void MainWindow::bMoveB(){
    cr->send_MOVE_BACKWARD();
}

void MainWindow::bMoveL(){
    cr->send_MOVE_LEFT();
}
void MainWindow::bMoveR(){
    cr->send_MOVE_RIGHT();
}
void MainWindow::bRotL(){
    cr->send_ROTATE_LEFT();
}
void MainWindow::bRotR(){
    cr->send_ROTATE_RIGHT();
}
void MainWindow::bStop(){
    cr->send_STOP();
}
