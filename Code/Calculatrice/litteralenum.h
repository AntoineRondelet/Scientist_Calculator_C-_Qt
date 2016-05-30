#ifndef LITTERALENUM_H
#define LITTERALENUM_H

#include "litteralenombre.h"
class Complexe; //On fait ca pour eviter les references croisées -> Ici, on dit que la classe Complexe existe -> mais on inclut pas
//son code car son code utilise la classe LitteraleNum etc -> On fait ceci pour résoudre ce problème

class LitteraleNum: public LitteraleNombre{
public:
    LitteraleNum(): LitteraleNombre(){}
    virtual LitteraleNum& operator=(const LitteraleNum& lit) = 0;
    virtual Complexe* toComplexe() const = 0;
};

#endif // LITTERALENUM_H
