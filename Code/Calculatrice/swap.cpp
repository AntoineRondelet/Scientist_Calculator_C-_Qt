#include "swap.h"

void Swap::execute(QVector<Litterale*> litterals) const {
    Litterale* operande1 = litterals[0];
    Litterale* operande2 = litterals[1];

    // -- On remet les litterales dans la pile dans le sens inverse -- //
    Pile::getInstance().push(operande1);
    Pile::getInstance().push(operande2);
}
