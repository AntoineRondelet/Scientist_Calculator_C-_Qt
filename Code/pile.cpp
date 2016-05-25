#include "pile.h"
#include "calculatriceexception.h"



void Pile::agrandissementCapacite() {
    Item* newtab=new Item[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=tab_item[i];
    Item*  old=tab_item;
    tab_item=newtab;
    nbMax=(nbMax+1)*2;
    delete[] old;
}

void Pile::push(Litterale& e){
    if (nb==nbMax) agrandissementCapacite();
    tab_item[nb].setLitterale(e);
    nb++;
}


void Pile::pop(){
    nb--;
    tab_item[nb].raz();
}


void Pile::affiche() const{
    //system("clear"); //-> Probleme avec le terminal Qt et "cls"
    cout<<"********************************************* \n";
    cout<<"M : "<<message<<"\n";
    cout<<"---------------------------------------------\n";
    for(int i=nbAffiche; i>0; i--) {
        if (i<=static_cast<int>(nb)) cout<<i<<": "<<tab_item[nb-i].getLitterale().toString()<<"\n";
        else cout<<i<<": \n";
    }
    cout<<"---------------------------------------------\n";
}


Pile::~Pile(){
    delete[] tab_item;
}

Litterale& Pile::top() const {

    if (nb==0) throw CalculatriceException("Erreur Pile::top(): Aucune litterale sur la pile");
    return tab_item[nb-1].getLitterale();
}

//SINGLETON
Pile::Handler Pile::handler;

Pile& Pile::getInstance() {
    if(handler.instance == nullptr)
        handler.instance = new Pile;
    return *handler.instance;
}

void Pile::libererInstance() {
    delete handler.instance;
    handler.instance=nullptr;
}



