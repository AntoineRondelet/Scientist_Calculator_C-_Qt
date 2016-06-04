
#include "pilecaretaker.h"


// -- Singleton -- //

PileCaretaker* PileCaretaker::ptrPileCaretaker;

PileCaretaker& PileCaretaker::getInstance() {
    if(ptrPileCaretaker == nullptr)
        // -- Par defaut on peut faire 5 UNDO -- //
        ptrPileCaretaker = new PileCaretaker(5);
    return *ptrPileCaretaker;
}

void PileCaretaker::libererInstance() {
    delete ptrPileCaretaker;
    ptrPileCaretaker=nullptr;
}


// -- save state of the originator -- //
/*
void PileCaretaker::saveState(Pile* orig){

    // -- On ajoute nos etats en haut de la pile -- //
    PileMementoList.push(orig->saveStatePile());
    numIndex++;

    // -- On ne veut garder en memoire que NbEtatsSave de la pile: limiter l'impact en memoire des UNDO/REDO -- //
    while (PileMementoList.size() >= NbEtatsSave) {
       // -- Tant que j'ai plus de sauvegardes de pile que je n'en veux, je supprime les plus anciennes -- //
       const Pile::PileMemento* lastPile = PileMementoList.takeFirst();
       Pile* pileASupprimer = lastPile->getState();
       while(!pileASupprimer->empty()) {
           // -- On supprime toutes les litterales de la pile unes à unes (on s'assure de relacher toute la memoire) -- //
           Litterale* litASuppr = pileASupprimer->pop();
           delete litASuppr;
       }
       delete pileASupprimer;
    }
}


// -- Restore state of the originator -- //

void PileCaretaker::restoreDownState(Pile* orig){

    // Si on veut retourner à un etat qui n'est plus stocké (on ne garde qu'un nombre fini, parametrable de PileMemento en memoire -- //
    // -- : Erreur, sinon si on veut faire un Undo alors qu'on a qu'une seule pile de sauvegarder: c'est la version actuelle donc on dit "stop les Undo" //
    if(numIndex < 1) {
        CALCULATRICE_EXCEPTION ("Plus possible de faire un UNDO");
    }
    else {
        numIndex= numIndex-1;
        orig->restoreStatePile(PileMementoList[numIndex]);
    }
}

*/
