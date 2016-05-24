#ifndef LITTERALEMANAGER_H
#define LITTERALEMANAGER_H

#include "litterale.h"
#include "entier.h"
#include "reel.h"

class LitteraleManager {
    Litterale** tab_lits; //tableau de pointeurs de Litterales -> on les allouera dynamiquement
    unsigned int nb;
    unsigned int nbMax;
    void agrandissementCapacite();
public:
    LitteraleManager():tab_lits(0),nb(0),nbMax(0){}
    //LitteraleManager(const LitteraleManager& m);

    Litterale* addLitteraleEntiere(int v);
    Litterale* addLitteraleReelle(float v);
    Litterale* addLitteraleRationnelle(int num, int den);
    //Litterale& addLitterale(int v); --> A Faire

    void removeLitterale(Litterale& e);

    //LitteraleManager& operator=(const LitteraleManager& m);

    ~LitteraleManager();
};


#endif // LITTERALEMANAGER_H
