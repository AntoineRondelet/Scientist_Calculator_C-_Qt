#ifndef NOT_H
#define NOT_H

#include "unaryoperator.h"

class Not: public UnaryOperator{
public:
    Not(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // NOT_H
