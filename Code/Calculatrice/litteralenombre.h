#ifndef LitteraleNombre_H
#define LitteraleNombre_H

#include <string>
#include <iostream>
#include "litterale.h"

class Entier;

using namespace std;

//Cette classe n'a pas d'attributs, mais on la fait quand meme au cas ou, plus tard, on veut ajouter une caracteristique a toutes nos LitteraleNombres
class LitteraleNombre: public Litterale {
public:
    LitteraleNombre(): Litterale(){}

    //virtual string toString() const = 0; -> au niveau de Litterale

    //Ici ce sont des LitteraleNombres car les complexes qui ne sont pas des LitteraleNombresNum doivent aussi supporter ces opérations
    virtual LitteraleNombre& addition(const LitteraleNombre& litNum) const = 0;
    virtual LitteraleNombre& soustraction(const LitteraleNombre& n) const = 0;
    virtual LitteraleNombre& multiplication(const LitteraleNombre& n) const = 0;
    virtual LitteraleNombre& division(const LitteraleNombre& n) const = 0;
    virtual bool egal(const LitteraleNombre& n) const = 0;
    virtual bool inferieur(const LitteraleNombre& n) const = 0;
    virtual bool superieur(const LitteraleNombre& n) const = 0;


    LitteraleNombre& operator+(const LitteraleNombre& n){return this->addition(n);}
    LitteraleNombre& operator-(const LitteraleNombre& n){return this->soustraction(n);}
    LitteraleNombre& operator*(const LitteraleNombre& n){return this->multiplication(n);}
    LitteraleNombre& operator/(const LitteraleNombre& n){return this->division(n);}

    //virtual ~LitteraleNombre(){} //Destructeur virtuel --> Heritage
};

#endif // LitteraleNombre_H
