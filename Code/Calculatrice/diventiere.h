#ifndef DIVENTIERE_H
#define DIVENTIERE_H

#include "binaryoperator.h"


class Diventiere: public BinaryOperator {
public:
    Diventiere(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // DIVENTIERE_H
