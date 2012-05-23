#ifndef CONNROBO_H
#define CONNROBO_H

#include <QThread>
#include <QTimer>

#include "GUI/src/mainwindow.h"

class ConnRobo : public QThread {
    public:

        ConnRobo(MainWindow *mw);

        void run();

        bool getConnStatus();
        bool send();

    private:

        MainWindow* mainWin;
        bool connStatus;
        bool sending;

    public slots:

        void ping();

};

#endif // CONNROBO_H
