#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T11:05:59
#
#-------------------------------------------------

QT       += core gui opengl widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PInfo
TEMPLATE = app

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}


SOURCES += main.cpp\
        mainwindow.cpp \
    brique.cpp \
    myglwidget.cpp \
    palet.cpp \
    boule.cpp \
    mur.cpp \
    jeu.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    brique.h \
    myglwidget.h \
    palet.h \
    boule.h \
    mur.h \
    jeu.h \
    camera.h

FORMS    += mainwindow.ui

CONFIG+=c++11

RESOURCES += \
    images.qrc

INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include

LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413 \
    -lopencv_features2d2413 \
    -lopencv_calib3d2413
