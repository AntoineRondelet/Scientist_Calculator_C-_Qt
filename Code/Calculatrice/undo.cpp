#include "undo.h"
#include "pilecaretaker.h"

void Undo::execute(QVector<Litterale*> litterals) const {
    PileCaretaker* stackHistory = &PileCaretaker::getInstance();
    Pile* stack = &Pile::getInstance();
    stack->setMessage("On revient à 1 état précédent");
    stackHistory->restoreDownState(stack);
    //return;
}
