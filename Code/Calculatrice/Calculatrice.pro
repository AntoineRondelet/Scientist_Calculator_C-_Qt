#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T22:32:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculatrice
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    entier.cpp \
    reel.cpp \
    rationnel.cpp \
    litterale.cpp \
    pile.cpp \
    litteralenombre.cpp \
    litteralenum.cpp \
    calculatriceexception.cpp \
    controleur.cpp \
    analyser.cpp \
    entieranalyser.cpp \
    operator.cpp \
    binaryoperator.cpp \
    add.cpp \
    mult.cpp

HEADERS  += mainwindow.h \
    entier.h \
    reel.h \
    rationnel.h \
    litterale.h \
    pile.h \
    litteralenombre.h \
    litteralenum.h \
    calculatriceexception.h \
    controleur.h \
    analyser.h \
    entieranalyser.h \
    operator.h \
    binaryoperator.h \
    add.h \
    mult.h

FORMS    += mainwindow.ui


CONFIG += console


