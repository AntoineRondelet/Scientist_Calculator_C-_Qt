#include "controleur.h"


#include "pile.h"
#include "calculatriceexception.h"
//#include "operator.h"
//#include "add.h"

#include <memory>

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QStringList>
#include <QRegularExpressionMatchIterator>


void Controleur::execute(const string& src)
{
    Litterale* number = analyser->reconnaitre(src);
    cout << "VOILA ::::: " << number->toString() << endl;
}

/*
void Controleur::commande(const string& c){
    Litterale* ptr_lit = nullptr;
    //Operator* ptr_op = nullptr;

    if ((ptr_lit = isEntier(c, *this)) != nullptr){
        pileAff.push(ptr_lit);
    }
    else {
        cout << "RIEN !" << endl;
    }
}*/
    /*else if ((ptr_lit = isReel(c, *this)) != nullptr){
        pileAff.push(ptr_lit);
    }
    else if ((ptr_lit = isRationnel(c, *this)) != nullptr){
        pileAff.push(ptr_lit);
    }*/
    /*else if ((ptr_op = getOperateur(c)) != nullptr) {
        LitteraleNombre** tab_lit = ptr_op->chargerOperande();
        ptr_lit = ptr_op->execute(tab_lit);
        ptr_op->empiler(*ptr_lit);
    }*/


    /*if (c == "ADD") {
                    Pile* ptr_stack = &Pile::getInstance();
                    LitteraleManager* ptr_lit_man = &LitteraleManager::getInstance();

                    // Ce qu'on pop de la pile c'est des Litterale --> Or, on veut pouvoir les sommer ici, donc il nous
                    // les faut convertir en LitteraleNombre
                    Litterale* v1 = ptr_stack->top();
                    cout << "V1: " << v1->toString() << endl;
                    ptr_stack->pop();
                    ptr_lit_man->removeLitterale(*ptr_stack->top());
                    ptr_stack->affiche();


                    Litterale* v2 = ptr_stack->top();
                    cout << "V2: " << v2->toString() << endl;
                    ptr_stack->pop();
                    ptr_lit_man->removeLitterale(*v2);
                    ptr_stack->affiche();


                    LitteraleNombre* nbrev1 = dynamic_cast<LitteraleNombre *>(v1);
                    if (nbrev1 == 0) {
                        cout << "pas un nombre" << endl;
                        ptr_stack->push(v1);
                        ptr_stack->push(v2);
                        return;
                    }

                    LitteraleNombre* nbrev2 = dynamic_cast<LitteraleNombre *>(v2);
                    if (nbrev2 == 0) {
                        cout << "pas un nombre" << endl;
                        ptr_stack->push(v1);
                        ptr_stack->push(v2);
                        return;
                    }

                    Litterale& res = (*nbrev1) + (*nbrev2); //On teste le type de res -> pour savoir quel objet construire


                    const Reel* ptReel = dynamic_cast<const Reel*>(&res);
                    if (ptReel == 0) {
                        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&res);
                            if (ptRationnel == 0) {
                                const Entier* ptEntier = dynamic_cast<const Entier*>(&res);
                                    if (ptEntier ==  0) throw CalculatriceException("ERREUR Operator.cpp: Dynamic_cast");
                                    else {
                                        Litterale* e = ptr_lit_man->addLitteraleEntiere(ptEntier->getValeur());
                                        ptr_stack->push(e);
                                    }
                            }
                            else {
                                Litterale* e = ptr_lit_man->addLitteraleRationnelle(ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
                                ptr_stack->push(e);
                            }
                    }
                    else {
                        Litterale* e = ptr_lit_man->addLitteraleReelle(ptReel->getValue());
                        ptr_stack->push(e);
                    }
                }

    else {
        cout << "RIEN !" << endl;
    }
}
        /*if (c == "ADD") {
                Pile* ptr_stack = &Pile::getInstance();
                LitteraleManager* ptr_lit_man = &LitteraleManager::getInstance();

                // Ce qu'on pop de la pile c'est des Litterale --> Or, on veut pouvoir les sommer ici, donc il nous
                // les faut convertir en LitteraleNombre
                Litterale& v1 = ptr_stack->top();
                cout << "V1: " << v1.toString() << endl;
                ptr_stack->pop();
                ptr_lit_man->removeLitterale(v1);
                ptr_stack->affiche();


                Litterale& v2 = ptr_stack->top();
                cout << "V2: " << v2.toString() << endl;
                ptr_stack->pop();
                ptr_lit_man->removeLitterale(v2);
                ptr_stack->affiche();


                LitteraleNombre* nbrev1 = dynamic_cast<LitteraleNombre *>(&v1);
                if (nbrev1 == 0) {
                    cout << "pas un nombre" << endl;
                    ptr_stack->push(v1);
                    ptr_stack->push(v2);
                    return;
                }

                LitteraleNombre* nbrev2 = dynamic_cast<LitteraleNombre *>(&v2);
                if (nbrev2 == 0) {
                    cout << "pas un nombre" << endl;
                    ptr_stack->push(v1);
                    ptr_stack->push(v2);
                    return;
                }

                Litterale& res = (*nbrev1) + (*nbrev2); //On teste le type de res -> pour savoir quel objet construire


                const Reel* ptReel = dynamic_cast<const Reel*>(&res);
                if (ptReel == 0) {
                    const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&res);
                        if (ptRationnel == 0) {
                            const Entier* ptEntier = dynamic_cast<const Entier*>(&res);
                                if (ptEntier ==  0) throw CalculatriceException("ERREUR Operator.cpp: Dynamic_cast");
                                else {
                                    Litterale* e = ptr_lit_man->addLitteraleEntiere(ptEntier->getValeur());
                                    ptr_stack->push(*e);
                                }
                        }
                        else {
                            Litterale* e = ptr_lit_man->addLitteraleRationnelle(ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
                            ptr_stack->push(*e);
                        }
                }
                else {
                    Litterale* e = ptr_lit_man->addLitteraleReelle(ptReel->getValue());
                    ptr_stack->push(*e);
                }
            }
*/



