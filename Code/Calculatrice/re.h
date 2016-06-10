#ifndef RE_H
#define RE_H

#include "unaryoperator.h"


class Re: public UnaryOperator {
public:
    Re(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};

#endif // RE_H
