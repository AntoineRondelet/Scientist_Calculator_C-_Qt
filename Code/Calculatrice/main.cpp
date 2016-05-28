#include "mainwindow.h"
#include <QApplication>
#include "pile.h"
#include "litterale.h"
#include "reel.h"
#include "entier.h"
#include "rationnel.h"
#include "analyser.h"
#include "controleur.h"

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

    Pile& stack = Pile::getInstance();
    /*stack.affiche();
    Entier e(5);
    Reel re(5.873);
    Rationnel rat(5, 4);

    //Litterale* lit1 = &e;
    Litterale* lit2 = &re;
    Litterale* lit3 = &rat;

    stack.push(&e);
    stack.push(lit2);
    stack.push(lit3);

    stack.affiche();*/

    Controleur controle(stack);
    //controle.executer();
    cout << "EXECUTE" << endl;
    controle.execute("13/23");

    /*
    Analyser an;

    QMap <string, int> mapTest;
    mapTest.insert("salut", 2);
    mapTest.insert("salut2", 1);

    cout << "voila -> " << mapTest.key(1) << endl;
    */





    return 0;
}
