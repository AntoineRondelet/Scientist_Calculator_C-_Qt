#ifndef PILE_H
#define PILE_H

#include <QProcess>
#include <QStack>
#include <QString>

#include "litterale.h"

#include "pilememento.h"

// ----  DESIGN PATTERN SINGLETON ---- //

class Pile: public QStack<Litterale*> {
    friend class PileCaretaker;

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

    // -- Singleton -- //
    static Pile& getInstance();
    static void libererInstance();


    // -- Memento -- //
//----------------------------------------------------------------------------------//
    class PileMemento {
    private:
      friend class Pile; //Suggested
      Pile* statePile;
    public:
        // -- Ici, on créer une copie de notre pile que l'on "stocke" dans un objet memento lui meme stocké dans le PileCareTaker -- //
        PileMemento(const Pile* pileASave): statePile(pileASave->clone()){}
        Pile* getState() const {return statePile;}
        //void setState(Pile* etat_a_save) {statePile = etat_a_save;}
    };
//----------------------------------------------------------------------------------//

    //Sauvegarde l'état pile actuelle: A chaque sauvegarde on créer un memento
    PileMemento* saveStatePile() const {return new PileMemento(Pile::handler.instance);}
    //Restaure un état antécédent
    void restoreStatePile(const PileMemento* pM) {handler.instance = pM->getState();}

    Pile* clone() const;

};


#endif // PILE_H
