#ifndef RATIONNEL_H
#define RATIONNEL_H

#include <sstream>
#include "litteralenum.h"
#include "CalculatriceException.h"
#include "complexe.h"


using namespace std;

class Rationnel: public LitteraleNum { // On rompt l'heritage entre reel et rationnel
protected:
    int numerateur;
    int denominateur;
    void simplification();
public:
    Rationnel(int num=0, int den=1); //Rappel: les arguments par defaut sont juste dans le .h

    int getNumerateur() const {return numerateur;}
    int getDenominateur() const {return denominateur;}


    QString toString() const override;
    Rationnel* clone() const override;

    //Le fait d'implementer ces methodes -> pas besoin de faire les operator correspondants --> DP template method
    LitteraleNombre& addition(const LitteraleNombre& lit) const override;
    LitteraleNombre& soustraction(const LitteraleNombre& lit) const override;
    LitteraleNombre& multiplication(const LitteraleNombre& lit) const override;
    LitteraleNombre& division(const LitteraleNombre& lit) const override;
    LitteraleNombre& egal(const LitteraleNombre& n) const override;
    LitteraleNombre& inferieur(const LitteraleNombre& n) const override;
    LitteraleNombre& superieur(const LitteraleNombre& n) const override;


    Rationnel& operator=(const LitteraleNum& lit) override;

    Complexe* toComplexe() const override;
  };



 inline Rationnel& Rationnel::operator=(const LitteraleNum& lit) {
    const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
    if (ptRationnel == 0) {
        CALCULATRICE_EXCEPTION("ERREUR: dynamic_cast vers rationnel impossible");
    }
    else {
      this->numerateur = ptRationnel->numerateur;
      this->denominateur = ptRationnel->denominateur;
      return *this;
    }
}


inline Rationnel* Rationnel::clone() const {return new Rationnel(*this);}


#endif // RATIONNEL_H

