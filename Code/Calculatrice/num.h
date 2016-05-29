#ifndef NUM_H
#define NUM_H

#include "unaryoperator.h"

class Num: public UnaryOperator {
public:
    Num(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


#endif // NUM_H
