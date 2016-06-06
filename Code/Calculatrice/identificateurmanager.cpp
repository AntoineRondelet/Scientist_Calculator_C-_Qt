#include "identificateurmanager.h"

#include <QList>
#include <QStringList>



// -- Singleton -- //

IdentificateurManager::Handler IdentificateurManager::handler;

IdentificateurManager& IdentificateurManager::getInstance() {
    if(handler.instance == nullptr)
        handler.instance = new IdentificateurManager;
    return *handler.instance;
}

void IdentificateurManager::libererInstance() {
    delete handler.instance;
    handler.instance=nullptr;
}


void IdentificateurManager::ajouterIdentificateur(const QString lit_name, Litterale* lit) {
    // -- Utiliser insert() permet, si l'identifiant correspond deja a une variable, de l'écraser -- //
    if (m_names.contains(lit_name)) {
        // -- On associe le "meme" atome a une autre Litterale -> On supprime PROPREMENT (on a une QMap de pointers !) l'ancienne entrée présente dans le QMap (et on ne fait pas un -- //
        // -- simple "insert" qui se contenterai d'ecraser l'ancien pointeru sans relacher la memoire allouée. Puis, on peut mettre dans la table l'identificateur et la nouvelle Litterale associée -- //
        Litterale* lit_name_suppr = m_names.take(lit_name);
        delete lit_name_suppr;
    }
    m_names.insert(lit_name, lit);
}



void IdentificateurManager::init() {
    m_ops.insert("+", "LOW");
    m_ops.insert("-", "LOW");

    m_ops.insert("*", "MEDIUM");
    m_ops.insert("/", "MEDIUM");

    m_ops.insert("DROP", "HIGH");
    m_ops.insert("NEG", "HIGH");
    m_ops.insert("EVAL", "HIGH");
    m_ops.insert("UNDO", "HIGH");
    m_ops.insert("REDO", "HIGH");
    m_ops.insert("NUM", "HIGH");
    m_ops.insert("DEN", "HIGH");
    m_ops.insert("$", "HIGH");
}


QString IdentificateurManager::strOperateurs() const {
    QString result;
    QList<QString> op_list = m_ops.keys("HIGH");
    QList<QString>::iterator i;
    for (i = op_list.begin(); i != op_list.end(); ++i)
        result+= "|" + *i;
return result.remove(0,1);
}
