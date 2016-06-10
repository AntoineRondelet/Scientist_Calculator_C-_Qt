#include "re.h"
#include "complexe.h"
#include "rationnel.h"
#include "reel.h"
#include "calculatriceexception.h"
#include "litteralenombre.h"

void Re::execute(QVector<Litterale*> litterals) const {
        Complexe* operande = dynamic_cast<Complexe *>(litterals[0]);
try{
    if (operande!=nullptr){
        const LitteraleNombre* temp = operande->getPartEnt();


        //On delete le tableau qu'on a récupéré en argument
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
        //On empilele resultat
        Pile& stack = Pile::getInstance();
        LitteraleNombre& res = dynamic_cast<LitteraleNombre &>(*temp->clone());
        stack.push(&res);
        Pile::lastOpname = "RE";
    }
    else{
        CALCULATRICE_EXCEPTION("Erreur : La litterale n'est pas un complexe");
    }
    }
    catch(CalculatriceException& e){
    Pile& p = Pile::getInstance();
    p.push_back(litterals[0]);
    CALCULATRICE_EXCEPTION(e.getMsg());
    }

}

