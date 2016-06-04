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

    QMap<QString, Litterale*> m_names; //QMap qui associe un nom a une Litterale ayant subit un STO

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
    IdentificateurManager(): m_names(QMap<QString, Litterale*>()){}

    void ajouterIdentificateur(const QString lit_name, Litterale* lit) {
        // -- Utiliser insert() permet, si l'identifiant correspond deja a une variable, de l'écraser -- //
        if (m_names.contains(lit_name)) {
            // -- On associe le "meme" atome a une autre Litterale -> On supprime PROPREMENT (on a une QMap de pointers !) l'ancienne entrée présente dans le QMap (et on ne fait pas un -- //
            // -- simple "insert" qui se contenterai d'ecraser l'ancien pointeru sans relacher la memoire allouée. Puis, on peut mettre dans la table l'identificateur et la nouvelle Litterale associée -- //
            Litterale* lit_name_suppr = m_names.take(lit_name);
            delete lit_name_suppr;
        }
        m_names.insert(lit_name, lit);
    }

    /*void supprimerIdentificateur(Litterale* lit) {
        Litterale* lit_name_suppr = m_names.take(lit_name);
        delete lit_name_suppr;
    }*/

    //void init(); //Lorsque l'on fera la persistance des données, on devra l'initialiser avec les données stockées


    // -- Singleton -- //
    static IdentificateurManager& getInstance();
    static void libererInstance();
};

#endif // IDENTIFICATEURMANAGER_H
