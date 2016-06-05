#include "mult.h"

#include "expression.h"
#include "litteralenum.h"
#include <QString>

void Mult::execute(QVector<Litterale*> litterals) const {

    Expression* operande2 = dynamic_cast<Expression*>(litterals[1]);
    LitteraleNum* operande1 = dynamic_cast<LitteraleNum*>(litterals[0]);

    Expression* operande1bis = dynamic_cast<Expression*>(litterals[0]);
    if(operande1!=nullptr && operande2!=nullptr) {
        Litterale& res = operande2->multiplication(*operande1);
        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empilele resultat
        Pile::getInstance().push(&res);
    }
    else if (operande1bis!=nullptr && operande2!=nullptr)  {
        Litterale& res = operande2->multiplication(*operande1bis);
        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empilele resultat
        Pile::getInstance().push(&res);
    }
    else {
        LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
        LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

        if (operande1!=nullptr && operande2!=nullptr){
            Litterale& res = (*operande2) * (*operande1); //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme

            //On delete le tableau qu'on a récupéré en argument
            for (unsigned int i = 0; i < Nb_a_depiler; i++) {
                delete litterals[i];
            }
            //On empilele resultat
            Pile::getInstance().push(&res);
        }
        else {
            this->reChargerOperande(litterals);
        }
    }
}
