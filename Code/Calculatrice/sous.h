#ifndef SOUS_H
#define SOUS_H

#include "binaryoperator.h"


class Sous: public BinaryOperator {
public:
    Sous(): BinaryOperator(){}
    Litterale* execute(QVector<Litterale*> litterals) const override;
};



#endif // SOUS_H
