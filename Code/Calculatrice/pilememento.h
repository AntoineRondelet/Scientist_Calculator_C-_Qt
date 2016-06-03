/*
#ifndef PILEMEMENTO_H
#define PILEMEMENTO_H

//Pour eviter les références croisées
#include"pile.h"

//Sauvegarde les états de la pile
class PileMemento {
private:
  friend class Pile; //Suggested
  Pile* statePile;
public:
    // -- Ici, on créer une copie de notre pile que l'on "stocke" dans un objet memento lui meme stocké dans le PileCareTaker -- //
    PileMemento(const Pile* pileASave): statePile(pileASave->clone()){}
    Pile* getState() const {return statePile;}
    //void setState(Pile* etat_a_save) {statePile = etat_a_save;}
};

#endif // PILEMEMENTO_H
*/
