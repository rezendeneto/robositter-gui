#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QString>

#include <Phonon/VideoPlayer>
#include <Phonon/VideoWidget>
#include <Phonon/MediaSource>

#include "configwidget.h"


namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0, MainWindow *mw = 0);
    ~MainWindow();

    void loadVideoFile(char *path);
    void playVideo();
    
private slots:


    void on_actionChangeMode_triggered();

    void on_actionSair_triggered();

    void on_actionConfigura_o_triggered();

private:
    Ui::MainWindow *ui;

    Phonon::VideoPlayer *vp;

    bool autoMode;
    bool connCam;
    bool connRobot;
    //bool m;

    QString status;
    QString alert;

    void setStatusInfo();
    void addAlertInfo(QString addedAlert);

    int cc;


};

#endif // MAINWINDOW_H
