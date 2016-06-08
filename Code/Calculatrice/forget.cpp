#include "forget.h"

#include <QString>
#include "atome.h"
#include "litterale.h"
#include "identificateurmanager.h"


void Forget::execute(QVector<Litterale*> litterals) const {

    QRegularExpression atome("^[A-Z]([A-Z0-9]*)$");

    Expression* operande1 = dynamic_cast<Expression*>(litterals[0]);
    if(operande1 != nullptr) {
        QString stringAMatcher = operande1->toString();
        stringAMatcher.remove("'");
        QRegularExpressionMatch str_match = atome.match(stringAMatcher);

        if(str_match.hasMatch()) {
            IdentificateurManager& id_man = IdentificateurManager::getInstance();
            id_man.forgetIdentificateur(stringAMatcher);
        }
        else {
            CALCULATRICE_EXCEPTION("L'expression ne doit comporter qu'un atome !")
        }
    }
    else {
        // -- Sinon, opérande du mauvais type: On réempile -- //
        this->reChargerOperande(litterals);
    }
}
