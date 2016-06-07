#ifndef AND_H
#define AND_H

#include "binaryoperator.h"


class And: public BinaryOperator{
public:
    And(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // AND_H
