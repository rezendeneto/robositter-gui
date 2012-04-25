QT += core gui
QT += phonon

TARGET = "Robo Sitter Manager"
TEMPLATE = app

SOURCES += \
    src/main.cpp \
    GUI/src/mainwindow.cpp \
    GUI/src/configwidget.cpp

HEADERS += \
    GUI/src/mainwindow.h \
    GUI/src/configwidget.h

FORMS += \
    GUI/ui/mainwindow.ui \
    GUI/ui/configwidget.ui
