#include "controleur.h"
#include "litteralemanager.h"
#include "pile.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QStringList>
#include <QRegularExpressionMatchIterator>



void Controleur::commande(const string& c){
    Litterale* ptr = nullptr;
    if ((ptr = isEntier(c, *this)) != nullptr){
        pileAff.push(*ptr);
    }
    else if ((ptr = isReel(c, *this)) != nullptr){
        pileAff.push(*ptr);
    }
    else if ((ptr = isRationnel(c, *this)) != nullptr){
        pileAff.push(*ptr);
    }
    /*}else{
        if (estUnOperateur(c)){
            if (pileAff.taille()>=2) {
                int v2=pileAff.top().getValue();
                litManag.removeLitterale(pileAff.top());
                pileAff.pop();
                int v1=pileAff.top().getValue();
                litManag.removeLitterale(pileAff.top());
                pileAff.pop();

                int res;
                if (c=="+") res=v1+v2;
                if (c=="-") res=v1-v2;
                if (c=="*") res=v1*v2;
                if (c=="/") {
                    if (v2!=0) 	res=v1/v2;
                    else{
                        pileAff.setMessage("Erreur : division par zero");
                        // restauration de la pile
                        pileAff.push(litManag.addLitterale(v1));
                        res=v2;
                    }
                }
                Litterale& e=litManag.addLitterale(res);
                pileAff.push(e);
            }else{
                pileAff.setMessage("Erreur : pas assez d'arguments");
            }
        }else pileAff.setMessage("Erreur : commande inconnue");*/
}



void Controleur::executer(){
    string c; //Utiliser la commande suivante pour spliter une QSring et recuperer chaque terme: QString splitThis("Hello Marcus.-I am Stian.-Try this.-");QStringList splitted = splitThis.split("-");
    do {
        pileAff.affiche();
        cout<<"?-";
        cin>>c;
        if (c!="Q") commande(c);
    }while(c!="Q");
}



// --------------- FONCTIONS DE PATTERN MATCHING --------------


Entier* isEntier(const string& c, Controleur& cont) {
    QRegularExpression regexEntier("^-?[[:digit:]]+$");
    bool valid = regexEntier.isValid(); //On verifie si l'expression reg. est valide ou pas
    if (valid == true) cout << "Oui: valide" << endl;
    else cout << "Non valide" << endl;

    QRegularExpressionMatch match = regexEntier.match(QString::fromStdString(c)); //permet de construire une QString a partir d'une std::string
    if (match.hasMatch()) {
        QString matched = match.captured(0);
        Entier* ptEntier = dynamic_cast<Entier*>(cont.litManag.addLitteraleEntiere(matched.toInt())); //On converti notre QString qui a matché en Int pour construire tout de suite notre entier en pouvoir l'empiler
        if (ptEntier ==  0) {
            throw CalculatriceException("ERREUR controleur: Dynamic_cast");
        }
        return ptEntier;
    }
    cout << "NO MATCH " << endl;
    return nullptr;
}

/*
Note: ici, dans ces fonctions, on verifie a la fois le pattern, et on le construit. (Ci dessus, on verifie a la fois
si la saisie correpond a un entier (via les regex). Si oui alors on le construit. OR, la construction des litterales
est faite par le manager ! De ce fait, on appelle le manager (d'ou la fonction amie, car le manager est un attribut
du controleur) pour construire notre objet.) Le fait de retourner un ptr nous permet de fusionner en quelque sorte
un retour booléen et le retour d'un objet (en effet, on sait que si le retour est nullptr => isEntier est FAUX). De ce
fait, on repere et construit directement nos objets, on peut donc evaluer prograessivement l'expression
*/



Reel* isReel(const string& c, Controleur& cont) {
    QRegularExpression regexReel("^(-?)[[:digit:]]*(\\\.)?([[:digit:]]*)$");
    bool valid = regexReel.isValid();
    if (valid == true) cout << "Oui: valide" << endl;
    else cout << "Non valide" << endl;

    QRegularExpressionMatch match = regexReel.match(QString::fromStdString(c));
    if (match.hasMatch()) {
        QString matched = match.captured(0);
        Reel* ptReel = dynamic_cast<Reel*>(cont.litManag.addLitteraleReelle(matched.toFloat()));
        if (ptReel ==  0) {
            throw CalculatriceException("ERREUR controleur: Dynamic_cast Reel");
        }
        return ptReel;
    }
    cout << "NO MATCH " << endl;
    return nullptr;
}


Rationnel* isRationnel(const string& c, Controleur& cont) {
    QRegularExpression regexRationnel("^(?<numerateur>(-?)[[:digit:]]+)/(?<denominateur>(-?)[[:digit:]]+)$");
    bool valid = regexRationnel.isValid();
    if (valid == true) cout << "Oui: valide" << endl;
    else cout << "Non valide" << endl;

    QRegularExpressionMatch match = regexRationnel.match(QString::fromStdString(c));
    if (match.hasMatch()) {
        //Ici, on récupère, si on trouve le pattern d'un rationnel, le numerateur et le denominateur pour construire facilement notre rationnel qu'on empilera ensuite
        QString numer = match.captured("numerateur");
        QString denom = match.captured("denominateur");
        Rationnel* ptRationnel = dynamic_cast<Rationnel*>(cont.litManag.addLitteraleRationnelle(numer.toInt(), denom.toInt()));
        if (ptRationnel ==  0) {
            throw CalculatriceException("ERREUR controleur: Dynamic_cast Rationnel");
        }
        return ptRationnel;
    }
    cout << "NO MATCH " << endl;
    return nullptr;
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

