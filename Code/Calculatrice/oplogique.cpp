#include "oplogique.h"

#include "expression.h"
#include "entier.h"

void OpLogiqueEgal::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale* res = nullptr;
        if(operande2->egal(*operande1)) //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empile le resultat
        Pile::getInstance().push(res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}




void OpLogiqueInf::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale* res = nullptr;
        if(operande2->inferieur(*operande1)) //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empile le resultat
        Pile::getInstance().push(res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}



void OpLogiqueSup::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale* res = nullptr;
        if(operande2->superieur(*operande1)) //On a des operandes qui sont des ptr sur des LitteralesNombre -> l'operateur + y est defini -> polymorphisme
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empile le resultat
        Pile::getInstance().push(res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}



void OpLogiqueInfEgal::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale* res = nullptr;
        if(operande2->inferieur(*operande1) || operande2->egal(*operande1))
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empile le resultat
        Pile::getInstance().push(res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}



void OpLogiqueSupEgal::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale* res = nullptr;
        if(operande2->superieur(*operande1) || operande2->egal(*operande1))
            res = new Entier(1);
        else
            res = new Entier(0);

        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empile le resultat
        Pile::getInstance().push(res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}

