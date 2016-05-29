#ifndef ADD_H
#define ADD_H

#include "binaryoperator.h"


class Add: public BinaryOperator {
public:
    Add(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


#endif // ADD_H
