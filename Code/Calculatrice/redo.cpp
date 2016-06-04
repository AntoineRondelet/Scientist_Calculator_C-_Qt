#include "redo.h"
#include "pilecaretaker.h"

void Redo::execute(QVector<Litterale*> litterals) const {
    PileCaretaker& stackHistory = PileCaretaker::getInstance();
    Pile& stack = Pile::getInstance();
    stackHistory.restoreUpState(&stack);
    //return;
}
