#include "div.h"

//A VOIR POUR LES EXCEPTIONS !!

Litterale* Div::execute(Litterale** litterals) const {

    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    try {
        Litterale& res = (*operande1) / (*operande2);
        // On libere la memoire du tableau
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        delete[] litterals;
        //On oublie pas de delete le tableau qu'on a récupéré en argument
        return &res;
    }
    catch (CalculatriceException &e){
        Pile* stack = &Pile::getInstance();
        stack->setMessage(e.what());
    }
    // On libere la memoire du tableau
    for (unsigned int i = 0; i < Nb_a_depiler; i++) {
        delete litterals[i];
    }
    delete[] litterals;
    //On oublie pas de delete le tableau qu'on a récupéré en argument
    return nullptr;
}

