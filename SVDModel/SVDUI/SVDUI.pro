#-------------------------------------------------
#
# Project created by QtCreator 2017-06-29T17:46:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SVDUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ../SVDCore

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    modelcontroller.cpp \
    testdnn.cpp

HEADERS += \
        mainwindow.h \
    modelcontroller.h \
    testdnn.h

FORMS += \
        mainwindow.ui \
    testdnn.ui

win32:CONFIG (release, debug|release): LIBS += -L../Predictor/release -lPredictor
else:win32:CONFIG (debug, debug|release): LIBS += -L../Predictor/debug -lPredictor

win32:CONFIG (release, debug|release): LIBS += -L../SVDCore/release -lSVDCore
else:win32:CONFIG (debug, debug|release): LIBS += -L../SVDCore/debug -lSVDCore


LIBS += -LE:/dev/tensorflow/tensorflow/contrib/cmake/build/Release -ltensorflow
