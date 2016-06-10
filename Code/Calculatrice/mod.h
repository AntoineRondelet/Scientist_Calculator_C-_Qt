#ifndef MOD_H
#define MOD_H

#include "binaryoperator.h"


class Mod: public BinaryOperator {
public:
    Mod(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const;
};

#endif // MOD_H
