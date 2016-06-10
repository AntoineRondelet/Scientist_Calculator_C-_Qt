#include "mod.h"
#include "entier.h"
#include "pile.h"

void Mod::execute(QVector<Litterale*> litterals) const {

    Entier* operande2 = dynamic_cast<Entier *>(litterals[0]);
    Entier* operande1 = dynamic_cast<Entier *>(litterals[1]);
    try{
        if (operande1 != nullptr && operande2 != nullptr && operande2->getValeur() != 0) {
            Entier* rslt=new Entier((operande1->getValeur()) % (operande2->getValeur()));
            LitteraleNombre& res = *rslt;
    // On libere la memoire du tableau
            for (unsigned int i = 0; i < Nb_a_depiler; i++) {
                delete litterals[i];
            }
    //On oublie pas de delete le tableau qu'on a récupéré en argument
            Pile& p = Pile::getInstance();
            p.push_back(&res);
        }
        else{
            if (operande1 == nullptr || operande2 == nullptr){
                CALCULATRICE_EXCEPTION("ERREUR: Au moins l'un des deux opérandes n'est pas une littérale entière");
            }
            else if(operande2->getValeur() == 0){
                CALCULATRICE_EXCEPTION("ERREUR: Impossible de diviser par 0");
            }
        }
    }

    catch(CalculatriceException& e){
        Pile& p = Pile::getInstance();
        p.push_back(litterals[1]);
        p.push_back(litterals[0]);
        CALCULATRICE_EXCEPTION(e.getMsg());

    }
}
