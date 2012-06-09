#include "connrobo.h"


ConnRobo::ConnRobo(Kid* k) {

    connStatus = false;
    sending = false;
    autoMode = false;

    control = new Control(k);

    start();



}

void ConnRobo::run() {

    while(true){

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
                    break;
                case(Control::PING):
                default:
                    ping();
                    break;
            }

        }
        msleep(500);
    }

}

bool ConnRobo::ping() {

    char* c = new char[3];
    c[0] = (char)0x07;
    c[1] = (char)0;
    c[2] = (char)0;


    connStatus = send(c);
    return connStatus;

}



bool ConnRobo::send(char *msg){

    int fd1;
    char *buff = new char[3];
    int wr;
    bool s = false;

    fcntl(fd1, F_SETFL, O_NONBLOCK);
    fd1 = open("/dev/ttyUSB0", O_RDWR | O_NONBLOCK);
    //string data="";

    if (fd1 == -1)
        return s;
    else {
            fcntl(fd1, F_SETFL, 0);

            wr = write(fd1, msg, 3);

            int bytes=0;
            bytes = read(fd1, buff, 1);

            //do {

            for(int i = 0; i < 3;i++){
                bytes = read(fd1,buff,1);
                if(bytes == 3){
                    if(buff[0] == msg[0] && buff[1] == msg[1] && buff[2] == msg[2]) s = true;
                    break;
                }
            }
                //if(buff[0]=='\r') {
                  //  read(fd1,buff,1);
                    //break;
                //}
                //else {
                    //data.append(1,buff[0]);
                //}
            //}while(bytes > 0);

        }

        close(fd1);
        return s;
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
    c[0] = (char)0x04;
    c[1] = (char)0x00;
    c[2] = (char)0x00;
    send(c);
}
void ConnRobo::send_MOVE_FORWARD(){
    cout << "MOVE_FORWARD" << endl;
    char* c = new char[3];
    c[0] = (char)0x05;
    c[1] = (char)0x00;
    c[2] = (char)0x00;
    send(c);
}
void ConnRobo::send_MOVE_BACKWARD(){
    cout << "MOVE_BACKWARD" << endl;
    char* c = new char[3];
    c[0] = (char)0x05;
    c[1] = (char)0x80;
    c[2] = (char)0x1E;
    send(c);
}
void ConnRobo::send_MOVE_LEFT(){
    cout << "MOVE_LEFT" << endl;
}
void ConnRobo::send_MOVE_RIGHT(){
    cout << "MOVE_RIGHT" << endl;
}
void ConnRobo::send_ROTATE_LEFT(){
    cout << "ROTATE_LEFT" << endl;
    char* c = new char[3];
    c[0] = (char)0x06;
    c[1] = (char)0x00;
    c[2] = (char)0x1E;
    send(c);
}
void ConnRobo::send_ROTATE_RIGHT(){
    cout << "ROTATE_RIGHT" << endl;
    char* c = new char[3];
    c[0] = (char)0x06;
    c[1] = (char)0x01;
    c[2] = (char)0x1E;
    send(c);
}
