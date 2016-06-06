#include "div.h"

//A VOIR POUR LES EXCEPTIONS !!

#include "expression.h"
#include "litteralenum.h"
#include <QString>

void Div::execute(QVector<Litterale*> litterals) const {

    Expression* operande2 = dynamic_cast<Expression*>(litterals[1]);
    LitteraleNum* operande1 = dynamic_cast<LitteraleNum*>(litterals[0]);

    Expression* operande1bis = dynamic_cast<Expression*>(litterals[0]);

    if(operande1!=nullptr && operande2!=nullptr) {
        Litterale& res = operande2->division(*operande1);
        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empilele resultat
        Pile::getInstance().push(&res);
    }
    else if (operande1bis!=nullptr && operande2!=nullptr)  {
        Litterale& res = operande2->division(*operande1bis);
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
            try{
                Litterale& res = (*operande2) / (*operande1); //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme

                //On empilele resultat
                Pile::getInstance().push(&res);

                //On delete le tableau qu'on a récupéré en argument
                for (unsigned int i = 0; i < Nb_a_depiler; i++) {
                    delete litterals[i];
                }
            }
            catch (CalculatriceException& e){
                // -- On réempile les litterales -- //
                Pile::getInstance().push(litterals[1]);
                Pile::getInstance().push(litterals[0]);
                // -- Comme on catch l'expression on en refait une autre avec le message de l'ancienne pour relayer l'information pour haut -- //
                CALCULATRICE_EXCEPTION(e.getMsg());
            }
        }
        else {
            this->reChargerOperande(litterals);
        }
    }
}

