#ifndef REEL_H
#define REEL_H

#include <string>
#include <iostream>
#include <sstream>
#include "litteralenum.h"
#include "CalculatriceException.h"
#include "complexe.h"

using namespace std;

class Reel: public LitteraleNum{
private:
  float value;
public:
  Reel(float v=0): LitteraleNum(), value(v){}

  float getValue() const {return value;}

  QString toString() const override;
  Reel* clone() const override;

  //Le fat d'implementer ces methodes -> pas besoin de faire les operator correspondants --> DP template method
  LitteraleNombre& addition(const LitteraleNombre& lit) const override;
  LitteraleNombre& soustraction(const LitteraleNombre& lit) const override;
  LitteraleNombre& multiplication(const LitteraleNombre& lit) const override;
  LitteraleNombre& division(const LitteraleNombre& lit) const override;
  LitteraleNombre& egal(const LitteraleNombre& n) const override;
  LitteraleNombre& inferieur(const LitteraleNombre& n) const override;
  LitteraleNombre& superieur(const LitteraleNombre& n) const override;

  Reel& operator=(const LitteraleNum& lit) override;

  Complexe* toComplexe() const override;
};

inline Reel& Reel::operator=(const LitteraleNum& lit) {
  const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
  if (ptReel == 0) {
      CALCULATRICE_EXCEPTION("ERREUR operator=(): Dynamic_cast vers reel impossible");
  }
  else {
    this->value = ptReel->value;
    return *this;
  }
}

inline Reel* Reel::clone() const {return new Reel(*this);}


#endif // REEL_H

