#include "oplogique.h"

#include "expression.h"
#include "entier.h"
#include "eval.h"
#include <QVector>

void OpLogiqueEgal::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operandeNb1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operandeNb2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    Expression* operande1Ex = dynamic_cast<Expression*>(litterals[0]);
    Expression* operande2Ex = dynamic_cast<Expression*>(litterals[1]);

    // -- Si on opère sur des expressions, on les evalue et on opère ensuite sur les nombres renvoyés par l'evaluation -- //
    Eval objEval;
    if(operande1Ex != nullptr) {
        QVector<Litterale*> vec;
        vec.push_back(litterals[0]);
        objEval.execute(vec);
        Litterale* result = Pile::getInstance().pop();
        operandeNb1 = dynamic_cast<LitteraleNombre *>(result);
    }
    if(operande2Ex != nullptr) {
        QVector<Litterale*> vec2;
        vec2.push_back(litterals[1]);
        objEval.execute(vec2);
        Litterale* result = Pile::getInstance().pop();
        operandeNb2 = dynamic_cast<LitteraleNombre *>(result);
    }

    // -- Nombre et nombre -- //
    if (operandeNb1!=nullptr && operandeNb2!=nullptr){
        Litterale* res = nullptr;
        if(operandeNb2->egal(*operandeNb1))
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        delete operandeNb1;
        delete operandeNb2;

        //On empile le resultat
        Pile::getInstance().push(res);
        Pile::lastOpname = "=";
    }
}




void OpLogiqueDiffEgal::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operandeNb1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operandeNb2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    Expression* operande1Ex = dynamic_cast<Expression*>(litterals[0]);
    Expression* operande2Ex = dynamic_cast<Expression*>(litterals[1]);

    // -- Si on opère sur des expressions, on les evalue et on opère ensuite sur les nombres renvoyés par l'evaluation -- //
    Eval objEval;
    if(operande1Ex != nullptr) {
        QVector<Litterale*> vec;
        vec.push_back(litterals[0]);
        objEval.execute(vec);
        Litterale* result = Pile::getInstance().pop();
        operandeNb1 = dynamic_cast<LitteraleNombre *>(result);
    }
    if(operande2Ex != nullptr) {
        QVector<Litterale*> vec2;
        vec2.push_back(litterals[1]);
        objEval.execute(vec2);
        Litterale* result = Pile::getInstance().pop();
        operandeNb2 = dynamic_cast<LitteraleNombre *>(result);
    }

    // -- Nombre et nombre -- //
    if (operandeNb1!=nullptr && operandeNb2!=nullptr){
        Litterale* res = nullptr;
        if(operandeNb2->egal(*operandeNb1))
            res = new Entier(0);
        else
            res = new Entier(1);

        //On delete le tableau qu'on a récupéré en argument
        delete operandeNb1;
        delete operandeNb2;

        //On empile le resultat
        Pile::getInstance().push(res);
        Pile::lastOpname = "!=";
    }
}






void OpLogiqueInf::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operandeNb1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operandeNb2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    Expression* operande1Ex = dynamic_cast<Expression*>(litterals[0]);
    Expression* operande2Ex = dynamic_cast<Expression*>(litterals[1]);

    // -- Si on opère sur des expressions, on les evalue et on opère ensuite sur les nombres renvoyés par l'evaluation -- //
    Eval objEval;
    if(operande1Ex != nullptr) {
        QVector<Litterale*> vec;
        vec.push_back(litterals[0]);
        objEval.execute(vec);
        Litterale* result = Pile::getInstance().pop();
        operandeNb1 = dynamic_cast<LitteraleNombre *>(result);
    }
    if(operande2Ex != nullptr) {
        QVector<Litterale*> vec2;
        vec2.push_back(litterals[1]);
        objEval.execute(vec2);
        Litterale* result = Pile::getInstance().pop();
        operandeNb2 = dynamic_cast<LitteraleNombre *>(result);
    }

    // -- Nombre Nombre -- //
    if (operandeNb1!=nullptr && operandeNb2!=nullptr){
        Litterale* res = nullptr;
        if(operandeNb2->inferieur(*operandeNb1)) //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        delete operandeNb1;
        delete operandeNb2;

        //On empile le resultat
        Pile::getInstance().push(res);
        Pile::lastOpname = "<";
    }
    else {
        this->reChargerOperande(litterals);
    }
}



