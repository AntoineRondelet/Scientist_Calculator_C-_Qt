#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "pile.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <QString>
#include "analyser.h"

#include "eval.h"
#include <QObject>

class Controleur: public QObject {
    Q_OBJECT

    friend class Eval;

    Analyser* analyser;

    //Debut singleton
    Controleur(const Controleur& p);
    Controleur& operator=(const Controleur& p);
    ~Controleur(){delete analyser;} //On a une composition

    class Handler {
    public:
        Controleur* instance;
        Handler():instance(0){}
        ~Handler() {delete instance;}
    };

    static Handler handler;
    //Fin singleton

public:
    Controleur(): analyser(new Analyser()){
        //On initialise la map qui contient nos regex et nos fonctions de construction
        analyser->init();
    }

    void boucleExcecution();
    void commande(QStringList& list_src);



    // -- Singleton -- //
    static Controleur& getInstance();
    static void libererInstance();

signals:
    void modificationEtat();
};

//void splitEntry(const string& c); //Fonction qui permet de recuperer chaque "mot" dans la "phrase" saisie par le user
// Donc elle nous permet de recuperer





#endif // CONTROLEUR_H
