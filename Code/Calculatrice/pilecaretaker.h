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
    PileCaretaker(unsigned int NbEtats, unsigned int nbIndex=0): NbEtatsSave(NbEtats), numIndex(nbIndex), PileMementoList(QStack<const Pile::PileMemento*>()){}
    int getNumIndex() const {return numIndex;}
    int getNbEtatsSave() const {return NbEtatsSave;}
    void setNbEtatsSave(unsigned int nb) {NbEtatsSave = nb;}


    // -- Save state de la pile "principale": Ajoute une pile de sauvegarde dans PileMementoList -- //
    //void saveState(Pile* orig);
    // -- restore un ancien state de la pile "principale": Va récuperer une pile de sauvegarde pour la fetch/"deverser" dans la pile "principale pour repartir d'une sauvegarde -- //
    //void restoreDownState(Pile* orig);


    // -- Sauvegarde de la pile "principale" -- //

    void saveState(Pile* orig) {
        PileMementoList.push(orig->saveStatePile());
        numIndex+=1;
        QString index = QString::number(this->numIndex);
        orig->setMessage("INDEX SAVE : " + index + "  <-----");
    }

    // -- Recupère une sauvegarde pour la "mettre" dans la pile "principale" -- //
    void restoreDownState(Pile* orig) {
        QString index2 = QString::number(numIndex);
        orig->setMessage("INDEX RESTORE : " + index2 + "  <-----");
        const Pile::PileMemento* pileToRestore = PileMementoList[--numIndex];
        orig->restoreStatePile(pileToRestore);

/*
        int taille = getNumIndex();
        if (!PileMementoList.empty() && taille > 0){
            QString index = QString::number(taille);
            stack->setMessage("INDEX RESTORE : " + index + "  BLABLA <-----");
            //numIndex--; // on descends dans la liste des piles, donc on décrémente notre index.
            const Pile::PileMemento* pileToRestore = PileMementoList[--taille];
            orig->restoreStatePile(pileToRestore);
        } else { // liste de piles vide
            CALCULATRICE_EXCEPTION("BackUpPiles : Impossible de revenir en arrière (undo) car liste piles vide !");
        }
        */
    }



    // -- Singleton -- //
    static PileCaretaker& getInstance();
    static void libererInstance();
};

#endif // PILECARETAKER_H

