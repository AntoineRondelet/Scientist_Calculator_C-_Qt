#ifndef OPERATOR_H
#define OPERATOR_H

#include "litterale.h"
#include "litteralenombre.h"
#include <QString>
#include <QVector>
#include <QMap>
#include <QMapIterator>
#include <memory>

class Operator {
    //Pas besoin d'avoir un nom ou quelque attribut -> on utilise direct l'instance que l'on créer -> on s'assure juste de créer la bonne
    //Donc comme pas besoin d'vaoir d'attribut -> pas besoin d'avoir une enum ou une map pour stocker le nom des operateurs possibles
public:
    Operator(){}
    virtual QVector<Litterale*> chargerOperande() const = 0; //S'occupe du depilement des Litterales sur lesquelles portent l'operation
    virtual void reChargerOperande(QVector<Litterale*> litterals) const = 0;
    virtual void execute(QVector<Litterale*> litterals) const = 0; //fait l'operantion créer et renvoie un ptr sur une litterale
    virtual ~Operator(){}
};

Operator* getOperateur(const string& str);
//A partir de la string lue sur la ligne de commande, renvoie/construit l'operateur correspondant
//getOperateur --> contient un mega switch avec toutes les possibilités -> le default -> throw error -> Operateur inconnu


#endif // OPERATOR_H
