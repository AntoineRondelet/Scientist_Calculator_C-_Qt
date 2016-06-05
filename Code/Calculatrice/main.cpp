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
#include <QStringList>

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
        Controleur& controle = Controleur::getInstance();
        controle.boucleExcecution();

    }
    catch (CalculatriceException &e) {
        cout << e.what();
    }
    catch (...) {
        cout << "On a catch" << endl;
    }

    //le but ici c'est de la mettre dans l'ordre qui est compris par la machine !
    //QString test = "'3*X1+3+TOTO/-2";
    QString test = "'3+3'";
    test.remove("'");
    cout << "before : " << test.toStdString() << endl;
    test.replace(QRegularExpression("\\+"), " + ");
    test.replace(QRegularExpression("-"), " - ");
    test.replace(QRegularExpression("\\*"), " * ");
    test.replace(QRegularExpression("\\/"), " / ");
    cout << "after spaces : " << test.toStdString() << endl;

    QStringList testSplit = test.split(" ");
    testSplit.swap(1,2);
    //verification des atomes -> A FAIRE
    //verification des - infixes (NEG)
    //for (unsigned int i = 0; i < testSplit.size(); ++i){
        /*
        if (testSplit[i] == "-") {
            if (i == 0 || (i > 0 && (testSplit[i-1] == "+" || testSplit[i-1] == "-" || testSplit[i-1] == "*" || testSplit[i-1] == "/")))
                testSplit.swap(i, i+1); // on echange le - avec la litterale sur laquelle il s'applique
                cout << "on est dans le if " << endl;
                QString stri = testSplit[i];
                QString stri1 = testSplit[i+2];
                cout << " index i : " << stri.toStdString() << endl;
                cout << " index i+1 : " << stri1.toStdString() << endl;

                //testSplit[i+1] = "NEG";
            }*/
        /*
        //permutation des operateurs prioritaires * et -
        if (testSplit[i] == "*" || testSplit[i] == "/") {
            unsigned int j = 1;
            while((i+j < testSplit.size() && (testSplit[i+j] != "+" || testSplit[i+j] != "-" || testSplit[i+j] != "*" || testSplit[i+j] != "/"))){
                testSplit.swap(i+j, i+j+1);
                j++;
            }
        }*/
    //}
    cout << "Apres debut de tri : " << testSplit.join(" ").toStdString() << endl;







    return 0;
}
