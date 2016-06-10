#include "not.h"
#include "entier.h"

void Not::execute(QVector<Litterale*> litterals) const {
    Entier* operande1 = dynamic_cast<Entier*>(litterals[0]);

    if (operande1!=nullptr){
        Litterale* res = nullptr;
        if (operande1->getValeur() != 0)
            res = new Entier(0);
        else
            res = new Entier(1);

        Pile::getInstance().push(res);
        Pile::lastOpname = "NOT";
    }
    else {
        this->reChargerOperande(litterals);
    }
}
