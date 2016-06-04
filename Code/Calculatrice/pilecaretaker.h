#ifndef PILECARETAKER_H
#define PILECARETAKER_H

#include <QStack>
#include "pile.h"

#include "calculatriceexception.h"

// -- Cette classe c'est le manageur des piles de sauvegarde -- //


// --- DESIGN PATTERN SINGLETON --- //

class PileCaretaker {

private:
    //friend class Undo;

    // -- Attributs -- //
    unsigned int NbEtatsSave; // -- Nombre de sauvegardes qu'on veut, en même temps dans le système -- //
    int numIndex; // -- Position courante dans la pile de sauvegarde (on est ou/sur quelle sauvegarde) -- //
    QStack<const Pile::PileMemento*> PileMementoList; // -- Nos sauvegardes sont constantes, en effet, on ne devrait pas pouvoir les changer (ce sont des sauvegardes...) -- //

    // -- Debut singleton -- //
    PileCaretaker(const PileCaretaker& p);
    PileCaretaker& operator=(const PileCaretaker& p);
    ~PileCaretaker(){}


    static PileCaretaker* ptrPileCaretaker;
    // -- Fin singleton -- //


public:
    PileCaretaker(unsigned int NbEtats, unsigned int nbIndex=-1): NbEtatsSave(NbEtats), numIndex(nbIndex), PileMementoList(QStack<const Pile::PileMemento*>()){}
    int getNumIndex() const {return numIndex;}
    int getNbEtatsSave() const {return NbEtatsSave;}

    // -- On peut imaginer une amelioration de l'application ou l'utilisateur peut gérer lui-meme le nombre de UNDO qu'il veut pouvoir faire -- //
    // -- NB: Si NbEtatsSave = 5 (N), on pourra revenir à 4 (N-1) etats précédents, car l'état courant sera en top de pile -- //
    void setNbEtatsSave(unsigned int nb) {NbEtatsSave = nb;}


    // -- Save state de la pile "principale": Ajoute une pile de sauvegarde dans PileMementoList -- //
    void saveState(Pile* orig);
    // -- restore un ancien state de la pile "principale": Va récuperer une pile de sauvegarde pour la fetch/"deverser" dans la pile "principale pour repartir d'une sauvegarde -- //
    void restoreDownState(Pile* orig);


    // -- Singleton -- //
    static PileCaretaker& getInstance();
    static void libererInstance();
};

#endif // PILECARETAKER_H

