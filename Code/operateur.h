
#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "litterale.h"
#include <QString>
#include <QMap>
#include <QMapIterator>



class Operateur {
    string Opname;
public:
    Operateur(const string& s): Opname(s){} //Obligé de passer une string ! c'est logique si on imagine une commande
    void executerOp() const;
    //bool isOperateur() const; --> On utilise la fonction adaptée de QMap

    /*
    ADD
    SOUS
    DIV
    MOD
    ...
    */
};


#endif // OPERATEUR_H

