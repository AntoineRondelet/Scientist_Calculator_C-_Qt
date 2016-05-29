#include "den.h"

#include "entier.h"
#include "rationnel.h"

Litterale* Den::execute(QVector<Litterale*> litterals) const {
    if(Rationnel* operande_rationnelle = dynamic_cast<Rationnel *>(litterals[0])) {
        Entier* res= new Entier(operande_rationnelle->getDenominateur());
        LitteraleNombre& ref = *res;
        delete litterals[0];
        return &ref;
    }
    else if (dynamic_cast<Entier *>(litterals[0])) {
        Entier* res= new Entier(1);
        LitteraleNombre& ref = *res;
        delete litterals[0];
        return &ref;
    }
    else {
        Pile* stack = &Pile::getInstance();
        stack->setMessage("Erreur: Operande du mauvais type");
        //On réeimpile la littérale
        return litterals[0];
    }
}
