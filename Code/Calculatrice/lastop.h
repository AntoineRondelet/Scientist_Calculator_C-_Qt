#ifndef LASTOP_H
#define LASTOP_H


#include "operateurspecial.h"
#include "operator.h"

class LastOp:public OperateurSpecial{
    //Debut singleton
    LastOp(const LastOp& p);
    LastOp& operator=(const LastOp& p);
    ~LastOp(){}

    class Handler {
    public:
        LastOp* instance;
        Handler():instance(0){}
        ~Handler() {delete instance;}
    };

    static Handler handler;
    //Fin singleton
    QString lastOp;

public:
    LastOp(): OperateurSpecial(), lastOp(""){}
    void execute(QVector<Litterale*> litterals) const;

    // -- Singleton -- //
    static LastOp& getInstance();
    static void libererInstance();
};


#endif // LASTOP_H
