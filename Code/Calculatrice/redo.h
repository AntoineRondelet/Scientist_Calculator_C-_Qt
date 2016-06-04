#ifndef REDO_H
#define REDO_H

#include "operator.h"

// -- Operateur spécial: On choisit de les faire heriter direct de la classe Operateur -- //

class Redo: public Operator {
public:
    Redo(): Operator(){}
    QVector<Litterale*> chargerOperande() const{return QVector<Litterale*>();}
    void reChargerOperande(QVector<Litterale*> litterals) const{}
    void execute(QVector<Litterale*> litterals) const;
};


#endif // REDO_H
