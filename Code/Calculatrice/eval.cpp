#include "eval.h"
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include "controleur.h"

#include "expression.h"
#include "programme.h"


void Eval::execute(QVector<Litterale*> litterals) const {
    Expression* operande = dynamic_cast<Expression*>(litterals[0]);
    Programme* operandeProg = dynamic_cast<Programme*>(litterals[0]);

    Controleur& cont = Controleur::getInstance();

    if (operande!=nullptr){
        // -- L'expression s'evalue elle meme: En réalité la methode "eval" transforme l'expression pour la mettre au format comprit par la calculatrice (on permutte nos opérateurs dans la QStringList) -- //
        QStringList expAnalyse = operande->eval(operande);
        bool rep = cont.analyser->reconnaitre(expAnalyse);
        if(rep == false) {
            this->reChargerOperande(litterals);
            Pile::getInstance().setMessage("ERREUR: Evaluation de l'expression");
        }
        else {
            delete litterals[0];
        }
    }
    else if (operandeProg!=nullptr) {
        // -- L'expression s'evalue elle meme: En réalité la methode "eval" transforme l'expression pour la mettre au format comprit par la calculatrice (on permutte nos opérateurs dans la QStringList) -- //
        QStringList progAnalyse = operandeProg->eval(operandeProg);
        bool rep = cont.analyser->reconnaitre(progAnalyse);
        if(rep == false) {
            this->reChargerOperande(litterals);
            //progAnalyse.join("-")
            Pile::getInstance().setMessage(progAnalyse.join("-"));
            //Pile::getInstance().setMessage("ERREUR: Evaluation du programme");
        }
        else {
            delete litterals[0];
        }
    }
    else {
        this->reChargerOperande(litterals);
    }
}
