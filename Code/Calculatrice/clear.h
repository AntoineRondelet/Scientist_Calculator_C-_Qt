#ifndef CLEAR_H
#define CLEAR_H

#include "operateurspecial.h"

class Clear:public OperateurSpecial{
public:
    Clear(): OperateurSpecial(){}
    void execute(QVector<Litterale*> litterals) const;
};

#endif // CLEAR_H
