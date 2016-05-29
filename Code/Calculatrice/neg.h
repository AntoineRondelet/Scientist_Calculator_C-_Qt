#ifndef NEG_H
#define NEG_H

#include "unaryoperator.h"


class Neg: public UnaryOperator {
public:
    Neg(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


#endif // NEG_H
