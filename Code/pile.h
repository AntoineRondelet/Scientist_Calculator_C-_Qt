#ifndef PILE_H
#define PILE_H

#include <QProcess> // Pour faire QProcess::execute("clear"); <-> system("clear")
#include "item.h"
#include "litterale.h"
#include <QStack>



class Pile/*: public QStack<Litterale> */{ //FAIRE HERITER PILE DE QSTACK !!! /!\. -> ca va alleger le code -> on la fait heriter, comme ca on peut quand meme faire un singleton !

    //Debut singleton
    Pile(const Pile& p){}
    Pile& operator=(const Pile& p){}
    ~Pile();

    class Handler {
    public:
        Pile* instance;
        Handler():instance(0){}
        ~Handler() {delete instance;}
    };

    static Handler handler;
    //Fin singleton

    Item* tab_item; //Tableaux des items --> C'est la structure de donnée meme de la pile
    unsigned int nbAffiche; //La taille de la fenetre d'affichage (en nbre de lignes, 1 ligne -> 1 litterale)
    unsigned int nb; // Le nombre de litterales dans la pile
    unsigned int nbMax; // Le nombre maximal de litterales dans la pile
    string message;
    void agrandissementCapacite();

public:
    Pile():tab_item(0),nbAffiche(4),nb(0),nbMax(0),message(""){} //on initialise les attributs dans l'ordre dans lequel ils sont déclarés, sinon -> Warning du compilateur

    void push(Litterale& e); //--> a voir ce qu'on fait des attributs si on fait l'heritage
    void pop();
    bool estVide() const { return nb==0; }
    void affiche() const;
    Litterale& top() const;

    unsigned int getTaille() const { return nb; }
    string getMessage() const { return message; }
    unsigned int getNbItemsToAffiche()const { return nbAffiche; }
    void setNbItemsToAffiche(unsigned int n) { nb=n; }
    void setMessage(const string& m) { message=m; }

    //Singleton
    static Pile& getInstance();
    static void libererInstance();
};


#endif // PILE_H
