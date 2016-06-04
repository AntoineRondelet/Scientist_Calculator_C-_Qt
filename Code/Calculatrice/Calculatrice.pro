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
    mult.cpp \
    unaryoperator.cpp \
    neg.cpp \
    div.cpp \
    num.cpp \
    sous.cpp \
    den.cpp \
    atome.cpp \
    sto.cpp \
    binaryoperatortemplate.cpp \
    drop.cpp \
    expression.cpp \
    programme.cpp \
    complexe.cpp \
    operateurcomplexe.cpp \
    function.cpp \
    pilememento.cpp \
    pilecaretaker.cpp \
    undo.cpp \
    redo.cpp \
    operateurspecial.cpp

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
    mult.h \
    unaryoperator.h \
    neg.h \
    div.h \
    num.h \
    sous.h \
    den.h \
    atome.h \
    sto.h \
    binaryoperatortemplate.h \
    drop.h \
    expression.h \
    programme.h \
    complexe.h \
    operateurcomplexe.h \
    function.h \
    pilememento.h \
    pilecaretaker.h \
    undo.h \
    redo.h \
    operateurspecial.h

FORMS    += mainwindow.ui


CONFIG += console


