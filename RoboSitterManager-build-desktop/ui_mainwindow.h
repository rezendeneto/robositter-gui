/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue May 22 22:23:57 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSair;
    QAction *actionChangeMode;
    QAction *actionConfigura_o;
    QWidget *centralwidget;
    QWidget *videoWidget;
    QTextEdit *textAlert;
    QPushButton *buttonMODE;
    QTextEdit *textStatus;
    QPushButton *buttonLEFT;
    QPushButton *buttonDOWN;
    QPushButton *buttonRIGHT;
    QPushButton *buttonUP;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(680, 521);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionChangeMode = new QAction(MainWindow);
        actionChangeMode->setObjectName(QString::fromUtf8("actionChangeMode"));
        actionConfigura_o = new QAction(MainWindow);
        actionConfigura_o->setObjectName(QString::fromUtf8("actionConfigura_o"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        videoWidget = new QWidget(centralwidget);
        videoWidget->setObjectName(QString::fromUtf8("videoWidget"));
        videoWidget->setGeometry(QRect(10, 10, 480, 360));
        sizePolicy.setHeightForWidth(videoWidget->sizePolicy().hasHeightForWidth());
        videoWidget->setSizePolicy(sizePolicy);
        videoWidget->setCursor(QCursor(Qt::CrossCursor));
        textAlert = new QTextEdit(centralwidget);
        textAlert->setObjectName(QString::fromUtf8("textAlert"));
        textAlert->setEnabled(true);
        textAlert->setGeometry(QRect(10, 380, 380, 90));
        sizePolicy.setHeightForWidth(textAlert->sizePolicy().hasHeightForWidth());
        textAlert->setSizePolicy(sizePolicy);
        textAlert->setTabChangesFocus(true);
        textAlert->setReadOnly(true);
        textAlert->setOverwriteMode(false);
        buttonMODE = new QPushButton(centralwidget);
        buttonMODE->setObjectName(QString::fromUtf8("buttonMODE"));
        buttonMODE->setGeometry(QRect(400, 380, 90, 90));
        sizePolicy.setHeightForWidth(buttonMODE->sizePolicy().hasHeightForWidth());
        buttonMODE->setSizePolicy(sizePolicy);
        textStatus = new QTextEdit(centralwidget);
        textStatus->setObjectName(QString::fromUtf8("textStatus"));
        textStatus->setGeometry(QRect(500, 10, 170, 340));
        sizePolicy.setHeightForWidth(textStatus->sizePolicy().hasHeightForWidth());
        textStatus->setSizePolicy(sizePolicy);
        textStatus->setReadOnly(true);
        buttonLEFT = new QPushButton(centralwidget);
        buttonLEFT->setObjectName(QString::fromUtf8("buttonLEFT"));
        buttonLEFT->setGeometry(QRect(500, 420, 50, 50));
        sizePolicy.setHeightForWidth(buttonLEFT->sizePolicy().hasHeightForWidth());
        buttonLEFT->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        buttonLEFT->setFont(font);
        buttonDOWN = new QPushButton(centralwidget);
        buttonDOWN->setObjectName(QString::fromUtf8("buttonDOWN"));
        buttonDOWN->setGeometry(QRect(560, 420, 50, 50));
        sizePolicy.setHeightForWidth(buttonDOWN->sizePolicy().hasHeightForWidth());
        buttonDOWN->setSizePolicy(sizePolicy);
        buttonDOWN->setFont(font);
        buttonRIGHT = new QPushButton(centralwidget);
        buttonRIGHT->setObjectName(QString::fromUtf8("buttonRIGHT"));
        buttonRIGHT->setGeometry(QRect(620, 420, 50, 50));
        sizePolicy.setHeightForWidth(buttonRIGHT->sizePolicy().hasHeightForWidth());
        buttonRIGHT->setSizePolicy(sizePolicy);
        buttonRIGHT->setFont(font);
        buttonUP = new QPushButton(centralwidget);
        buttonUP->setObjectName(QString::fromUtf8("buttonUP"));
        buttonUP->setGeometry(QRect(560, 360, 50, 50));
        sizePolicy.setHeightForWidth(buttonUP->sizePolicy().hasHeightForWidth());
        buttonUP->setSizePolicy(sizePolicy);
        buttonUP->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 680, 25));
        sizePolicy.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy);
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sizePolicy.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionConfigura_o);
        menuMenu->addSeparator();
        menuMenu->addAction(actionSair);

        retranslateUi(MainWindow);
        QObject::connect(buttonMODE, SIGNAL(clicked()), actionChangeMode, SLOT(trigger()));
        QObject::connect(actionSair, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RoboSitter - v0.1", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", 0, QApplication::UnicodeUTF8));
        actionSair->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionChangeMode->setText(QApplication::translate("MainWindow", "ChangeMode", 0, QApplication::UnicodeUTF8));
        actionConfigura_o->setText(QApplication::translate("MainWindow", "Configura\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        actionConfigura_o->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        videoWidget->setToolTip(QApplication::translate("MainWindow", "V\303\255deo da c\303\242mera em tempo real.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        textAlert->setToolTip(QApplication::translate("MainWindow", "Alertas do sistema.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textAlert->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buttonMODE->setToolTip(QApplication::translate("MainWindow", "Alternar entre o modo manual e autom\303\241tico", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonMODE->setText(QApplication::translate("MainWindow", "Manual/Auto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textStatus->setToolTip(QApplication::translate("MainWindow", "Informa\303\247\303\265es do sistema.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textStatus->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buttonLEFT->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400;\">Girar o rob\303\264 para esquerda.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonLEFT->setText(QApplication::translate("MainWindow", "\342\206\220", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buttonDOWN->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400;\">Movimentar o rob\303\264 para tr\303\241s.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonDOWN->setText(QApplication::translate("MainWindow", "\342\206\223", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buttonRIGHT->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400;\">Girar o rob\303\264 para a direita.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonRIGHT->setText(QApplication::translate("MainWindow", "\342\206\222", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buttonUP->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400;\">Movimentar o rob\303\264 para frente.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonUP->setText(QApplication::translate("MainWindow", "\342\206\221", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
