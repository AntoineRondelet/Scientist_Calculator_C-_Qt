#include "binaryoperator.h"

#include "pile.h"
#include <vector>

/*
QVector<Litterale*> BinaryOperator::chargerOperande() const{
    Pile* ptr_stack = &Pile::getInstance();

    if (ptr_stack->count() < Nb_a_depiler) {
        ptr_stack->setMessage("Pas assez d'elements dans la pile");
        return {};
    }

    QVector<Litterale*> loaded_lit;

    Litterale* lit1 = ptr_stack->pop();
    cout << "V1: " << lit1->toString() << endl;

    Litterale* lit2 = ptr_stack->pop();
    cout << "V2: " << lit2->toString() << endl;

    LitteraleNombre* litTemp1 = dynamic_cast<LitteraleNombre *>(lit1);
    LitteraleNombre* litTemp2 = dynamic_cast<LitteraleNombre *>(lit2);
    if (litTemp1 == nullptr || litTemp2 == nullptr) {
        ptr_stack->setMessage("Operandes du mauvais type");
        //ATTENTION: On doit réempiler lit2 avant lit1 pour retrouver le meme ordre dans les litterales de la pile !
        ptr_stack->push(lit2);
        ptr_stack->push(lit1);
        return{};
    }

    loaded_lit.push_back(lit1);
    loaded_lit.push_back(lit2);

    return loaded_lit;
}
*/

QVector<Litterale*> BinaryOperator::chargerOperande() const{
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

