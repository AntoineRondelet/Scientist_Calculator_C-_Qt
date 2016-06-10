#include "and.h"
#include "entier.h"

void And::execute(QVector<Litterale*> litterals) const {
    Entier* operande1 = dynamic_cast<Entier*>(litterals[0]);
    Entier* operande2 = dynamic_cast<Entier*>(litterals[1]);

    if (operande1!=nullptr && operande2!=nullptr){
        Litterale* res = nullptr;
        if (operande1->getValeur() != 0 && operande2->getValeur() != 0)
            res = new Entier(1);
        else
            res = new Entier(0);

        Pile::getInstance().push(res);
        Pile::lastOpname = "AND";
    }
    else {
        this->reChargerOperande(litterals);
    }
}
