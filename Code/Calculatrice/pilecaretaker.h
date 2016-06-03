#ifndef PILECARETAKER_H
#define PILECARETAKER_H

#include <QStack>
#include "pile.h"

#include "calculatriceexception.h"


// --- DESIGN PATTERN SINGLETON --- //

class PileCaretaker {
public: // A CHANGER JUSTE POUR UN TEST !!
    // -- Attributs -- //
    unsigned int NbEtatsSave; // Taille de la pile des sauvegardes de la pile
    unsigned int numIndex; // Si on a une pile des sauvegardes de la pile, faire un UNDO: descendre, REDO: monter. Cet index nous permet de gerer cette descente/montée dans la pile --> indique où on est dans l'historique des piles
    QStack<Pile::PileMemento*> PileMementoList;

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
    PileCaretaker(unsigned int NbEtats, unsigned int nIdx = 0): NbEtatsSave(NbEtats), numIndex(nIdx){}

    // -- Save state of the originator -- //
    void saveState(Pile* orig);

    //restore state of the originator
    void restoreState(Pile* orig, unsigned int stateNb);


    // -- Singleton -- //
    static PileCaretaker& getInstance();
    static void libererInstance();
};

#endif // PILECARETAKER_H

