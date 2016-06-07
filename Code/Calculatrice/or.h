#ifndef OR_H
#define OR_H

#include "binaryoperator.h"

class Or: public BinaryOperator{
public:
    Or(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // OR_H
