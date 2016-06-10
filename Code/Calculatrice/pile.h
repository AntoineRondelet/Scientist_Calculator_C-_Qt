#ifndef PILE_H
#define PILE_H

#include <QProcess>
#include <QStack>
#include <QString>
#include <QObject>

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

    static QVector<Litterale*> argsHistory;
    static QString lastOpname;

    void clean(QVector<Litterale*> vec);

    Pile(): QStack<Litterale*>(), nbAffiche(5){}
    void affiche() const;
    QString getMessage() const {return message;}
    void setMessage(const QString& m) {message=m;}

    unsigned int getNbAffiche() const {return nbAffiche;}

    void setNbAffiche(unsigned int i) {nbAffiche = i;}

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


    // -- Restaure un état antécédent -- //

    // -- Nos sauvegardes sont juste des piles "constantes" donc non modifiables qui permettent de savoir ce qu'il y avait avant dans la pile -- //
    // -- Il est a noter qu'elles ne sont en AUCUN CAS exploitable directement, il faut, rebasculer les données de la sauvegarde dans la pile "principale" -- //
    // -- Si on veut repartir d'une sauvegarde pour faire des modifications (On doit récupérer les données correspondantes à la sauvegarde) et les mettre dans la pile "pincipale" -- //
    // -- Modifier une sauvegarde n'a pas de sens ! -- //
    void restoreStatePile(const PileMemento* pM) {
        // -- On vide la pile principale pour y mettre les données de la sauvegarde et pouvoir faire des modifs a partir de données récuprées d'une sauvegarde -- //
        while (!this->empty()) {
            delete this->pop();
        }
        // -- En sortant du while la pile est vide: On oublie pas qu'on a UNE SEULE instance de la Pile, on la remplit donc avec les données de la sauvegarde -- //
        Litterale* litToPush;
        QStack<Litterale*>::iterator it;
        // -- On a donc vidé la pile et on la reremplie avec ce qu'il y a dans la sauvegarde (compléxité pas ouf j'avoue...) -- //
        for (it = (*pM->getState()).begin(); it != (*pM->getState()).end(); ++it){
            litToPush = *it;
            // -- On push dans la pile "principale" LE CLONE de CHAQUE litterale de la sauvegarde actuelle. (On clone car on ne veut pas altérer la sauvegarde: elle sera détruite au bon moment lorsqu'on en aura d'autres plus récentes -- //
            this->push(litToPush->clone());
        }
    }

    //-- /!\ A NE PAS FAIRE !!/!\ -- //
    //void restoreStatePile(const PileMemento* pM) {handler.instance = pM->getState();} -> ici on récupere le pointeur sur une pile qui est toujours contenu (le ptr) dans le manageur de pile
    // OR ON A DECIDER d'eliminer les sauvegardes plus anciennes que les 5 plus récentes. DONC si on recupere la pile comme ca et qu'on veut la modifier -> 5 modifications plus tard
    // cette pile sera DETRUITE (car trop anciennes) et nos modifs seront EFFACEES !! /!\ avec ces details. D'ou l'importance de faire comme ci-dessus (de plus ci-dessus, on respecte bien le fait qu'on a une et une seule instance de la pile, elle ne change JAMAIS)


    Pile* clone() const;
};


#endif // PILE_H
