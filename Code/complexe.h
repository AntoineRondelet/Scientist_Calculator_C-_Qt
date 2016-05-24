/*

#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "litteralenombre.h"
#include "litteralenum.h"
#include "calculatriceexception.h"


class Complexe: public LitteraleNombre{
private:
    //Les parties imaginaires peuvent etre des entiers, reels, ou, rationnels. Donc ce sont des LitteraleNum. Or, cette classe est abstraites, donc on en fait des pointeurs
    const LitteraleNum* partRe; //Les ptr doivent etre const, on ne doit pas pouvoir modifier les ref const a travers eux !
    const LitteraleNum* partIm;
public:
    //Complexe(const LitteraleNum& re, const LitteraleNum& im);
    Complexe(const LitteraleNombre& re, const LitteraleNombre& im);
    LitteraleNum getReelle() const {return *partRe;}
    LitteraleNum getImagin() const {return *partIm;}
    string toString() const;

// A FAIRE + Integrer la somme, sous etc avec les complexes aux autres classes
    LitteraleNombre& addition(const LitteraleNombre& lit) const;
    LitteraleNombre& soustraction(const LitteraleNombre& lit) const;
    LitteraleNombre& multiplication(const LitteraleNombre& lit) const;
    LitteraleNombre& division(const LitteraleNombre& lit) const;


    Complexe& operator=(const LitteraleNombre& lit);
    ~Complexe(){} //definir un constructeur puisque l'on a des pointeurs en attributs
};

inline Complexe& Complexe::operator=(const LitteraleNombre& lit) {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == 0) {
       throw CalculatriceException("ERREUR operator=(): Dynamic_cast vers entier impossible");
    }
    else {
     this->partIm = ptComplexe->partIm;
     this->partRe = ptComplexe->partRe;
     return *this;
    }
}

#endif // COMPLEXE_H


*/
