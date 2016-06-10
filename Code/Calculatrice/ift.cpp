#include "ift.h"

#include "entier.h"
#include "programme.h"
#include "expression.h"
#include "eval.h"

void Ift::execute(QVector<Litterale*> litterals) const {
    // -- IFT porte sur des TESTS LOGIQUES et DES LITTERALES EVALUABLES(prog ou expressions) -- //

    Programme* operande1 = dynamic_cast<Programme*>(litterals[0]);
    Expression* operandeEx = dynamic_cast<Expression*>(litterals[0]);

    // -- On doit avoir un entier car on sait que le resultat d'un test logique est un Entier -- //
    Entier* operande2 = dynamic_cast<Entier*>(litterals[1]);

    if((operande1 != nullptr && operande2 != nullptr) || (operandeEx != nullptr && operande2 != nullptr)) {
        // -- car toute valeur =/= 0 est considérée comme vraie -- //
        if(operande2->getValeur() != 0) {
            Eval objEval;
            QVector<Litterale*> vec;
            vec.push_back(litterals[0]);
            objEval.execute(vec);
            delete operande2;
            Pile::lastOpname = "IFT";
        }
        else{
            for (unsigned int i = 0; i < Nb_a_depiler; i++) {
                delete litterals[i];
            }
        }
    }
    else {
        // -- Sinon, opérandes du mauvais type: On les réempile -- //
        this->reChargerOperande(litterals);
    }
}
