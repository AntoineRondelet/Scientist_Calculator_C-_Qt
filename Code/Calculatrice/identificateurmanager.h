#ifndef IDENTIFICATEURMANAGER_H
#define IDENTIFICATEURMANAGER_H

#include "litterale.h"
#include <QMap>
#include <QString>
#include "analyser.h"
#include "xml_dom.h"

#include <QObject>

// -- Cette classe vise a recenser les litterales qui sont associées a un nom via STO: elle est composée par l'analyseur -- //
class IdentificateurManager: public QObject {
    Q_OBJECT
private:
    // -- On decide de mettre analyser en classe amie et de NE PAS faire de composition car: -- //
    // -- 1) Certains opérateurs (STO/FORGET) doivent acceder a cette classe, donc on la considère un peu comme un ressource partagée -- //
    // -- 2) On met Analyser en classe amie car elle doit pouvoir avoir un acces direct a la QMap (pour la parcourir etc.) alors que STO et FORGET passent par les methodes ajout et suppression de la classe (pas les mêmes droits) -- //
    friend Litterale* createAtome(QRegularExpressionMatch matched_exp);
    friend class Xml_Dom;

    // -- QMaps qui associe un nom a une Litterale ayant subit un STO -- //
    QMap<QString, Litterale*> m_names_var;
    QMap<QString, Litterale*> m_names_prog;

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
    IdentificateurManager(): m_names_var(QMap<QString, Litterale*>()), m_names_prog(QMap<QString, Litterale*>()), m_ops(QMap<QString, QString>()){
        this->init();
    }

    void ajouterIdentificateur(const QString lit_name, Litterale* lit);
    void forgetIdentificateur(const QString lit_name);

    QStringList getVarEntries() const;
    QStringList getProgEntries() const;

    void init();

    // -- On choisit de ne pas faire de methode d'ajout d'operateur car les operateurs sont buit-in. Donc a priori, seul un programmeur pourra en ajouter, et pas l'utilisateur (il pourra cependant faire des programmes !) -- //

    const QString strOperateurs() const;

    QString getLitteraleVar(const QString& cle) const;
    QString getLitteraleProg(const QString& cle) const;


    // -- Singleton -- //
    static IdentificateurManager& getInstance();
    static void libererInstance();

signals:
    void modificationEtatIDs();
};

#endif // IDENTIFICATEURMANAGER_H
