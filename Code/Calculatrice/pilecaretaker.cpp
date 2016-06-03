#include "pilecaretaker.h"


// -- Singleton -- //

PileCaretaker::Handler PileCaretaker::handler;

PileCaretaker& PileCaretaker::getInstance() {
    if(handler.instance == nullptr) {
        // -- Par defaut on peut faire 5 UNDO -- //
        handler.instance = new PileCaretaker(5);
        numIndex = 0;
    }
    return *handler.instance;
}

void PileCaretaker::libererInstance() {
    delete handler.instance;
    handler.instance=nullptr;
}


unsigned int PileCaretaker::numIndex = 0;


// -- Sauvegarde de la pile "principale" -- //

void PileCaretaker::saveState(Pile* orig) {

    // -- On creéer une sauvegarde de la pile et on l'ajoute nos etats en haut de la pile -- //
    PileMementoList.push(orig->saveStatePile());
    // -- Index de la plus haute sauvegarde dans la pile (version la plus récente) -- //
    numIndex++;
    QString index = QString::number(numIndex);
    Pile::getInstance().setMessage("Fucking index --> " + index + " !!");

    // -- On ne veut garder en memoire que NbEtatsSave de la pile: limiter l'impact en memoire des UNDO/REDO (on gère le nombre de sauvegarde en eliminant les plus anciennes si "plus de place") -- //
    while (numIndex >= NbEtatsSave) {
       const Pile::PileMemento* lastPile = PileMementoList.takeFirst();
       Pile* pileASupprimer = lastPile->getState();
       while(!pileASupprimer->empty()) {
           // -- On supprime toutes les litterales de la pile unes à unes (on s'assure de relacher toute la memoire) -- //
           Litterale* litASuppr = pileASupprimer->pop();
           delete litASuppr;
       }
       delete pileASupprimer;
       numIndex--;
    }
}



// -- Recupère une sauvegarde pour la "mettre" dans la pile "principale" -- //
void PileCaretaker::restoreDownState(Pile* orig) {

    // Si on veut retourner à un etat qui n'est plus stocké (on ne garde qu'un nombre fini, parametrable de PileMemento en memoire -- //
    // -- : Erreur, sinon si on veut faire un Undo alors qu'on a qu'une seule pile de sauvegarder: c'est la version actuelle donc on dit "stop les Undo" //
    if(numIndex < 1) {
        // -- On ne peut plus descendre on est deja en bas de la pile de sauvegarde -- //
        //CALCULATRICE_EXCEPTION ("Plus possible de faire un UNDO");
        QString index = QString::number(numIndex);
        Pile::getInstance().setMessage("C'est de la merde --> " + index + " !!");
    }
    else {
        // -- On décrémente numIndex (on descend dans l'historique des sauvegardes): On choisit la sauvegarde à restaurer  -- //
        const Pile::PileMemento* pileToRestore = PileMementoList[--numIndex];
        orig->restoreStatePile(pileToRestore);
    }
}


