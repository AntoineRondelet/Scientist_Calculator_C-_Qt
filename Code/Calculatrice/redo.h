#ifndef REDO_H
#define REDO_H

#include "operateurspecial.h"

// -- Operateur spécial: On choisit de les faire heriter direct de la classe Operateur -- //

class Redo: public OperateurSpecial {
public:
    Redo(): OperateurSpecial(){}
    void execute(QVector<Litterale*> litterals) const;
};


#endif // REDO_H
