#ifndef OPLOGIQUE_H
#define OPLOGIQUE_H

#include "binaryoperator.h"

class OpLogiqueEgal:public BinaryOperator{
public:
    OpLogiqueEgal(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};




#endif // OPLOGIQUE_H
