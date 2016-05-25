#include "litterale.h"
#include "litteralemanager.h"
#include "calculatriceexception.h"
#include <string>

using namespace std;

void LitteraleManager::agrandissementCapacite() {
    Litterale** newtab=new Litterale*[(nbMax+1)*2];
    //for(unsigned int i=0; i<nb; i++) newtab[i]=tab_lits[i];
    memcpy(newtab,tab_lits,nb*sizeof(Litterale*)); //On utilise une fonction de la std pour faire la recopie
    Litterale**  old=tab_lits;
    tab_lits=newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}


//Constructeur de recopie
/*
LitteraleManager::LitteraleManager(const LitteraleManager& m):
    tab_lits(new Litterale*[m.nbMax]), nb(m.nb), nbMax(m.nbMax)
{
    for(unsigned int i=0; i<nb; i++)
        tab_lits[i]=new Litterale(*m.tab_lits[i]);
}
*/

/*
Litterale* LitteraleManager::addLitterale(int v){
    if (nb==nbMax) agrandissementCapacite();
    tab_lits[nb++]=new Entier(v);
    return tab_lits[nb-1];
}
*/


Litterale* LitteraleManager::addLitteraleEntiere(int v){
    if (nb==nbMax) agrandissementCapacite();
    tab_lits[nb++]=new Entier(v);
    return tab_lits[nb-1];
}

Litterale* LitteraleManager::addLitteraleReelle(float v) {
    if (nb==nbMax) agrandissementCapacite();
    tab_lits[nb++]=new Reel(v);
    return tab_lits[nb-1];
}


Litterale* LitteraleManager::addLitteraleRationnelle(int num, int den) {
    if (nb==nbMax) agrandissementCapacite();
    tab_lits[nb++]=new Rationnel(num, den);
    return tab_lits[nb-1];
}

/*
Litterale& LitteraleManager::addLitterale(const string& s){
    on passe une string, et, en focntion de sa forme -> regex, on appelera la fonction
    addLitteraleEntiere ou addLitteraleType correspondante
}
*/

void LitteraleManager::removeLitterale(Litterale& e){
    unsigned int i=0;
    while(i<nb && tab_lits[i]!=&e) i++;
    if (i==nb) throw CalculatriceException("Erreur LitteraleManager: Elimination d'une Litterale inexistante");
    delete tab_lits[i];
    i++;
    while(i<nb) { tab_lits[i-1]=tab_lits[i]; i++; } //On fait un "decalage" apres la suppression
    nb--;
}


void LitteraleManager::parcoursLitMan() const {
    unsigned int i=0;
    while(i<nb) {
        cout << tab_lits[i] << endl;
        i++;
    }
}


LitteraleManager::~LitteraleManager(){
    for(unsigned int i=0; i<nb; i++) delete tab_lits[i]; //car on a alloué dynamiquement nos Litterales
    delete[] tab_lits;
}

//operateur de recopie
/*
LitteraleManager& LitteraleManager::operator=(const LitteraleManager& m){
    if (this==&m) return *this;
    Litterale** newtab=new Litterale*[m.nbMax];
    for(unsigned int i=0; i<nb; i++)
        newtab[i]=new Litterale(*m.tab_lits[i]);
    Litterale** old=tab_lits;
    unsigned int oldnb=nb;
    tab_lits=newtab;
    nb=m.nb;
    nbMax=m.nbMax;
    for(unsigned int i=0; i<oldnb; i++) delete old[i];
    delete[] old;
    return *this;
}
*/


//SINGLETON
LitteraleManager::Handler LitteraleManager::handler;

LitteraleManager& LitteraleManager::getInstance() {
    if(handler.instance == nullptr)
        handler.instance = new LitteraleManager;
    return *handler.instance;
}

void LitteraleManager::libererInstance() {
    delete handler.instance;
    handler.instance=nullptr;
}
