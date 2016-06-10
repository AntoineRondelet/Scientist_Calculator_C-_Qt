#include "lastop.h"
#include "operateurspecial.h"
#include "controleur.h"


// -- Singleton -- //

LastOp::Handler LastOp::handler;

LastOp& LastOp::getInstance() {
    if(handler.instance == nullptr)
        handler.instance = new LastOp;
    return *handler.instance;
}

void LastOp::libererInstance() {
    delete handler.instance;
    handler.instance=nullptr;
}


void LastOp::execute(QVector<Litterale*> litterals) const {
    QStringList op;
    op << lastOp;
    Controleur::getInstance().commande(op);
}
