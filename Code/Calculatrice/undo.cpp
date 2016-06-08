#include "undo.h"
#include "pilecaretaker.h"


void Undo::execute(QVector<Litterale*> litterals) const {
    PileCaretaker& stackHistory = PileCaretaker::getInstance();
    Pile& stack = Pile::getInstance();
    stackHistory.restoreDownState(&stack);
}

