#include "analyser.h"
#include <functional>
#include"entieranalyser.h"
#include "pile.h"
#include "operator.h"
#include "undo.h"
#include "redo.h"



// --- Fonctions qui construisent les litterales en fonction des match --- //

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

/*
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
*/


Litterale* createComplexe(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE COMPLEXE !! " << endl;
    QString re = matched_exp.captured("partRE");
    QString im = matched_exp.captured("partIM");
    //On fait tourner nos regex des entiers, reels et rationnels sur les parties RE et IM du complexe

    QRegularExpression entier("^-?[[:digit:]]+$");
    QRegularExpression reel("^(-?)[[:digit:]]*(\\.)([[:digit:]]*)$");
    QRegularExpression rationnel("^(?<numerateur>(-?)[[:digit:]]+)/(?<denominateur>(-?)[[:digit:]]+)$");

    LitteraleNombre* pEnt;
    LitteraleNombre* pIm;

    QRegularExpressionMatch str_match = entier.match(re);
    if(str_match.hasMatch()) {
        pEnt = new Entier(re.toInt());
    }
    str_match = entier.match(im);
    if(str_match.hasMatch()) {
        pIm = new Entier(im.toInt());
    }

    str_match = reel.match(re);
    if(str_match.hasMatch()) {
        pEnt = new Reel(re.toFloat());
    }
    str_match = reel.match(im);
    if(str_match.hasMatch()) {
        pIm = new Reel(im.toFloat());
    }

    str_match = rationnel.match(re);
    if(str_match.hasMatch()) {
        QStringList reRationnel = re.split(QRegularExpression("/"));
        QString numEnt = reRationnel.takeFirst();
        QString denEnt = reRationnel.takeFirst();
        pEnt = new Rationnel(numEnt.toInt(), denEnt.toInt());
    }
    str_match = rationnel.match(im);
    if(str_match.hasMatch()) {
        QStringList imRationnel = im.split(QRegularExpression("/"));
        QString numIm = imRationnel.takeFirst();
        QString denIm = imRationnel.takeFirst();
        pIm = new Rationnel(numIm.toInt(), denIm.toInt());
    }


    Litterale* ptComplexe = new Complexe(*pEnt, *pIm);
    if (ptComplexe ==  0) {
        CALCULATRICE_EXCEPTION("Erreur de construction du rationnel");
    }
    return ptComplexe;
}



// -- Les litterales expressions et programmes ne sont pas evaluées automatiquement, on les empile juste (sujet p3). D'ou les regex très simplistes -- //

Litterale* createExpression(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE EXPRESSION !! " << endl;
    QString matched = matched_exp.captured(0);
    Litterale* ptExpression = new Expression(matched);
    if (ptExpression ==  0) {
        CALCULATRICE_EXCEPTION("Erreur de construction de l'expression");
    }
    return ptExpression;
}

Litterale* createProgramme(QRegularExpressionMatch matched_exp) {
    cout << "ON EST DANS CREATE Programme !! " << endl;
    QString matched = matched_exp.captured(0);
    Litterale* ptProgramme = new Programme(matched);
    if (ptProgramme ==  0) {
        CALCULATRICE_EXCEPTION("Erreur de construction du Programme");
    }
    return ptProgramme;
}





// --- Fonction: Initialisation de l'analyseur avec les regex et fonctions de construction --- //

void Analyser::init() {
    QString entier = "^-?[[:digit:]]+$";
    QString reel = "^(-?)[[:digit:]]*(\\.)([[:digit:]]*)$";
    QString rationnel = "^(?<numerateur>(-?)[[:digit:]]+)/(?<denominateur>(-?)[[:digit:]]+)$";
    //QString atome = "^[A-Z]([A-Z0-9]*)$";
    QString complexe = "^(?<partRE>[[:digit:]]+(([\\.]|[\\/])[[:digit:]]+)?)[\\$](?<partIM>[[:digit:]]+(([\\.]|[\\/])[[:digit:]]+)?)$";
    QString expression = "(?:'[^']+')";
    QString programme = "\\[(.)*\\]";

    m_matchers.insert(reel, createReel);
    m_matchers.insert(entier, createInteger);
    m_matchers.insert(rationnel, createRationnel);
    //m_matchers.insert(atome, createAtome); //On fera un 2e traitement dans create atome pour ne pas créer un atome de meme nom qu'un operateur
    m_matchers.insert(complexe, createComplexe); //--> Faire la fonction de reconnaissance des complexes
    m_matchers.insert(expression, createExpression);
    m_matchers.insert(programme, createProgramme);
}


