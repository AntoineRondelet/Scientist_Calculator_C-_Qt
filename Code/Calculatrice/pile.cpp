#include "pile.h"
#include "calculatriceexception.h"


void Pile::affiche() const{
    //system("clear"); //-> Probleme avec le terminal Qt et "cls"
    cout<<"********************************************* \n";
    cout<<"M : "<<message.toStdString()<<"\n";
    cout<<"---------------------------------------------\n";
    for(int i=nbAffiche; i>0; i--) {
        if (i<= this->size()) cout<<i<<": "<<this->value(this->size()-i)->toString()<<"\n";
        else cout<<i<<": \n";
    }
    cout<<"---------------------------------------------\n";
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



