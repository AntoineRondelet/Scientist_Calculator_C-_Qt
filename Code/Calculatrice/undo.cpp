#include "undo.h"
#include "pilecaretaker.h"


void Undo::execute(QVector<Litterale*> litterals) const {
    PileCaretaker& stackHistory = PileCaretaker::getInstance();
    Pile& stack = Pile::getInstance();
    QString msg = QString::number(stackHistory.numIndex);
    stack.setMessage("On est dans le UNDO :: " + msg + " !!");
    stackHistory.restoreDownState(&stack);
    //return;
}

