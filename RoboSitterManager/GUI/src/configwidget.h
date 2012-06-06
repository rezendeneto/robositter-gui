#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
    class ConfigWidget;
}

class ConfigWidget : public QWidget {
    Q_OBJECT

    public:
        explicit ConfigWidget(QWidget *parent = 0);
        ~ConfigWidget();

    private:
        Ui::ConfigWidget *ui;

    private slots:

};

#endif // CONFIGWIDGET_H
