#include "controleur.h"


#include "pile.h"
#include "pilecaretaker.h"
#include "calculatriceexception.h"
#include "operator.h"
#include "add.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QStringList>
#include <QRegularExpressionMatchIterator>



void Controleur::commande(QStringList& list_src)
{
    try{
        bool match = analyser->reconnaitre(list_src);
        if (match == true) // -- On a construit quelque chose: on sauvegarde -- //
            PileCaretaker::getInstance().saveState(&Pile::getInstance());
    }
    catch (CalculatriceException& e) {
        Pile::getInstance().setMessage(QString::fromStdString(e.getMsg()));
    }
    catch (...) {
        Pile::getInstance().setMessage("Sorry something went wrong");
    }

/*
    if(match == false) {
        //On a pas de litteraleNombre donc on teste si c'est un operateur
        //stack->setMessage("Controleur.cpp: Entrée Inconnue");
        // -- Ici on ne sauvegarde pas l'etat de la pile car il est inchangé -- //
    }
    else {
        // -- La commande s'est executée: On sauvegarde le changement -- //
        // -- On sauvegarde a chaque fois que match == true (on a produit de nouvelles littérales et on a donc modifié la pile) -- //
        PileCaretaker::getInstance().saveState(&Pile::getInstance());
    }*/
    /* A FAIRE
    else {
        ICI IL FAUT faire : On recompose une QString a partir de la QStringList splitée -> Et on affiche strEntree sur la QLineEdit (sujet p3)
        QString strEntree = str.join(" ");
    }*/
}




void Controleur::boucleExcecution(){
    string c;
    //Une sauvegarde de la pile vide
    PileCaretaker::getInstance().saveState(&Pile::getInstance());
    do {
        Pile::getInstance().affiche();
        cout<<"?-";
        getline(cin,c);
        QString str_in = QString::fromStdString(c);
        QStringList liste_param = str_in.split(QRegularExpression("[[:space:]]+"));
        if (c!="Q") commande(liste_param);
    } while(c!="Q");
}








// -- Singleton -- //

Controleur::Handler Controleur::handler;

Controleur& Controleur::getInstance() {
    if(handler.instance == nullptr)
        handler.instance = new Controleur;
    return *handler.instance;
}

void Controleur::libererInstance() {
    delete handler.instance;
    handler.instance=nullptr;
}


