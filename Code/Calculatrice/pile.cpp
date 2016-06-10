#include "pile.h"
#include "calculatriceexception.h"


void Pile::affiche() const{
    //system("clear"); //-> Probleme avec le terminal Qt et "cls"
    cout<<"********************************************* \n";
    cout<<"M : "<<message.toStdString()<<"\n";
    cout<<"---------------------------------------------\n";
    for(int i=nbAffiche; i>0; i--) {
        //A changer ! ici on affiche des std::string -> il faudra supprimer le .toStdString() et affciher des QString dans l'appli
        if (i<= this->size()) cout<<i<<": "<<this->value(this->size()-i)->toString().toStdString()<<"\n";
        else cout<<i<<": \n";
    }
    cout<<"---------------------------------------------\n";
}


//QVector<Litterale*> argsHistory;
//QString lastOpname = "";

// -- Singleton -- //

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


// -- Memento -- //

Pile* Pile::clone() const {
    Pile* pClone = new Pile();
    QStack<Litterale*>::iterator it;
    Litterale* litte = nullptr;
    for (it = Pile::getInstance().begin(); it != Pile::getInstance().end(); ++it){
        litte = *it;
        // -- On push dans la nouvelle pile LE CLONE de chaque litterale de la pile actuelle. -- //
        pClone->push(litte->clone());
    }
    return pClone;
}


// -- Pour la sauvegarde XML -- //

void Pile::saveData() const {

}


void restoreData() {

}



