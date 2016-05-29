#include "analyser.h"
#include <functional>
#include"entieranalyser.h"

//Les fonctions qui construisent les objets apres que les regex aient matchées

Litterale* createInteger(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE INTEGER!! " << endl;
    QString matched = matched_exp.captured(0);
    Litterale* ptEntier = new Entier(matched.toInt());
    if (ptEntier ==  0) {
        CALCULATRICE_EXCEPTION("Erreur de construction de l'entier");
    }
    return ptEntier;
}


Litterale* createRationnel(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE RATIONNEL !! " << endl;
    QString numer = matched_exp.captured("numerateur");
    QString denom = matched_exp.captured("denominateur");
    Litterale* ptRationnel = new Rationnel(numer.toInt(), denom.toInt());
    if (ptRationnel ==  0) {
        CALCULATRICE_EXCEPTION("Erreur de construction du rationnel");
    }
    return ptRationnel;
}


Litterale* createReel(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE REEL !! " << endl;
    QString matched = matched_exp.captured(0);
    Litterale* ptReel = new Reel(matched.toFloat());
    if (ptReel ==  0) {
        CALCULATRICE_EXCEPTION("Erreur de construction du reel");
    }
    return ptReel;
}


Litterale* createAtome(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE ATOME !! " << endl;
    QString matched = matched_exp.captured(0);
    //on refait tourner une regex pour s'assurer que l'atome n'a pas le nom d'un programme deja existant
    QRegularExpression regexOperateur("NEG|NUM|DEN|DIV|MOD|RE|IM|ARG|NORM|AND|OR|NOT|DUP|DROP|UNDO|REDO"); //C'est pas tres propre ! il faudrait trouver un moyen de faire cela de facon plus propre
    QRegularExpressionMatch str_match_op = regexOperateur.match(matched);
    if(str_match_op.hasMatch()) {
        return nullptr; //on veut creer un atome qui a le meme identificateur qu'un programme
    }
    else {
        Litterale* ptAtome = new Atome(matched);
        if (ptAtome ==  0) {
            CALCULATRICE_EXCEPTION("Erreur de construction de l'atome");
        }
        return ptAtome;
    }
}




//On initialise notre analyser (qui est un module du controleur -> composition)
void Analyser::init() {
    m_matchers.insert("^-?[[:digit:]]+$", createInteger);
    m_matchers.insert("^(?<numerateur>(-?)[[:digit:]]+)/(?<denominateur>(-?)[[:digit:]]+)$", createRationnel);
    m_matchers.insert("^(-?)[[:digit:]]*(\\\.)([[:digit:]]*)$", createReel);
    m_matchers.insert("^[A-Z]([A-Z0-9]*)$", createAtome); //On fera un 2e traitement dans create atome pour ne pas créer un atome de meme nom qu'un operateur
}



//On itère sur la map qui contient les regex et les fonctions de construction, et on renvoie le ptr sur l'objet construit, nullptr sinon
Litterale* Analyser::reconnaitre(const string& src)
{
    QMap<QString, func_t>::iterator i;
    for (i = m_matchers.begin(); i != m_matchers.end(); ++i) {
        QRegularExpression regex(i.key());
        func_t func = i.value();

        QRegularExpressionMatch str_match = regex.match(QString::fromStdString(src));
        if(str_match.hasMatch()) {
            return func(str_match);
        }
    }
    return nullptr;
}


//Utiliser le global matching pour analyser toutes une entrée et pour trouver les programmes a l'interieur des programmes etc

