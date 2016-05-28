#include "binaryoperator.h"

#include "pile.h"
#include <vector>


Litterale** BinaryOperator::chargerOperande() const{
    Pile* ptr_stack = &Pile::getInstance();
    Litterale** loaded_lit = new Litterale*[Nb_a_depiler];

    Litterale* lit1 = ptr_stack->pop();
    cout << "V1: " << lit1->toString() << endl;

    Litterale* lit2 = ptr_stack->pop();
    cout << "V2: " << lit1->toString() << endl;


    //A faire dans la classe BinaryNumericOperator
    loaded_lit[0] = dynamic_cast<LitteraleNombre *>(lit1);
    if (loaded_lit[0] == nullptr) {
        cout << "pas un nombre, on réempile" << endl;
        //ATTENTION: On doit réempiler lit2 avant lit1 pour retrouver le meme ordre dans les litterales de la pile !
        ptr_stack->push(lit2);
        ptr_stack->push(lit1);
        return nullptr;
    }

    loaded_lit[1] = dynamic_cast<LitteraleNombre *>(lit2);
    if (loaded_lit[1] == nullptr) {
        cout << "pas un nombre, on réempile" << endl;
        ptr_stack->push(lit2);
        ptr_stack->push(lit1);
        return nullptr;
    }

    return loaded_lit;
}

