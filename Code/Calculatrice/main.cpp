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

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include<QStringList>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */


   try {
        //Pile& stack = Pile::getInstance();
        Controleur controle/*(stack)*/;
        controle.boucleExcecution();

    }
    catch (CalculatriceException &e) {
        cout << e.what();
    }
    catch (...) {
        cout << "On a catch" << endl;
    }


/*
//regex("\\[(.)*\\]"); --> regex pour les programmes
    string c;
    cout<<"?-";
    getline(cin,c);
    QString str_in = QString::fromStdString(c);
    QRegularExpression regex("'(.)*'");
    QRegularExpressionMatch str_match = regex.match(str_in);
    if(str_match.hasMatch()) {
        cout << "------- MATCHED --------" << endl;
        QString act2 = str_match.captured(0);
        cout << "Match " << ": " << act2.toStdString() << endl;
    }
    else
        cout << "Case " << ": " << str_in.toStdString() << endl;
*/

/*

    string c;
    cout<<"?-";
    getline(cin,c);
    QString str_in = QString::fromStdString(c);
    //cout << str_in.toStdString() << endl;
    QStringList liste_param = str_in.split(QRegularExpression("[[:space:]]+"));
    int i = 0;
    int counterCrochet = 0;
    while(!liste_param.empty()) {
        QRegularExpression regex("\\[(.)*\\]");
        QString act = liste_param.takeFirst();


        //------ CIRCUIT POUR RECONSTITUER LES PROGRAMMES ------//
        if (act == "[") {
                counterCrochet++;
                QString isFound = "";
                while (!liste_param.empty() && counterCrochet !=0){ //Si counterCrochet != 0 -> on a pas fini de lire le programme
                    isFound = liste_param.takeFirst();
                    if (isFound == "[") counterCrochet++;
                    if (isFound == "]") counterCrochet--;
                    act += " " + isFound;
                }
        }
         //------ SORTIE DE CIRCUIT POUR RECONSTITUER LES PROGRAMMES ------//

        QRegularExpressionMatch str_match = regex.match(act);
        if(str_match.hasMatch()) {
            cout << "------- MATCHED --------" << endl;
            QString act2 = str_match.captured(0);
            cout << "Match " << i << ": " << act2.toStdString() << endl;
        }
        else
            cout << "Case " << i << ": " << act.toStdString() << endl;
        i++;
    }

*/





    return 0;
}
