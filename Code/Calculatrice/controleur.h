#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "pile.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <QString>
#include "analyser.h"

class Controleur {
    Pile& pileAff;
    Analyser* analyser;
public:
    Controleur(Pile& v):pileAff(v), analyser(new Analyser()){
        analyser->init();
    }

    //void commande(const string& c);
    //void executer();

    void execute(const string& src);

    friend Entier* isEntier(const string& c, Controleur& cont);
    //friend Reel* isReel(const string& c, Controleur& cont);
    //friend Rationnel* isRationnel(const string& c, Controleur& cont);
};

//void splitEntry(const string& c); //Fonction qui permet de recuperer chaque "mot" dans la "phrase" saisie par le user
// Donc elle nous permet de recuperer





#endif // CONTROLEUR_H
