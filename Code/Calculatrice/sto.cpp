#include "sto.h"


#include <QString>
#include "atome.h"
#include "litterale.h"
#include "expression.h"
#include "identificateurmanager.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

void Sto::execute(QVector<Litterale*> litterals) const {
    // -- STO porte sur des EXPRESSIONS ne contenant qu'UN atome -- //
    Expression* operande1 = dynamic_cast<Expression*>(litterals[0]);
    LitteraleNombre* operande2 = dynamic_cast<LitteraleNombre *>(litterals[1]);

    // -- On regarde si ce qu'il y a dans l'expression est un atome (on cherche le pattern associé -- //
    QRegularExpression atome("^[A-Z]([A-Z0-9]*)$");

    // -- Pour se faire: On retire les "'" de l'expression et on essaie de matcher son contenu avec la regex associée à un atome -- //
    QString stringAMatcher = operande1->toString();
    stringAMatcher.remove("'");
    QRegularExpressionMatch str_match = atome.match(stringAMatcher);

    // -- Si on a bien une expression contenant un atome, on entre le nom de l'atome dans la table des identificateurs -- //
    if (operande1!=nullptr && operande2!=nullptr && str_match.hasMatch()){
        IdentificateurManager& id_man = IdentificateurManager::getInstance();

        // -- On s'assure qu'on a bien exactement 1 atome dans l'expression -- //
        QString matched = str_match.captured(0);

        // -- On veille a bien faire un clone car on ne veut pas stocker un objet en particulier, mais plutot mettre un objet "modele" ou referant -- //
        // -- dans la table de telle sorte a pouvoir supprimer des atomes ayants la meme valeur que lui dans la pile, sans le supprimer lui (des adresses diffrentes) -- //
        id_man.ajouterIdentificateur(matched, operande2->clone());
        for (unsigned int i = 0; i < Nb_a_depiler; i++) {
            delete litterals[i];
        }
    }
    else {
        // -- Sinon, opérandes du mauvais type: On les réempile -- //
        this->reChargerOperande(litterals);
    }
}
