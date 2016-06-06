#ifndef IDENTIFICATEURMANAGER_H
#define IDENTIFICATEURMANAGER_H

#include "litterale.h"
#include <QMap>
#include <QString>
#include "analyser.h"


// -- Cette classe vise a recenser les litterales qui sont associées a un nom via STO: elle est composée par l'analyseur -- //
class IdentificateurManager {
private:
    // -- On decide de mettre analyser en classe amie et de NE PAS faire de composition car: -- //
    // -- 1) Certains opérateurs (STO/FORGET) doivent acceder a cette classe, donc on la considère un peu comme un ressource partagée -- //
    // -- 2) On met Analyser en classe amie car elle doit pouvoir avoir un acces direct a la QMap (pour la parcourir etc.) alors que STO et FORGET passent par les methodes ajout et suppression de la classe (pas les mêmes droits) -- //
    friend Litterale* createAtome(QRegularExpressionMatch matched_exp);

    // -- QMap qui associe un nom a une Litterale ayant subit un STO -- //
    QMap<QString, Litterale*> m_names;

    // -- QMap des noms des opérateurs dans le systeme -- //
    QMap<QString, QString> m_ops;

    //Debut singleton
    IdentificateurManager(const IdentificateurManager& p);
    IdentificateurManager& operator=(const IdentificateurManager& p);
    ~IdentificateurManager(){}

    class Handler {
    public:
        IdentificateurManager* instance;
        Handler():instance(0){}
        ~Handler() {delete instance;}
    };

    static Handler handler;
    //Fin singleton


public:
    IdentificateurManager(): m_names(QMap<QString, Litterale*>()), m_ops(QMap<QString, QString>()){
        this->init();
    }

    void ajouterIdentificateur(const QString lit_name, Litterale* lit);

    void init();

    /*void supprimerIdentificateur(Litterale* lit) {
        Litterale* lit_name_suppr = m_names.take(lit_name);
        delete lit_name_suppr;
    }*/

    // -- On choisit de ne pas faire de methode d'ajout d'operateur car les operateurs sont buit-in. Donc a priori, seul un programmeur pourra en ajouter, et pas l'utilisateur (il pourra cependant faire des programmes !) -- //

    QString strOperateurs() const;


    // -- Singleton -- //
    static IdentificateurManager& getInstance();
    static void libererInstance();
};

#endif // IDENTIFICATEURMANAGER_H
