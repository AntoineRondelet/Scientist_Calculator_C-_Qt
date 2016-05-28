#include "mainwindow.h"
#include <QApplication>
#include "pile.h"
#include "litterale.h"
#include "reel.h"
#include "entier.h"
#include "rationnel.h"
#include "analyser.h"
#include "controleur.h"
#include "calculatriceexception.h"


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
        std::cout << e.what();
    }







    return 0;
}
