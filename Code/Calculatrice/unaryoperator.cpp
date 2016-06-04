#include "unaryoperator.h"

QVector<Litterale*> UnaryOperator::chargerOperande() const{
    Pile& ptr_stack = Pile::getInstance();

    if (ptr_stack.count() < Nb_a_depiler) {
        ptr_stack.setMessage("Pas assez d'elements dans la pile");
        return {};
    }

    QVector<Litterale*> loaded_lit;

    for(unsigned int i=0; i < Nb_a_depiler; i++) {
            loaded_lit.push_back(ptr_stack.pop());
    }
    return loaded_lit;
}


void UnaryOperator::reChargerOperande(QVector<Litterale*> litterals) const {
    Pile& ptr_stack = Pile::getInstance();
    ptr_stack.setMessage("Operande du mauvais type"); //throw
    //on dépile tout du QVector et on remet tout dans la pile
    while (!litterals.isEmpty())
        ptr_stack.push(litterals.takeLast());
}



