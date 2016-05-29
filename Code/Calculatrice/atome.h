#ifndef ATOME_H
#define ATOME_H

#include "litterale.h"
#include <QString>


class Atome: public Litterale{
private:
    QString name;
public:
    Atome(const QString& s) : name(s) {} //car un atome à un nom composé de lettres majuscules
    string toString() const override;
    Atome* clone() const override;
};

inline Atome* Atome::clone() const {return new Atome(*this);}

#endif // ATOME_H
