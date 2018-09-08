#-------------------------------------------------
#
# Project created by QtCreator 2018-06-01T10:20:44
#
#-------------------------------------------------

TEMPLATE = app 
TARGET = "Servo_Ultrasonic" 
DEPENDPATH += . include src
INCLUDEPATH += . include

QT       += core gui

#QMAKE_CXXFLAGS += -g
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Servo_Ultrasonic
TEMPLATE = app

CONFIG += console

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        src/mainwindow.cpp \
    src/servoslider.cpp \
    src/centralwidget.cpp \
    src/pie.cpp \
    src/draggableline.cpp \
    src/autoradar.cpp

HEADERS += \
        include/mainwindow.h \
    include/servoslider.h \
    include/centralwidget.h \
    include/global.h \
    include/pie.h \
    include/draggableline.h \
    include/autoradar.h
