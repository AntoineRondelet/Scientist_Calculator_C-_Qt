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

    // -- Sauvegarde l'état pile actuelle: A chaque sauvegarde on créer un memento: ATTENTION les sauvegardes doivent etre des ptr constants, sinon on pourrait changer l'état d'une sauvegarde, ce qui n'est pas très secure -- //

    const PileMemento* saveStatePile() const {return new PileMemento(Pile::handler.instance);}
    void restoreStatePile(const PileMemento* pM) {handler.instance = pM->getState();}



    // -- Restaure un état antécédent -- //

    // -- Nos sauvegardes sont juste des piles "constantes" donc non modifiables qui permettent de savoir ce qu'il y avait avant dans la pile -- //
    // -- Il est a noter qu'elles ne sont en AUCUN CAS exploitable directement, il faut, comme rebasculer les données de la sauvegarde dans la pile "principale" -- //
    // -- Si on veut repartir d'une sauvegarde pour faire des modifications (On doit récupérer les données correspondantes à la sauvegarde -- //
    /*void restoreStatePile(const PileMemento* pM) {
        while (!this->empty()) {
            delete this->pop();
        }
        // -- En sortant du while la pile est vide -> On oublie pas qu'on a UNE SEULE instance de la Pile, donc on ne peut pas faire clone ici -- //
        Litterale* litToPush;
        QStack<Litterale*>::iterator it;
        // -- On a donc vidé la pile et on la reremplie avec ce qu'il y a dans la sauvegarde (compléxité pas ouf j'avoue...) -- //
        for (it = (*pM->getState()).begin(); it != (*pM->getState()).end(); ++it){
            litToPush = *it;
            // -- On push dans la nouvelle pile LE CLONE de chaque litterale de la pile actuelle. -- //
            this->push(litToPush->clone());
        }
    }*/


    Pile* clone() const;

};


#endif // PILE_H
