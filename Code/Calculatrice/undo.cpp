#include "undo.h"
#include "pilecaretaker.h"

void Undo::execute(QVector<Litterale*> litterals) const {
    Pile* stack = &Pile::getInstance();
    stack->setMessage("On revient à 1 état précédent");
    PileCaretaker* stackHistory = &PileCaretaker::getInstance();
    stackHistory->restoreState(stack, (stackHistory->PileMementoList.size()-2));
    return;
}
