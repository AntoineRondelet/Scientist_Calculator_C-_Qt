#ifndef EVAL_H
#define EVAL_H

#include "unaryoperator.h"


// -- Operateur unaire juste sur une expression -- //
class Eval: public UnaryOperator{
public:
    Eval(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override{}
};

#endif // EVAL_H
