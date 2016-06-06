#ifndef IFT_H
#define IFT_H

#include "binaryoperator.h"

class Ift: public BinaryOperator {
public:
    Ift(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // IFT_H
