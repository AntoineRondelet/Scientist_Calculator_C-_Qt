#include "dup.h"

void Dup::execute(QVector<Litterale*> litterals) const {
    Litterale* operande = litterals[0];

    if (operande!=nullptr){
        Litterale* res = operande->clone(); //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme

        //On empile notre operande et notre resultat
        Pile::getInstance().push(operande);
        Pile::getInstance().push(res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}
