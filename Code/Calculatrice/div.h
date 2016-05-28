#ifndef DIV_H
#define DIV_H

#include "binaryoperator.h"


class Div: public BinaryOperator {
public:
    Div(): BinaryOperator(){}
    Litterale* execute(Litterale** litterals) const override;
};


#endif // DIV_H
