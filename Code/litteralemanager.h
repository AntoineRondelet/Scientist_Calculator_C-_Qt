#ifndef LITTERALEMANAGER_H
#define LITTERALEMANAGER_H

#include "litterale.h"
#include "entier.h"
#include "reel.h"

class LitteraleManager {

    //Debut singleton
    LitteraleManager(const LitteraleManager& m){}
    LitteraleManager& operator=(const LitteraleManager& m){}
    ~LitteraleManager();


    class Handler {
    public:
        LitteraleManager* instance;
        Handler():instance(0){}
        ~Handler() {delete instance;}
    };

    static Handler handler;
    //Fin singleton

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


    void parcoursLitMan() const;

    void removeLitterale(Litterale& e);

    //Singleton
    static LitteraleManager& getInstance();
    static void libererInstance();
};


#endif // LITTERALEMANAGER_H
