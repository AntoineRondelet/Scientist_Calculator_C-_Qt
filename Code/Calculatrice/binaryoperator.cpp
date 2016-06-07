#include "binaryoperator.h"

#include "pile.h"
#include <vector>




//Ici c'est plutot une methode de la classe BinaryOperatorNumeric qu'il faudra peut etre faire -> A VOIR
QVector<Litterale*> BinaryOperator::chargerOperande() const{
    Pile& ptr_stack = Pile::getInstance();

    if (ptr_stack.count() < Nb_a_depiler) {
        CALCULATRICE_EXCEPTION("La pile doit contenir au moins 2 elements");
    }

    QVector<Litterale*> loaded_lit;

    for(unsigned int i=0; i < Nb_a_depiler; i++) {
            loaded_lit.push_back(ptr_stack.pop());
    }
    return loaded_lit;
}


void BinaryOperator::reChargerOperande(QVector<Litterale*> litterals) const {
    Pile& ptr_stack = Pile::getInstance();
    while (!litterals.isEmpty())
        ptr_stack.push(litterals.takeLast());
    CALCULATRICE_EXCEPTION("Operandes du mauvais type");
}
