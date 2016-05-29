#include "add.h"

#include <QString>

void Add::execute(QVector<Litterale*> litterals) const {
    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale& res = (*operande2) + (*operande1); //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme

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
