#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "pile.h"
#include "litteralemanager.h"

class Controleur {
    LitteraleManager& litManag;
    Pile& pileAff;
public:
    Controleur(LitteraleManager& m, Pile& v):litManag(m), pileAff(v){}

    void commande(const string& c);
    void executer();

    friend Entier* isEntier(const string& c, Controleur& cont);
    friend Reel* isReel(const string& c, Controleur& cont);
    friend Rationnel* isRationnel(const string& c, Controleur& cont);
};

//bool isOperator(const string& s); //Il faudrait plutot passer notre mmap a la fonction pour implementer "la table des operateurs"


//void splitEntry(const string& c); //Fonction qui permet de recuperer chaque "mot" dans la "phrase" saisie par le user
// Donc elle nous permet de recuperer





#endif // CONTROLEUR_H
