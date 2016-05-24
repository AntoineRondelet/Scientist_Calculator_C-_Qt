#include "mainwindow.h"
#include <QApplication>
#include "reel.h"
#include "rationnel.h"
#include "entier.h"
#include "complexe.h"
#include "item.h"
#include "litteralenombre.h"
#include "litteralemanager.h"
#include "litterale.h"
#include "pile.h"
#include "controleur.h"
#include <iostream>
#include <stdlib.h>
#include <QTextStream>
#include <QString>

using namespace std;

int main(int argc, char *argv[])
{
    /* On met ca en commentaire pour tester le programme en ligne de commande --> TEMPORAIRE

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    */

    Reel r1;
    Reel r2(3.17);
    Entier e1(7);
    Entier e2(2);
    Rationnel ra(3,2);
    Rationnel ra2(3,2);
    Reel r5(7.62);
    Reel r6(78.29);

    Item it;

    try {
      Litterale& ref1 = ra2/ra;
      Litterale& ref2 = r5;
      Litterale& ref3 = e1/e2;
      it.setLitterale(ref3);
      Litterale& ref4 = it.getLitterale();


      cout << ref1.toString() << endl;
      cout << ref2.toString() << endl;
      cout << ref3.toString() << endl;
      cout << ref4.toString() << endl;

      //bool test = isEntier("345");
      //cout << "Res: " << test << endl;

      LitteraleManager manager;
      Pile stack;
      Controleur controleur(manager,stack);

      Controleur control(manager, stack);
      control.executer();

      /*cout << "ENTIER MATCHING" << endl;
      isEntier("-5");
      cout << "ENTIER MATCHING" << endl;
      isEntier("5");

      cout << "--------------------" << endl;

      cout << "RATIONNEL MATCHING" << endl;
      isRationnel("123/56");
      cout << "RATIONNEL MATCHING" << endl;
      isRationnel("1/6");

      cout << "--------------------" << endl;

      //cout << "SPLIT ENTRY" << endl;
      //splitEntry("324 -765 + ");

      cout << "REEL MATCHING" << endl;
      isReel("-.5");
      cout << "REEL MATCHING" << endl;
      isReel("-1.5");
      cout << "REEL MATCHING" << endl;
      isReel("1.2");*/

      /*LitteraleManager manager;
      int valeur;
      cout << "Valeur : ? " << endl;
      cin >> valeur;
      Litterale& ent = manager.addLitteraleEntiere(valeur);

      cout << "Entier ajouté au manager :" << ent.toString() << endl;
      manager.removeLitterale(ent);*/

      /*Pile maStack;
      maStack.affiche();
      maStack.push(ref1);
      maStack.affiche();
      maStack.push(ref3);
      maStack.affiche();
      maStack.push(ref2);
      maStack.affiche();
      maStack.pop();
      maStack.affiche();*/
    }
    catch (CalculatriceException& e) {
        cout << e.getInfo();
    }
    catch (...) {
        cout << "erreur inconnue";
    }





    // ATTENTION : On met ca en commentaire JUSTE pour tester le programme en ligne de commande !!
    //return a.exec();
    return 0;
}
