#include "unaryoperator.h"


Litterale** UnaryOperator::chargerOperande() const{
    Pile* ptr_stack = &Pile::getInstance();

    if (ptr_stack->count() < Nb_a_depiler) {
        ptr_stack->setMessage("Pas assez d'elements dans la pile");
        return nullptr;
    }
    Litterale** loaded_lit = new Litterale*[Nb_a_depiler];

    Litterale* lit1 = ptr_stack->pop();
    cout << "V1: " << lit1->toString() << endl;

    loaded_lit[0] = dynamic_cast<LitteraleNombre *>(lit1);
    if (loaded_lit[0] == nullptr) {
        ptr_stack->setMessage("Unary Operator: Operande du mauvais type");
        //ATTENTION: On doit réempiler lit2 avant lit1 pour retrouver le meme ordre dans les litterales de la pile !
        ptr_stack->push(lit1);
        delete[] loaded_lit;
        return nullptr;
    }
    return loaded_lit;
}


