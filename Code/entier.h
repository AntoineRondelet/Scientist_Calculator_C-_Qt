#ifndef ENTIER_H
#define ENTIER_H

#include "rationnel.h"


class Entier: public Rationnel{ //On choisit de garder l'heritage Rationnel et Entier
private:
    int valeur;
public:
    Entier(int val=0): Rationnel(val, 1), valeur(val){}
    int getValeur() const {return valeur;}

    string toString() const override;

    LitteraleNombre& addition(const LitteraleNombre& lit) const override;
    LitteraleNombre& soustraction(const LitteraleNombre& lit) const override;
    LitteraleNombre& multiplication(const LitteraleNombre& lit) const override;
    LitteraleNombre& division(const LitteraleNombre& lit) const override;

    Entier& operator=(const LitteraleNombre& lit) override;
};

inline Entier& Entier::operator=(const LitteraleNombre& lit) {
   const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
   if (ptEntier == 0) {
       throw CalculatriceException("ERREUR operator=(): Dynamic_cast vers entier impossible");
   }
   else {
     this->valeur = ptEntier->valeur;
     return *this;
   }
 }


#endif // ENTIER_H
