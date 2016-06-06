#ifndef OPLOGIQUE_H
#define OPLOGIQUE_H

#include "binaryoperator.h"

class OpLogiqueEgal:public BinaryOperator{
public:
    OpLogiqueEgal(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

class OpLogiqueDiffEgal:public BinaryOperator{
public:
    OpLogiqueDiffEgal(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


class OpLogiqueInf:public BinaryOperator{
public:
    OpLogiqueInf(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


class OpLogiqueSup:public BinaryOperator{
public:
    OpLogiqueSup(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


class OpLogiqueInfEgal:public BinaryOperator{
public:
    OpLogiqueInfEgal(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


class OpLogiqueSupEgal:public BinaryOperator{
public:
    OpLogiqueSupEgal(): BinaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


#endif // OPLOGIQUE_H
