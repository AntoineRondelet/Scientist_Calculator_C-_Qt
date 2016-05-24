#ifndef LITTERALENUM_H
#define LITTERALENUM_H

#include "litteralenombre.h"

class LitteraleNum: public LitteraleNombre {
public:
    LitteraleNum(): LitteraleNombre(){}

    //Ici seuls les LitteraleNum doivent implemeter ces methodes
    /*virtual LitteraleNum& toEntier() const = 0;
    virtual LitteraleNum& toReel() const = 0;
    virtual LitteraleNum& toRationnel() const = 0;
    virtual LitteraleNum& toComplexe() const = 0;*/

    ~LitteraleNum(){}
};


#endif // LITTERALENUM_H
