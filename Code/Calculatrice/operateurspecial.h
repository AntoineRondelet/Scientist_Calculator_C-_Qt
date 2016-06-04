#ifndef OPERATEURSPECIAL_H
#define OPERATEURSPECIAL_H

#include "operator.h"

class OperateurSpecial: public Operator {
public:
    OperateurSpecial(): Operator(){}
    // -- Ces methodes ne font rien. Ici cela peut paraitre etrange mais on a choisit de dire: On fait une classe d'opérateurs qui sont -- //
    // -- un peu speciaux (mais qui reste des opérateurs: beneficier du polymorphisme), mais ils ne feront rien quand on leur -- //
    // -- demandera de decharger des opérandes de la pile et quand il faudra en recharger. Ils s'executeront juste -- //
    QVector<Litterale*> chargerOperande() const override{return QVector<Litterale*>();}
    void reChargerOperande(QVector<Litterale*> litterals) const override{}
};

#endif // OPERATEURSPECIAL_H
