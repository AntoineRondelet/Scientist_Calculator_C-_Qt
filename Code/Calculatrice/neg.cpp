#include "neg.h"
#include "entier.h"

void Neg::execute(QVector<Litterale*> litterals) const {
    LitteraleNombre* operande = dynamic_cast<LitteraleNombre *>(litterals[0]);

    if (operande!=nullptr){
        Entier temp(-1);
        Litterale& res = temp * (*operande); //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme

        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empilele resultat
        Pile* stack = &Pile::getInstance();
        stack->push(&res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}

