#include "mainwindow.h"
#include <QApplication>

#include "pile.h"
#include "litterale.h"
#include "reel.h"
#include "entier.h"
#include "rationnel.h"
#include "atome.h"
#include "analyser.h"
#include "controleur.h"
#include "calculatriceexception.h"
#include <QTextStream>
#include "pilecaretaker.h"
#include "identificateurmanager.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QStringList>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

/*
    IdentificateurManager& id_man = IdentificateurManager::getInstance();
    QString res = id_man.strOperateurs();

    cout << " ----> Res : " << res.toStdString() << endl;
*/
    //Pile& stack = Pile::getInstance();
    //Controleur& controle = Controleur::getInstance();
    //controle.boucleExcecution();

    return a.exec();
}
