#include "programme.h"
#include <QString>
#include <QStringList>
#include <QRegularExpression>

#include "calculatriceexception.h"


QStringList Programme::eval(Litterale* lit) const {
    Programme* operandeProgramme = dynamic_cast<Programme*>(lit);

    if(operandeProgramme) {
        QString str_prog = operandeProgramme->toString();
        QStringList str_lis_op = str_prog.split(QRegularExpression("[[:space:]]+"));
        // -- On retire les crochets de notre programme et on envoie la QStringList à notre controleur pour qu'il fasse le reste du travail -- //
        str_lis_op.pop_back();
        str_lis_op.pop_front();
        return str_lis_op;
    }
    else {
        CALCULATRICE_EXCEPTION("PROBLEME DANS L'EVALUATION DE LA LITTERALE");
    }
}
