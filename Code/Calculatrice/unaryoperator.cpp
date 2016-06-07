#include "unaryoperator.h"
#include "calculatriceexception.h"

QVector<Litterale*> UnaryOperator::chargerOperande() const{
    Pile& ptr_stack = Pile::getInstance();

    if (ptr_stack.count() < Nb_a_depiler) {
        CALCULATRICE_EXCEPTION("La pile doit contenir au moins 1 element");
    }

    QVector<Litterale*> loaded_lit;

    for(unsigned int i=0; i < Nb_a_depiler; i++) {
            loaded_lit.push_back(ptr_stack.pop());
    }
    return loaded_lit;
}


void UnaryOperator::reChargerOperande(QVector<Litterale*> litterals) const {
    Pile& ptr_stack = Pile::getInstance();
    while (!litterals.isEmpty())
        ptr_stack.push(litterals.takeLast());
    CALCULATRICE_EXCEPTION("Operandes du mauvais type");
}



