#include "neg.h"
#include "entier.h"

Litterale* Neg::execute(Litterale** litterals) const {
    LitteraleNombre* operande = dynamic_cast<LitteraleNombre *>(litterals[0]);

    Entier ent(-1);
    Litterale& res = ent * (*operande);

    //factorisable a tous les operateurs binaires -> template method comme pour les operateurs + - etc du debut
    for (unsigned int i = 0; i < Nb_a_depiler; i++) {
        delete litterals[i];
    }
    delete[] litterals;
    //On oublie pas de delete le tableau qu'on a récupéré en argument -> ce tableau c'est comme un registre dans lequel on met les litterals depilées prettent a etre sommées (dans ce cas ci)
    return &res;
}

