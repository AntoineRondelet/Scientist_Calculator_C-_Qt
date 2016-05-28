#ifndef MULT_H
#define MULT_H

#include "binaryoperator.h"


class Mult: public BinaryOperator {
public:
    Mult(): BinaryOperator(){}
    Litterale* execute(Litterale** litterals) const override;
};


#endif // MULT_H
