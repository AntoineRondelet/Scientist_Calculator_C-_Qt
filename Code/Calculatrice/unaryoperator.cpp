#include "unaryoperator.h"

QVector<Litterale*> UnaryOperator::chargerOperande() const{
    Pile* ptr_stack = &Pile::getInstance();

    if (ptr_stack->count() < Nb_a_depiler) {
        ptr_stack->setMessage("Pas assez d'elements dans la pile");
        return {};
    }

    QVector<Litterale*> loaded_lit;

    for(unsigned int i=0; i < Nb_a_depiler; i++) {
        Litterale* lit_depilee = ptr_stack->pop();
        LitteraleNombre* litTemp = dynamic_cast<LitteraleNombre *>(lit_depilee);
        if (litTemp != nullptr) {
            loaded_lit.push_back(lit_depilee);
        }
        else {
            ptr_stack->setMessage("Operandes du mauvais type");
            //on dépile tout du QVector et on remet tout dans la pile
            while (loaded_lit.isEmpty() == false)
                ptr_stack->push(loaded_lit.takeLast());
            return {};
            }
        }
    return loaded_lit;
}


