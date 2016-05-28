#include "sous.h"

#include "Sous.h"

Litterale* Sous::execute(QVector<Litterale*> litterals) const {

    LitteraleNombre* operande1 = dynamic_cast<LitteraleNombre *>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    Litterale& res = (*operande1) - (*operande2);

    //factorisable a tous les operateurs binaires -> template method comme pour les operateurs + - etc du debut
    for (unsigned int i = 0; i < Nb_a_depiler; i++) {
        delete litterals[i];
    }
    //On oublie pas de delete le tableau qu'on a récupéré en argument -> ce tableau c'est comme un registre dans lequel on met les litterals depilées prettent a etre sommées (dans ce cas ci)
    return &res;
}



