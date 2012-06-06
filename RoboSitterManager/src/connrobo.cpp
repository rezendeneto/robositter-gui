#include "connrobo.h"


ConnRobo::ConnRobo(Kid* k) {

    connStatus = false;
    sending = false;

    control = new Control(k);

    start();

}

void ConnRobo::run() {

    while(true){
        ping();
        if(autoMode){

            switch(control->action()){
                case(Control::STOP):
                send_STOP();
                break;
                case(Control::MOVE_FORWARD):
                send_MOVE_FORWARD();
                break;
                case(Control::MOVE_BACKWARD):
                send_MOVE_BACKWARD();
                break;
                case(Control::MOVE_LEFT):
                send_MOVE_LEFT();
                break;
                case(Control::MOVE_RIGHT):
                send_MOVE_RIGHT();
                break;
                case(Control::ROTATE_LEFT):
                send_ROTATE_LEFT();
                break;
                case(Control::ROTATE_RIGHT):
                send_ROTATE_RIGHT();
                break;
                case(Control::STAY):
                default:
                break;

            }
            msleep(500);
        }
    }

}

bool ConnRobo::ping() {

    connStatus = send();
    return connStatus;

}



bool ConnRobo::send(){

    int randomValue = qrand() % (99 + 1);

    if(randomValue < 5) return false;
    else return true;

}

bool ConnRobo::getConnStatus(){

    return connStatus;

}

void ConnRobo::setAutoMode(bool m){
    autoMode = m;
}

bool ConnRobo::getAutoMode(){
    return autoMode;
}

void ConnRobo::send_STOP(){
    cout << "STOP" << endl;
}
void ConnRobo::send_MOVE_FORWARD(){
    cout << "MIOVE_FORWARD" << endl;
}
void ConnRobo::send_MOVE_BACKWARD(){
    cout << "MOVE_BACKWARD" << endl;
}
void ConnRobo::send_MOVE_LEFT(){
    cout << "MOVE_LEFT" << endl;
}
void ConnRobo::send_MOVE_RIGHT(){
    cout << "MOVE_RIGHT" << endl;
}
void ConnRobo::send_ROTATE_LEFT(){
    cout << "ROTATE_LEFT" << endl;
}
void ConnRobo::send_ROTATE_RIGHT(){
    cout << "ROTATE_RIGHT" << endl;
}
