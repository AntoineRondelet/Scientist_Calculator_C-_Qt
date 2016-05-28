#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include "operator.h"
#include "litteralenombre.h"


class BinaryOperator: public Operator {
protected:
    unsigned int Nb_a_depiler;
public:
    BinaryOperator(): Operator(), Nb_a_depiler(2){}
    Litterale** chargerOperande() const override; //2 operandes a depiler
};



#endif // BINARYOPERATOR_H
