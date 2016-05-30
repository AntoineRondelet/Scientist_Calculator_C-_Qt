#ifndef OPERATEURCOMPLEXE_H
#define OPERATEURCOMPLEXE_H


#include "binaryoperator.h"
#include "complexe.h"
#include "function.h"


class OperateurComplexe: public BinaryOperator {
public:
    OperateurComplexe(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


#endif // OPERATEURCOMPLEXE_H
