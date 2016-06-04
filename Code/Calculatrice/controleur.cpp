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
    bool match = analyser->reconnaitre(list_src);
    if(match == false) {
        //On a pas de litteraleNombre donc on teste si c'est un operateur
        //stack->setMessage("Controleur.cpp: Entrée Inconnue");
        // -- Ici on ne sauvegarde pas l'etat de la pile car il est inchangé -- //
    }
    else {
        // -- La commande s'est executée: On sauvegarde le changement -- //
        // -- On sauvegarde a chaque fois que match == true (on a produit de nouvelles littérales et on a donc modifié la pile) -- //
        PileCaretaker::getInstance().saveState(&Pile::getInstance());
    }
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







/*
void splitEntry(const string& c) {
    //QRegularExpression re1("(\\W+)"); --> matche ce qui n'est pas un mot
    QRegularExpression re("(\\w+)"); //--> matche ce qui est  un mot
    // Exemple : splitEntry("324 -765 + "); --> re1 matche: - et +, re2 matche: 324 et 765
    QRegularExpressionMatchIterator i = re.globalMatch(QString::fromStdString(c));
    QStringList words;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(1);
        cout << "word: " << word.toStdString() << endl;
        words << word;
    }
}

*/

