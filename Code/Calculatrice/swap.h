#ifndef SWAP_H
#define SWAP_H

#include "binaryoperator.h"

class Swap: public BinaryOperator{
public:
    Swap(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // SWAP_H
