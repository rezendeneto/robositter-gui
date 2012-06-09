#ifndef CONTROL_H
#define CONTROL_H

#include "kid.h"

class Control
{
public:
    Control(Kid* k);
    int action();

    static const int STAY = -1;
    static const int STOP = 0;
    static const int MOVE_FORWARD = 1;
    static const int MOVE_BACKWARD = 2;
    static const int MOVE_LEFT = 3;
    static const int MOVE_RIGHT = 4;
    static const int ROTATE_LEFT = 5;
    static const int ROTATE_RIGHT = 6;
    static const int PING = 7;


private:

    Kid* kid;

    bool moving_forward;
    bool moving_backward;
    bool moving_left;
    bool moving_right;
    bool rotating_left;
    bool rotating_right;
    bool lost;

    double MIN_HEIGHT;
    double MAX_HEIGHT;
    double MIN_WIDTH;
    double MAX_WIDTH;
    double MIN_X_VARIATION;
    double MAX_X_VARIATION;

    void stop();
    void move(int m);

    bool diminuiu();
    bool aumentou();
    bool direita();
    bool esquerda();

};

#endif // CONTROL_H