// --- On itère sur la QStringList. On construit l'objet reconnu, rien sinon --- //

bool Analyser::reconnaitre(QStringList& src) {
    //Pile* stack = &Pile::getInstance();
    //Variable drapeau: Construction d'objet ou pas
    bool construction = false;
    //Variable compteur de crochets: Programme avec le bon nombre de crochets ou pas
    int counterCrochet = 0;

    //Tant que j'ai des litterales dans la QStringList (donc à analyser)
    while(src.empty() == false) {

        QString mot = src.takeFirst();

        // --- Reconstruction des expressions splitées (Si espace lors de la saisie) --- //
        if (mot.left(1) == "'") {
            //Si on trouve (') seul: On a une expression qui a étée splitée (l'utilisateur l'a entrée avec un espace)
            if (mot.right(1) != "'" || mot.size() <= 1){
                QString finExp = "";
                //Tant qu'il reste des String et qu'on a pas refermé l'expression ((') manquant à la fin)
                while (!src.empty() && (mot.right(1) != "'")){
                    finExp = src.takeFirst();
                    //On concatène notre expression sans espaces dans mot
                    mot += finExp;
                }
            }
            //On sort du while car src.empty() == true mais le (') de fin n'a pas été trouvé
            if (mot.right(1) != "'") {
                Pile::getInstance().setMessage("Attention, caractere de fin d'expression manquant: (') ");
                //On ne construit rien, on sort
                return false;
            }
        }

        // --- Reconstruction des programmes splités (forcement car espace entre chaque opérande) --- //
        if (mot == "[") {
            counterCrochet++;
            QString finProg = "";
            while (!src.empty() && counterCrochet !=0){ //Si counterCrochet != 0 -> on a pas fini de lire le programme
                finProg = src.takeFirst();
                if (finProg == "[") counterCrochet++;
                if (finProg == "]") counterCrochet--;
                //On doit conserver l'espace de séparation entre chaque operande
                mot += " " + finProg;
            }
            //On est sorti du while car src.empty() == true. Mais il manque des crochets
            if(counterCrochet != 0) {
                Pile::getInstance().setMessage("Attention, crochet(s) manquant(s) : ']' ");
                return false;
            }
        }


        // --- Apres avoir réassemblé les expressions et les programmes, on analyse les entrées de l'utilisateur --- //
        QMap<QString, func_t>::iterator i;
        //On prend chaque opérande saisie par l'utilisateur et on le fait passer par toutes les regex
        for (i = m_matchers.begin(); i != m_matchers.end(); ++i) {
            QRegularExpression regex(i.key());
            func_t func = i.value();

            QRegularExpressionMatch str_match = regex.match(mot);
            if(str_match.hasMatch()) {
                //Si un pattern match avec une regex: On appelle la fonction pour le construire
                construction = true;
                Litterale* lit_a_empiler = func(str_match);
                Pile::getInstance().push(lit_a_empiler);
                //On a construit notre objet, on sort et on analyse l'opérande suivante
                break;
            }
            else { //Aucune litterale n'a matchée
                //Si aucune littérale ne match, ca peut etre un opérateur
                Operator *op = getOperateur(mot.toStdString());
                if (op) {
                    Undo* undoTest = dynamic_cast<Undo*>(op);
                    Redo* redoTest = dynamic_cast<Redo*>(op);
                    if (undoTest != nullptr) {
                        //On a un operateur Undo, on l'execute
                        QVector<Litterale*> vide;
                        undoTest->execute(vide);
                        construction = false; // -- Comme ca on ne fait pas de sauvegarde apres un UNDO (c'est pas le but) -- //
                        break;
                    }
                    else if (redoTest != nullptr) {
                        //On a un operateur Undo, on l'execute
                        QVector<Litterale*> vide;
                        redoTest->execute(vide);
                        construction = false; // -- Comme ca on ne fait pas de sauvegarde apres un REDO (c'est pas le but) -- //
                        break;
                    }
                    else {
                        QVector<Litterale*> stockage_temp_litterales = op->chargerOperande();
                        if (stockage_temp_litterales.empty() == false){
                            //On execute l'operateur que si on a dépilé suffisament d'elements de la pile
                            op->execute(stockage_temp_litterales);
                            construction = true;
                            break;
                        }
                    }
                }
            }
        }
        //On a rien construit: Donc on a entré quelque chose d'inconnu
        if(construction == false)
            return false;
     }
    //Tout est bon, on retourne true pour l'indiquer
    return true;
}
