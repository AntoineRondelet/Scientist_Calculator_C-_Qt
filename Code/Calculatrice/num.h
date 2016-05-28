#ifndef NUM_H
#define NUM_H

#include "unaryoperator.h"

class Num: public UnaryOperator {
public:
    Num(): UnaryOperator(){}
    Litterale* execute(Litterale** litterals) const override;
    Litterale** chargerOperande() const override; //On redefinit chargerOperande, car ici on ne veut que ds Entiers ou Rationnels
};


#endif // NUM_H
