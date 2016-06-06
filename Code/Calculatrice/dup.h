#ifndef DUP_H
#define DUP_H

#include "unaryoperator.h"

class Dup: public UnaryOperator{
public:
    Dup(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // DUP_H
