#include "controleur.h"


#include "pile.h"
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
    if(match == false) { //On a pas de litteraleNombre donc on teste si c'est un operateur
        pileAff.setMessage("Controleur.cpp: Entrée Inconnue");
    }
    //ou sinon faire une fonction de recuperation qui prend en parametre un int (renoyé par econnaitre, qui indique la position dans la QStringList du mot qui a pa sété reconnu de telle maniere a l'indiquer -> si 0 aors tout a été reconnu
}




void Controleur::boucleExcecution(){
    string c; //Utiliser la commande suivante pour spliter une QSring et recuperer chaque terme: QString splitThis("Hello Marcus.-I am Stian.-Try this.-");QStringList splitted = splitThis.split("-");
    do {
        //pileAff.setMessage(""); //On remet le message a zero a chaque iteration
        pileAff.affiche();
        cout<<"?-";
        getline(cin,c);
        QString str_in = QString::fromStdString(c);
        QStringList liste_param = str_in.split(QRegularExpression("[[:space:]]+"));
        if (c!="Q") commande(liste_param);
    }while(c!="Q");
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

