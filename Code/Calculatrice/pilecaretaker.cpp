
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


// -- Sauvegarde de la pile "principale" -- //

void PileCaretaker::saveState(Pile* orig) {
    if (numIndex<PileMementoList.size()-1) { //Alors on fait des modifs a partir d'un état restauré
        PileMementoList[++numIndex] = orig->saveStatePile();
    }
    else {
        PileMementoList.push(orig->saveStatePile());
        numIndex++;
        // -- On ne veut que NbEtatsSave sauvegardes en memoire à la fois: On supprime les plus anciennes (on ne garde que les plus recentes) -- //
        // -- On se limite a un nombre fini de sauvegardes de piles (parametrable par l'user via setNbEtatsSave() par exemple: On limite l'impact memoire du UNDO/REDO -- //
        if (numIndex > NbEtatsSave-1) {
            const Pile::PileMemento* pileToDelete = PileMementoList.takeFirst();
            while (!pileToDelete->getState()->empty()){
                delete pileToDelete->getState()->pop();
            }
            delete pileToDelete;
            numIndex--;
        }
    }
}

// -- Recupère une sauvegarde pour la "mettre" dans la pile "principale" -- //

// -- UNDO -- //
void PileCaretaker::restoreDownState(Pile* orig) {
    if (!PileMementoList.empty() && numIndex > 0){
        QString index = QString::number(numIndex);
        //orig->setMessage("INDEX RESTORE : " + index + "  BLABLA <-----");
        // -- On descends dans l'historique des sauvegardes: donc on décrémente notre index -- //
        const Pile::PileMemento* pileToRestore = PileMementoList[--numIndex];
        orig->restoreStatePile(pileToRestore);
    }
    // -- liste de piles de sauvegardes est vide -- //
    else {
        //orig->setMessage("Vous etes sur la derniere sauvegarde: UNDO impossible");
        CALCULATRICE_EXCEPTION("Sauvegardes: Impossible de revenir en arrière (undo) car liste piles vide !");
    }
}


// -- REDO -- //
void PileCaretaker::restoreUpState(Pile* orig) {
    if (!PileMementoList.empty() && numIndex < PileMementoList.size()-1){
        QString index = QString::number(numIndex);
        //orig->setMessage("INDEX RESTORE : " + index + "  BLABLA <-----");
        // -- On monte dans l'historique des sauvegardes: donc on incrémente notre index -- //
        const Pile::PileMemento* pileToRestore = PileMementoList[++numIndex];
        orig->restoreStatePile(pileToRestore);
    }
    // -- liste de piles de sauvegardes est vide -- //
    else {
        //orig->setMessage("Vous etes sur la sauvegarde la plus récente: REDO impossible");
        CALCULATRICE_EXCEPTION("Sauvegardes: Impossible de revenir en arrière (undo) car liste piles vide !");
    }
}