/*
void Controleur::executer(){
    string c; //Utiliser la commande suivante pour spliter une QSring et recuperer chaque terme: QString splitThis("Hello Marcus.-I am Stian.-Try this.-");QStringList splitted = splitThis.split("-");
    do {
        pileAff.affiche();
        cout<<"?-";
        cin>>c;
        if (c!="Q") commande(c);
    }while(c!="Q");
}
*/


// --------------- FONCTIONS DE PATTERN MATCHING --------------


/*
Entier* isEntier(const string& c, Controleur& cont) {
    QRegularExpression regexEntier("^-?[[:digit:]]+$");
    bool valid = regexEntier.isValid(); //On verifie si l'expression reg. est valide ou pas
    if (valid != true) CALCULATRICE_EXCEPTION("Regex non valide");

    QRegularExpressionMatch match = regexEntier.match(QString::fromStdString(c)); //permet de construire une QString a partir d'une std::string
    if (match.hasMatch()) {
        QString matched = match.captured(0);
        Entier* ptEntier = new Entier(matched.toInt());
        if (ptEntier ==  0) {
            CALCULATRICE_EXCEPTION("Erreur de construction de l'entier");
        }
        return ptEntier;
    }
    cout << "NO MATCH " << endl;
    return nullptr;
}
*/

/*
Note: ici, dans ces fonctions, on verifie a la fois le pattern, et on le construit. (Ci dessus, on verifie a la fois
si la saisie correpond a un entier (via les regex). Si oui alors on le construit. OR, la construction des litterales
est faite par le manager ! De ce fait, on appelle le manager (d'ou la fonction amie, car le manager est un attribut
du controleur) pour construire notre objet.) Le fait de retourner un ptr nous permet de fusionner en quelque sorte
un retour booléen et le retour d'un objet (en effet, on sait que si le retour est nullptr => isEntier est FAUX). De ce
fait, on repere et construit directement nos objets, on peut donc evaluer prograessivement l'expression
*/



/*
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

//Utiliser les smarts pointers. shared_ptr

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

*/

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

