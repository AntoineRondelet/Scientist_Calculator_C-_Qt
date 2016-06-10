#include "sto.h"


#include <QString>
#include "atome.h"
#include "litterale.h"
#include "expression.h"
#include "identificateurmanager.h"
#include "programme.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

void Sto::execute(QVector<Litterale*> litterals) const {
    // -- STO porte sur des EXPRESSIONS ne contenant qu'UN atome -- //

    Expression* operande1 = dynamic_cast<Expression*>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);
    Programme* operande2Prog = dynamic_cast<Programme *>(litterals[1]);

    // -- On regarde si ce qu'il y a dans l'expression est un atome (on cherche le pattern associé -- //
    QRegularExpression atome("^[A-Z]([A-Z0-9]*)$");

    // -- Si on a bien une expression -- //
    if ((operande1!=nullptr && operande2!=nullptr)||(operande1!=nullptr && operande2Prog!=nullptr)){

        // -- Pour se faire: On retire les "'" de l'expression et on essaie de matcher son contenu avec la regex associée à un atome -- //
        QString stringAMatcher = operande1->toString();
        stringAMatcher.remove("'");
        QRegularExpressionMatch str_match = atome.match(stringAMatcher);

        if(str_match.hasMatch()) {
            IdentificateurManager& id_man = IdentificateurManager::getInstance();

            // -- On s'assure qu'on a bien exactement 1 atome dans l'expression -- //
            QString matched = str_match.captured(0);

            // -- On veille a bien faire un clone car on ne veut pas stocker un objet en particulier, mais plutot mettre un objet "modele" ou referant -- //
            // -- dans la table de telle sorte a pouvoir supprimer des atomes ayants la meme valeur que lui dans la pile, sans le supprimer lui (des adresses diffrentes) -- //
            if(operande2!=nullptr)
                id_man.ajouterIdentificateur(matched, operande2->clone());
            else
                id_man.ajouterIdentificateur(matched, operande2Prog->clone());

            Pile::lastOpname = "STO";
            for (unsigned int i = 0; i < Nb_a_depiler; i++) {
                delete litterals[i];
            }
        }
        else {
            CALCULATRICE_EXCEPTION("L'expression ne doit comporter qu'un atome !")
        }
    }
    else {
        // -- Sinon, opérandes du mauvais type: On les réempile -- //
        this->reChargerOperande(litterals);
    }
}
