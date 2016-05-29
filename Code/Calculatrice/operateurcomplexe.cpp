#include "operateurcomplexe.h"


void OperateurComplexe::execute(QVector<Litterale*> litterals) const {
    LitteraleNum* operande1 = dynamic_cast<LitteraleNum *>(litterals[0]);
    LitteraleNum* operande2 = dynamic_cast<LitteraleNum *>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale* res = new Complexe(*operande2, *operande1);

        //ATTENTION /!\ Ci dessous on ne doit plus detruire le tableau des litterales
        //Elles sont desormais composées par le complexe -> Si on les detruits, on detruit de ce fait
        //la partie reel et imaginaire de notre complexe !
        /*
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }*/
        //On empilele resultat
        Pile* stack = &Pile::getInstance();
        stack->push(res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}
