#ifndef STO_H
#define STO_H

#include "binaryoperator.h"

class Sto: public BinaryOperator{
public:
    Sto(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // STO_H
