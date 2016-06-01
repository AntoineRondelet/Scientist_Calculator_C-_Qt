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
        Pile& stack = Pile::getInstance();
        Controleur controle(stack);
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
    while(!liste_param.empty()) {
        QRegularExpression regex("'(.)*'");
        QString act = liste_param.takeFirst();


        //On ne passe dans ce circuit de if etc QUE si l'utilisateur a mit des espaces dans
        if (act.left(1) == "'") {
            if (act.right(1) != "'" || act.size() <= 1){
                QString isFound = "";
                while (!liste_param.empty()){
                    isFound = liste_param.takeFirst();
                    act += isFound;
                    if (act.right(1) == "'") //on sort l'expression est "recollée"
                        break;
                }
            }
        }
        // En sortant de tous ces if/else -> On a "recollé" les morceaux de la litterale expession qui avait etée saisie avec des espaces et donc splitée -> On s'assure par la meme occasion que tout "'" ouvert se ferme !

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
