#include "num.h"

#include "entier.h"
#include "rationnel.h"


Litterale** Num::chargerOperande() const {
    Pile* ptr_stack = &Pile::getInstance();

    if (ptr_stack->count() < Nb_a_depiler) {
        ptr_stack->setMessage("Pas assez d'elements dans la pile");
        return nullptr;
    }

    Litterale** loaded_lit = new Litterale*[Nb_a_depiler];

    Litterale* lit1 = ptr_stack->pop();
    cout << "V1: " << lit1->toString() << endl;

    if (((loaded_lit[0] = dynamic_cast<Rationnel*>(lit1))  != nullptr) || ((loaded_lit[0] = dynamic_cast<Entier*>(lit1)) != nullptr)) {
        return loaded_lit;
    }
    //else
    ptr_stack->setMessage("NUM Operator: Operande du mauvais type");
    //Si la litterale depilée est pas un rationnel ou un entier -> on le réempile + message sur la pile
    ptr_stack->push(lit1);
    delete[] loaded_lit;
    return nullptr;
}


Litterale* Num::execute(Litterale** litterals) const {
    if(Rationnel* operande_rationnelle = dynamic_cast<Rationnel *>(litterals[0])) {
        Entier* res= new Entier(operande_rationnelle->getNumerateur());
        LitteraleNombre& ref = *res;

        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        delete[] litterals;
        return &ref;
    }
    else if (Entier* operande_entiere = dynamic_cast<Entier *>(litterals[0])) {
        LitteraleNombre& ref = *operande_entiere;

        delete[] litterals;
        return &ref;
    }
    else return nullptr;
}
