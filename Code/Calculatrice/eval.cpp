#include "eval.h"
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include "controleur.h"

#include "expression.h"


void Eval::execute(QVector<Litterale*> litterals) const {
    Expression* operande = dynamic_cast<Expression *>(litterals[0]);
    if (operande!=nullptr){
        Controleur& cont = Controleur::getInstance();
        // -- L'expression s'evalue elle meme: En réalité la methode "eval" transforme l'expression pour la mettre au format comprit par la calculatrice (on permutte nos opérateurs dans la QStringList) -- //
        QStringList expAnalyse = operande->eval(operande);
        bool rep = cont.analyser->reconnaitre(expAnalyse);
        if(rep == false) {
            this->reChargerOperande(litterals);
            Pile::getInstance().setMessage("Desole l'analyse est infructueuse...");
        }
        else {
            delete litterals[0];
        }
    }
    else {
        this->reChargerOperande(litterals);
    }
}
