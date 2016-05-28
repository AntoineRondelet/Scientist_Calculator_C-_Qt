#ifndef UNARYOPERATOR_H
#define UNARYOPERATOR_H

#include "operator.h"
#include "pile.h"
#include "litteralenombre.h"

class UnaryOperator: public Operator {
protected:
    unsigned int Nb_a_depiler;
public:
    UnaryOperator(): Operator(), Nb_a_depiler(1){} //Nb_a_depiler vaut tjrs 1 ici on est dans le cas d'un operateur unaire
    QVector<Litterale*> chargerOperande() const override; //On renvoie un tableau des litterales depilées
};

#endif // UNARYOPERATOR_H
