#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T20:21:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    reel.cpp \
    litteralenum.cpp \
    calculatriceexception.cpp \
    rationnel.cpp \
    litteralenombre.cpp \
    entier.cpp \
    complexe.cpp \
    litterale.cpp \
    item.cpp \
    pile.cpp \
    litteralemanager.cpp \
    controleur.cpp \
    operateur.cpp

HEADERS  += mainwindow.h \
    reel.h \
    litteralenum.h \
    calculatriceexception.h \
    litteralenombre.h \
    rationnel.h \
    entier.h \
    complexe.h \
    litterale.h \
    item.h \
    pile.h \
    litteralemanager.h \
    controleur.h \
    operateur.h

FORMS    += mainwindow.ui

CONFIG += console
