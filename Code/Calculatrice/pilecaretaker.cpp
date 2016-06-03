#include "pilecaretaker.h"


// -- Singleton -- //

PileCaretaker::Handler PileCaretaker::handler;

PileCaretaker& PileCaretaker::getInstance() {
    if(handler.instance == nullptr)
        // -- Par defaut on peut faire 5 UNDO -- //
        handler.instance = new PileCaretaker(5);
    return *handler.instance;
}

void PileCaretaker::libererInstance() {
    delete handler.instance;
    handler.instance=nullptr;
}


// -- save state of the originator -- //

void PileCaretaker::saveState(Pile* orig){

    // -- On ajoute nos etats en haut de la pile -- //
    PileMementoList.push(orig->saveStatePile());
    numIndex++;

    // -- On ne veut garder en memoire que NbEtatsSave de la pile: limiter l'impact en memoire des UNDO/REDO -- //
    while (PileMementoList.size() >= NbEtatsSave) {
       // -- Tant que j'ai plus de sauvegardes de pile que je n'en veux, je supprime les plus anciennes -- //
       Pile::PileMemento* lastPile = PileMementoList.takeFirst();
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

void PileCaretaker::restoreState(Pile* orig, unsigned int stateNb){

    // Si on veut retourner à un etat qui n'est plus stocké (on ne garde qu'un nombre fini, parametrable de PileMemento en memoire -- //
    // -- : Erreur, sinon si on veut faire un Undo alors qu'on a qu'une seule pile de sauvegarder: c'est la version actuelle donc on dit "stop les Undo" //
    if(stateNb >= NbEtatsSave || PileMementoList.size() < 1) {
        CALCULATRICE_EXCEPTION ("Plus possible de faire un UNDO");
    }
    else {
        orig->restoreStatePile(PileMementoList[stateNb]);
    }
}
