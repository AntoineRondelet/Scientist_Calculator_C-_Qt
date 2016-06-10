#include "num.h"

#include "entier.h"
#include "rationnel.h"


void Num::execute(QVector<Litterale*> litterals) const {
    Pile& stack = Pile::getInstance();
    Rationnel* operande_rationnelle = dynamic_cast<Rationnel *>(litterals[0]);
    Entier* operandeEntier = dynamic_cast<Entier *>(litterals[0]);

    if(operande_rationnelle) {
        Entier* res= new Entier(operande_rationnelle->getNumerateur());
        stack.push(res);
        delete litterals[0];
        Pile::lastOpname = "NUM";
    }
    else {
        if (!operandeEntier)
            //On réeimpile la littérale
            this->reChargerOperande(litterals);
            CALCULATRICE_EXCEPTION("Erreur: Operande du mauvais type");
    }
}

