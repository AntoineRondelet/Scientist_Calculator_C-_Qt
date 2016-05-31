#include "analyser.h"
#include <functional>
#include"entieranalyser.h"
#include "pile.h"
#include "operator.h"

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


//ESSAYER: Ici pour eviter la grande enumeration des operateurs dans la 2e regex -> on peut penser a stocker les operateurs deja defini dans un QVector, a itérer sur ce QVector -> stocker chaque QString contenue dans un truc comme stringstream, qu'on conveti en string pour construire la regex
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

/*
Litterale* createComplexe(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE COMPLEXE !! " << endl;
    QString re = matched_exp.captured("partRE");
    QString im = matched_exp.captured("partIM");
    Litterale* ptComplexe = new Complexe(im.toInt(), denom.toInt());
    if (ptRationnel ==  0) {
        CALCULATRICE_EXCEPTION("Erreur de construction du rationnel");
    }
    return ptRationnel;
}
*/


Litterale* createExpression(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE EXPRESSION !! " << endl;
    //QStringList words;
    QString matched = matched_exp.captured(0);
    Pile* stack = &Pile::getInstance();
    //stack->setMessage(mot);
    Litterale* ptExpression = new Expression(matched);
    if (ptExpression ==  0) {
        CALCULATRICE_EXCEPTION("Erreur de construction de l'expression");
    }
    return ptExpression;
}
/*
    QStringList words;
    QRegularExpression re("(?:'[^']+')");
    QRegularExpressionMatch str_match = re.match(QString::fromStdString("'3+4 SIN(3x+10)'"));
    if(str_match.hasMatch()) {
        words = str_match.capturedTexts();
    }
    while(words.empty() == false) {
       QString mot = words.takeFirst();
       cout << mot.toStdString() << endl;
    }
*/




//On initialise notre analyser (qui est un module du controleur -> composition)
void Analyser::init() {
    QString entier = "^-?[[:digit:]]+$";
    QString reel = "^(-?)[[:digit:]]*(\\.)([[:digit:]]*)$";
    QString rationnel = "^(?<numerateur>(-?)[[:digit:]]+)/(?<denominateur>(-?)[[:digit:]]+)$";
    QString atome = "^[A-Z]([A-Z0-9]*)$";
    //QString complexe = "^(?<partRE>[[:digit:]]+(([\.]|[\/])[[:digit:]]+)?)[\$](?<partIM>[[:digit:]]+(([\.]|[\/])[[:digit:]]+)?)$";


    m_matchers.insert(reel, createReel);
    m_matchers.insert(entier, createInteger);
    m_matchers.insert(rationnel, createRationnel);
    m_matchers.insert(atome, createAtome); //On fera un 2e traitement dans create atome pour ne pas créer un atome de meme nom qu'un operateur
    //m_matchers.insert(complexe, createComplexe); --> Faire la fonction de reconnaissance des complexes
    //m_matchers.insert("(?:'[^']+')", createExpression);
}


/*
    string c;
    cout<<"?-";
    getline(cin,c);
    QString str_in = QString::fromStdString(c);
    //cout << str_in.toStdString() << endl;
    QStringList liste_param = str_in.split(QRegularExpression("[[:space:]]+"));
    int i = 0;
    while(!liste_param.empty()) {
        QRegularExpression regex("^(?<numerateur>(-?)[[:digit:]]+)/(?<denominateur>(-?)[[:digit:]]+)$");
        QString act = liste_param.takeFirst();
        QRegularExpressionMatch str_match = regex.match(act);
        if(str_match.hasMatch()) {
            cout << "------- MATCHED --------" << endl;
            QString act2 = str_match.captured(0);
            cout << "Match " << i << ": " << act2.toStdString() << endl;
        }
        else
            cout << "Case " << i << ": " << act.toStdString() << endl;
        i++;
    }
*/


//On itère sur la map qui contient les regex et les fonctions de construction, et on renvoie le ptr sur l'objet construit, nullptr sinon
bool Analyser::reconnaitre(QStringList& src) {
    Pile* stack = &Pile::getInstance();
    bool construction = false; //variable drapeau qui atteste de la construction ou non d'un objet
    while(src.empty() == false) { //Tant que j'ai des Litterales a analyser
        QString mot = src.takeFirst(); //C'est ca qui fait avancer mon while !!
        QMap<QString, func_t>::iterator i;

        for (i = m_matchers.begin(); i != m_matchers.end(); ++i) { //On prend chaque "mot" de notre ligne de saisie et on le fais passer dans toutes nos regex
            QRegularExpression regex(i.key());
            func_t func = i.value();

            QRegularExpressionMatch str_match = regex.match(mot);
            if(str_match.hasMatch()) {
                //Si ca match -> on appelle la fonction pour le construire
                construction = true;
                Litterale* lit_a_empiler = func(str_match);
                stack->push(lit_a_empiler);
                break;
                /*if(lit_a_empiler != nullptr) {
                    stack->push(lit_a_empiler);
                    break; //On retrourne dans le while aussitot qu'on a trouvé le bon pattern -> on arrete de tester les regex sur le pattern deja trouvé
                }
                else {
                    stack->setMessage("Entrée inconnue");
                    return false;
                }*/
                /*
                Ici en disant qu'on compte le nombre d'empilement qu'on fait -> grace au for et a la QStringList, on pourra choisir de depiler les n operandes deja empilées ou choisir de les laisser -> demande a l'utilisateur + if/else avec une fonction de réempilement
                */
            }
            else {
                //Une partie de la littérale ne matche pas, ca peut etre un opérateur
                Operator *op = getOperateur(mot.toStdString());
                if(!op) {
                    //stack->setMessage("Entrée inconnue");
                    //return false;//on sort des 2 for, on stoppe l'analyse syntaxique -> Un truc ne va pas -> on renvoie false
                    continue;
                }
                else {
                    QVector<Litterale*> stockage_temp_litterales = op->chargerOperande();
                    if (stockage_temp_litterales.empty() == false){
                        //On execute l'operateur que si on a dépilé suffisament d'elements de la pile (donc si stockage_temp_litterales != nullptr)
                        op->execute(stockage_temp_litterales);
                        construction = true;
                        break;
                    }
                }
            }
        }
        if(construction == false) { //-> il n'a jamais été construit -> ne correspond a aucun pattern !
            return false;
        }
     }
    return true; //si on a pas retourné de false a la sortie du while => tout est bon
}

/*
string c;
cout<<"?-";
getline(cin,c);
QString str_in = QString::fromStdString(c);
cout << "------- MATCHED --------" << endl;
//cout << str_in.toStdString() << endl;
QStringList liste_param = str_in.split(QRegularExpression("[[:space:]]+"));
int i = 0;
while(!liste_param.empty()) {
    QString act = liste_param.takeFirst();
    cout << "Case " << i << ": " << act.toStdString() << endl;
    i++;
}
*/

/*
    QStringList words;
    QRegularExpression re("(?:'[^']+')");
    QRegularExpressionMatch str_match = re.match(QString::fromStdString("'3+4 SIN(3x+10)'"));
    if(str_match.hasMatch()) {
        words = str_match.capturedTexts();
    }
    while(words.empty() == false) {
       QString mot = words.takeFirst();
       cout << mot.toStdString() << endl;
    }
*/


//Utiliser le global matching pour analyser toutes une entrée et pour trouver les programmes a l'interieur des programmes etc

