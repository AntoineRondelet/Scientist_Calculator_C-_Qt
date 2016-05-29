#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "litteralenombre.h"
#include "calculatriceexception.h"
#include "litteralenum.h"


class Complexe: public LitteraleNombre{
private:
    const LitteraleNum* partEnt; //Si on ne met pas les const ici et dans le constructeur on prive l'utilisateur de construire un complexe a partir de constantes par exemple
    const LitteraleNum* partIm;
public:
    Complexe(const LitteraleNombre& re, const LitteraleNombre& im);

    const LitteraleNum* getPartEnt() const {return partEnt;}
    const LitteraleNum* getPartIm() const {return partIm;}

    QString toString() const override;
    Complexe* clone() const override;

    // ------- Design Pattern: Template method -------- //
    LitteraleNombre& addition(const LitteraleNombre& lit) const override;
    LitteraleNombre& soustraction(const LitteraleNombre& lit) const override;
    LitteraleNombre& multiplication(const LitteraleNombre& lit) const override;
    LitteraleNombre& division(const LitteraleNombre& lit) const override;
};



#endif // COMPLEXE_H
