#include "connrobo.h"


ConnRobo::ConnRobo(MainWindow *mw) {

    mainWin = mw;
    connStatus = false;
    sending = false;


    start();

}

void ConnRobo::run() {

    while(true){
        if(!sending){
            ping();
            msleep(500);
        }
    }

}

void ConnRobo::ping() {

    connStatus = send();
    if(connStatus != mainWin->getConnRobot()) mainWin->setConnRobot(connStatus);

}

bool ConnRobo::send(){

    int randomValue = qrand() % (99 + 1);

    if(randomValue < 5) return false;
    else return true;

}

bool ConnRobo::getConnStatus(){

    return connStatus;

}
