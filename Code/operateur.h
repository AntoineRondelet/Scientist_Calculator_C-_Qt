
#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "litterale.h"
#include <QString>
#include <QMap>
#include <QMapIterator>

enum Op_type{PILE, NUMERIC, OTHER}; //PILE <-> operateur sur la pile, NUMERIC

class Operateur {
    string Opname;
    //Op_type type_operateur;
public:
    Operateur(const string& s): Opname(s){} //Obligé de passer une string ! c'est logique si on imagine une commande
    Litterale* executerOp() const;
};


#endif // OPERATEUR_H

