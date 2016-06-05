#include "oplogique.h"

#include "expression.h"

void OpLogiqueEgal::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale& res = operande2->egal(*operande1); //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme

        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empile le resultat
        Pile::getInstance().push(&res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}
