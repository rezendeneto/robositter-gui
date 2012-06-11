#ifndef CONNROBO_H
#define CONNROBO_H

#include <QThread>
#include <QTimer>

#include "control.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>



using namespace std;

class ConnRobo : public QThread {
    public:

        ConnRobo(Kid* k);

        void run();

        bool getConnStatus();
        bool send(char *msg);
        bool receive(char *msg);
        bool ping();

        void setAutoMode(bool m);
        bool getAutoMode();

        void send_STOP();
        void send_MOVE_FORWARD();
        void send_MOVE_BACKWARD();
        void send_ROTATE_LEFT();
        void send_ROTATE_RIGHT();
        void send_MODE_AUTO();
        void send_MODE_MANUAL();

    private:

        bool connStatus;
        bool sending;
        bool autoMode;
        Control* control;
        bool w;





};

#endif // CONNROBO_H
