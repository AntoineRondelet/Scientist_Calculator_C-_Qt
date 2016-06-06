#include "clear.h"
#include "drop.h"
#include <QVector>

void Clear::execute(QVector<Litterale*> litterals) const {
    Drop objDrop;
    while (!Pile::getInstance().isEmpty()) {
        QVector<Litterale*> vec = objDrop.chargerOperande();
        objDrop.execute(vec);
    }
}
