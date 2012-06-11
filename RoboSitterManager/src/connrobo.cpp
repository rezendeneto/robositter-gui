#include "connrobo.h"
#define BUFF_SIZE 3

ConnRobo::ConnRobo(Kid* k) {

    connStatus = false;
    sending = false;
    autoMode = false;
    w = false;
    control = new Control(k);

    start();
}

void ConnRobo::run() {
    while(!w) {

            char *a = new char[3];
            a[0] = '7';
            a[1] = '0';
            a[2] = '0';
            w = receive(a);

    }

    while(true) {

        if(autoMode) {
            switch(control->action()) {
                case(Control::STOP):
                    send_STOP();
                    break;
                case(Control::MOVE_FORWARD):
                    send_MOVE_FORWARD();
                    break;
                case(Control::MOVE_BACKWARD):
                    send_MOVE_BACKWARD();
                    break;
                case(Control::ROTATE_LEFT):
                    send_ROTATE_LEFT();
                    break;
                case(Control::ROTATE_RIGHT):
                    send_ROTATE_RIGHT();
                    break;
                case(Control::STAY):
                    break;
                case(Control::PING):
                default:
                    ping();
                    break;
            }

        }

        msleep(100);
    }

}

bool ConnRobo::ping() {

    char* c = new char[3];
    c[0] = '7';
    c[1] = '0';
    c[2] = '0';

    connStatus = send(c);
    return connStatus;
}

bool ConnRobo::receive(char *msg) {
    int fd1;
    char* buff = new char[16];
    int wr;

    msleep(100);

    fd1 = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

    fcntl(fd1, F_SETFL, FNDELAY);


    if (fd1 == -1) {
        cout << "s";
        return false;
    }
    else {
        int bytes = 0;
        while((bytes = read(fd1, buff, 16)) > 0) {
            cout << "bytes: " << bytes << endl;
            cout << "buff: " << buff << endl;
            if(buff[0] == msg[0] && buff[1] == msg[1] && buff[2] == msg[2]){
                cout << "msg: " << msg << endl;
                close(fd1);
                return true;
            }
        }
    }

    close(fd1);
    return false;
}

bool ConnRobo::send(char *msg){
    if(w){
        int fd1;
        char* buff = new char[3*BUFF_SIZE];
        int wr;

        fd1 = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

        fcntl(fd1, F_SETFL, FNDELAY);

        if (fd1 == -1)
            return false;
        else {
            wr = write(fd1, msg, BUFF_SIZE);
            int bytes = 0;
            cout << "Enviei: " <<(unsigned int)msg[0] << (unsigned int)msg[1]<< (unsigned int)msg[2]<< endl;
            msleep(10);
            while((bytes = read(fd1, buff,3)) > 0) {
                cout << msg << endl;
                cout << buff << endl;
                cout << "Recebi: " << (unsigned int)buff[0] << (unsigned int)buff[1] << (unsigned int)buff[2] << endl;
            }
        }

        close(fd1);
        return true;
    }else
        return false;
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
    char* c = new char[3];
    c[0] = 4;
    c[1] = 0;
    c[2] = 0;
    send(c);
}

void ConnRobo::send_MOVE_FORWARD(){
    cout << "MOVE_FORWARD" << endl;
    char* c = new char[3];
    c[0] = 5;
    c[1] = 0;
    c[2] = 70;
    send(c);
}

void ConnRobo::send_MOVE_BACKWARD(){
    cout << "MOVE_BACKWARD" << endl;
    char* c = new char[3];
    c[0] = 5;
    c[1] = 127;
    c[2] = 70;
    send(c);
}

void ConnRobo::send_ROTATE_LEFT(){
    cout << "ROTATE_LEFT" << endl;
    char* c = new char[3];
    c[0] = 6;
    c[1] = 0;
    c[2] = 70;
    send(c);
}
void ConnRobo::send_ROTATE_RIGHT(){
    cout << "ROTATE_RIGHT" << endl;
    char* c = new char[3];
    c[0] = 6;
    c[1] = 1;
    c[2] = 70;
    send(c);
}

void ConnRobo::send_MODE_AUTO() {
    cout << "MODE_AUTO" << endl;
    char* c = new char[3];
    c[0] = 2;
    c[1] = 0;
    c[2] = 0;
    send(c);
}

void ConnRobo::send_MODE_MANUAL() {
    cout << "MODE_MANUAL" << endl;
    char* c = new char[3];
    c[0] = 3;
    c[1] = 0;
    c[2] = 0;
    send(c);
}
