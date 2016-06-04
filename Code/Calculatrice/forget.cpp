#include "forget.h"

#include <QString>
#include "atome.h"
#include "litterale.h"
#include "identificateurmanager.h"


/*
void Forget::execute(QVector<Litterale*> litterals) const {
    Litterale* operande = dynamic_cast<Litterale*>(litterals[0]);

    if (operande!=nullptr){
        IdentificateurManager& id_man = IdentificateurManager::getInstance();
        id_man.supprimerIdentificateur(operande);

        // -- On delete le tableau qu'on a récupéré en argument -- //
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empile le resultat: Pas de resultat à empiler ici
        //Pile::getInstance().push(&res);
    }
    else {
        this->reChargerOperande(litterals);
    }
}
*/
