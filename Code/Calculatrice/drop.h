#ifndef DROP_H
#define DROP_H

#include "unaryoperator.h"

class Drop: public UnaryOperator{
public:
    Drop(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // DROP_H
