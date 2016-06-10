#ifndef IM_H
#define IM_H

#include "unaryoperator.h"


class Im: public UnaryOperator {
public:
    Im(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // IM_H
