#ifndef PILECARETAKER_H
#define PILECARETAKER_H

#include <QStack>
#include "pile.h"

#include "calculatriceexception.h"

// -- Cette classe c'est le manageur des piles de sauvegarde -- //


// --- DESIGN PATTERN SINGLETON --- //

class PileCaretaker {

private:
    // -- Attributs -- //
    unsigned int NbEtatsSave; // -- Nombre de sauvegardes qu'on veut, en même temps dans le système -- //
    static unsigned int numIndex; // -- Position courante dans la pile de sauvegarde (on est ou/sur quelle sauvegarde) -- //
    QStack<const Pile::PileMemento*> PileMementoList; // -- Nos sauvegardes sont constantes, en effet, on ne devrait pas pouvoir les changer (ce sont des sauvegardes...) -- //

    // -- Debut singleton -- //
    PileCaretaker(const PileCaretaker& p);
    PileCaretaker& operator=(const PileCaretaker& p);
    ~PileCaretaker(){}

    class Handler {
    public:
        PileCaretaker* instance;
        Handler():instance(0){}
        ~Handler() {delete instance;}
    };

    static Handler handler;
    // -- Fin singleton -- //


public:
    PileCaretaker(unsigned int NbEtats): NbEtatsSave(NbEtats){}

    // -- Save state de la pile "principale": Ajoute une pile de sauvegarde dans PileMementoList -- //
    void saveState(Pile* orig);

    // -- restore un ancien state de la pile "principale": Va récuperer une pile de sauvegarde pour la fetch/"deverser" dans la pile "principale pour repartir d'une sauvegarde -- //
    void restoreDownState(Pile* orig);


    // -- Singleton -- //
    static PileCaretaker& getInstance();
    static void libererInstance();
};

#endif // PILECARETAKER_H

