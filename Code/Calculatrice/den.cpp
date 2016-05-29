#include "den.h"

#include "entier.h"
#include "rationnel.h"

void Den::execute(QVector<Litterale*> litterals) const {
    Pile* stack = &Pile::getInstance();
    Rationnel* operande_rationnelle = dynamic_cast<Rationnel *>(litterals[0]);
    Entier* operandeEntier = dynamic_cast<Entier *>(litterals[0]);

    if(operande_rationnelle) {
        Entier* res= new Entier(operande_rationnelle->getDenominateur());
        //LitteraleNombre& ref = *res;
        stack->push(res);
        delete litterals[0];
    }
    else if (operandeEntier){
        Entier* res= new Entier(1);
        //LitteraleNombre& ref = *res;
        stack->push(res);
        delete litterals[0];
    }
    else {
        stack->setMessage("Erreur: Operande du mauvais type");
        //On réeimpile la littérale
        this->reChargerOperande(litterals);
    }
}
