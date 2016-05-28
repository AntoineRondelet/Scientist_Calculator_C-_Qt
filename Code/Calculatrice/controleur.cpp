#include "controleur.h"


#include "pile.h"
#include "calculatriceexception.h"
#include "operator.h"
#include "add.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QStringList>
#include <QRegularExpressionMatchIterator>



void Controleur::commande(const string& src)
{
    Litterale* number = analyser->reconnaitre(src);
    if(number == nullptr) { //On a pas de litteraleNombre donc on teste si c'est un operateur
        Operator *op = getOperateur(src);
        if(!op) {
            pileAff.setMessage("Entrée inconnue");
        }
        else {
            QVector<Litterale*> stockage_temp_litterales = op->chargerOperande();
            if (stockage_temp_litterales.empty() == false){
            //On execute l'operateur que si on a dépilé suffisament d'elements de la pile (donc si stockage_temp_litterales != nullptr)
                Litterale* resultat = op->execute(stockage_temp_litterales);
                pileAff.push(resultat);
            }
        }
    }
    else {
        pileAff.push(number);
    }
}




void Controleur::boucleExcecution(){
    string c; //Utiliser la commande suivante pour spliter une QSring et recuperer chaque terme: QString splitThis("Hello Marcus.-I am Stian.-Try this.-");QStringList splitted = splitThis.split("-");
    do {
        //pileAff.setMessage(""); //On remet le message a zero a chaque iteration
        pileAff.affiche();
        cout<<"?-";
        cin>>c;
        if (c!="Q") commande(c);
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

