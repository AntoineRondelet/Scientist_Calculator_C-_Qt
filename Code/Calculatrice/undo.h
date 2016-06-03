#ifndef UNDO_H
#define UNDO_H

#include "operator.h"


// -- Operateur spécial: On choisit de les faire heriter direct de la classe Operateur -- //

class Undo: public Operator {
public:
    Undo(): Operator(){}
    QVector<Litterale*> chargerOperande() const{return QVector<Litterale*>();}
    void reChargerOperande(QVector<Litterale*> litterals) const{}
    void execute(QVector<Litterale*> litterals) const;
};

#endif // UNDO_H

