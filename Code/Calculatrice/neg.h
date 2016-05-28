#ifndef NEG_H
#define NEG_H

#include "unaryoperator.h"


class Neg: public UnaryOperator {
public:
    Neg(): UnaryOperator(){}
    Litterale* execute(Litterale** litterals) const override;
};


#endif // NEG_H