void OpLogiqueSup::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operandeNb1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operandeNb2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    Expression* operande1Ex = dynamic_cast<Expression*>(litterals[0]);
    Expression* operande2Ex = dynamic_cast<Expression*>(litterals[1]);

    // -- Si on opère sur des expressions, on les evalue et on opère ensuite sur les nombres renvoyés par l'evaluation -- //
    Eval objEval;
    if(operande1Ex != nullptr) {
        QVector<Litterale*> vec;
        vec.push_back(litterals[0]);
        objEval.execute(vec);
        Litterale* result = Pile::getInstance().pop();
        operandeNb1 = dynamic_cast<LitteraleNombre *>(result);
    }
    if(operande2Ex != nullptr) {
        QVector<Litterale*> vec2;
        vec2.push_back(litterals[1]);
        objEval.execute(vec2);
        Litterale* result = Pile::getInstance().pop();
        operandeNb2 = dynamic_cast<LitteraleNombre *>(result);
    }

    // -- Nombre nombre -- //
    if (operandeNb1!=nullptr && operandeNb2!=nullptr){
        Litterale* res = nullptr;
        if(operandeNb2->superieur(*operandeNb1)) //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        delete operandeNb1;
        delete operandeNb2;

        //On empile le resultat
        Pile::getInstance().push(res);
        Pile::lastOpname = ">";
    }
    else {
        this->reChargerOperande(litterals);
    }
}



void OpLogiqueInfEgal::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operandeNb1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operandeNb2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    Expression* operande1Ex = dynamic_cast<Expression*>(litterals[0]);
    Expression* operande2Ex = dynamic_cast<Expression*>(litterals[1]);

    // -- Si on opère sur des expressions, on les evalue et on opère ensuite sur les nombres renvoyés par l'evaluation -- //
    Eval objEval;
    if(operande1Ex != nullptr) {
        QVector<Litterale*> vec;
        vec.push_back(litterals[0]);
        objEval.execute(vec);
        Litterale* result = Pile::getInstance().pop();
        operandeNb1 = dynamic_cast<LitteraleNombre *>(result);
    }
    if(operande2Ex != nullptr) {
        QVector<Litterale*> vec2;
        vec2.push_back(litterals[1]);
        objEval.execute(vec2);
        Litterale* result = Pile::getInstance().pop();
        operandeNb2 = dynamic_cast<LitteraleNombre *>(result);
    }

    // -- Nombre nombre -- //
    if (operandeNb1!=nullptr && operandeNb2!=nullptr){
        Litterale* res = nullptr;
        if(operandeNb2->inferieur(*operandeNb1) || operandeNb2->egal(*operandeNb1))
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        delete operandeNb1;
        delete operandeNb2;

        //On empile le resultat
        Pile::getInstance().push(res);
        Pile::lastOpname = "<=";
    }
    else {
        this->reChargerOperande(litterals);
    }
}



void OpLogiqueSupEgal::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operandeNb1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operandeNb2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    Expression* operande1Ex = dynamic_cast<Expression*>(litterals[0]);
    Expression* operande2Ex = dynamic_cast<Expression*>(litterals[1]);

    // -- Si on opère sur des expressions, on les evalue et on opère ensuite sur les nombres renvoyés par l'evaluation -- //
    Eval objEval;
    if(operande1Ex != nullptr) {
        QVector<Litterale*> vec;
        vec.push_back(litterals[0]);
        objEval.execute(vec);
        Litterale* result = Pile::getInstance().pop();
        operandeNb1 = dynamic_cast<LitteraleNombre *>(result);
    }
    if(operande2Ex != nullptr) {
        QVector<Litterale*> vec2;
        vec2.push_back(litterals[1]);
        objEval.execute(vec2);
        Litterale* result = Pile::getInstance().pop();
        operandeNb2 = dynamic_cast<LitteraleNombre *>(result);
    }

    // -- Nombre nombre -- //
    if (operandeNb1!=nullptr && operandeNb2!=nullptr){
        Litterale* res = nullptr;
        if(operandeNb2->superieur(*operandeNb1) || operandeNb2->egal(*operandeNb1))
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        delete operandeNb1;
        delete operandeNb2;

        //On empile le resultat
        Pile::getInstance().push(res);
        Pile::lastOpname = ">=";
    }
    else {
        this->reChargerOperande(litterals);
    }
}

