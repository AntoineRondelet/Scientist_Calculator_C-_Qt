#ifndef PILE_H
#define PILE_H

#include <QProcess>
#include "litterale.h"
#include <QStack>
#include <QString>


class Pile: public QStack<Litterale*> {

    //Debut singleton
    Pile(const Pile& p);
    Pile& operator=(const Pile& p);
    ~Pile(){}

    class Handler {
    public:
        Pile* instance;
        Handler():instance(0){}
        ~Handler() {delete instance;}
    };

    static Handler handler;
    //Fin singleton

    //Attributs
    unsigned int nbAffiche;
    QString message;
public:

    Pile(): QStack<Litterale*>(), nbAffiche(5){}
    void affiche() const;
    QString getMessage() const {return message;}
    void setMessage(const QString& m) {message=m;}

    //Singleton
    static Pile& getInstance();
    static void libererInstance();
};


#endif // PILE_H
