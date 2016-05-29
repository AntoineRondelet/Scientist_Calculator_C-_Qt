#ifndef LITTERALENUM_H
#define LITTERALENUM_H

#include "litteralenombre.h"


class LitteraleNum: public LitteraleNombre{
public:
    LitteraleNum(): LitteraleNombre(){}
    virtual LitteraleNum& operator=(const LitteraleNum& lit) = 0;
};

#endif // LITTERALENUM_H
