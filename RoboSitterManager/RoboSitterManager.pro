QT += core gui

TARGET = "Robo Sitter Manager"
TEMPLATE = app

SOURCES += \
    src/main.cpp \
    GUI/src/mainwindow.cpp \
    GUI/src/configwidget.cpp \
    GUI/src/qopencvwidget.cpp \
    color-tracker/colortracker.cpp \
    src/connrobo.cpp

HEADERS += \
    GUI/src/mainwindow.h \
    GUI/src/configwidget.h \
    GUI/src/qopencvwidget.h \
    color-tracker/colortracker.h \
    src/connrobo.h

FORMS += \
    GUI/ui/mainwindow.ui \
    GUI/ui/configwidget.ui

INCLUDEPATH += /usr/local/include/
INCLUDEPATH += /usr/local/include/opencv2/
INCLUDEPATH += /usr/local/include/opencv/

LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_features2d -lopencv_calib3d
