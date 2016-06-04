#ifndef UNDO_H
#define UNDO_H

#include "operateurspecial.h"


// -- Operateur spécial: On choisit de les faire heriter direct de la classe Operateur -- //

class Undo: public OperateurSpecial {
public:
    Undo(): OperateurSpecial(){}
    void execute(QVector<Litterale*> litterals) const;
};


#endif // UNDO_H

