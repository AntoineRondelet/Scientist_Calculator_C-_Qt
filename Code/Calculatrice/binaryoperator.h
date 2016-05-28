#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include "operator.h"
#include "litteralenombre.h"
#include "calculatriceexception.h"
#include "pile.h"


class BinaryOperator: public Operator {
protected:
    unsigned int Nb_a_depiler;
public:
    BinaryOperator(): Operator(), Nb_a_depiler(2){} //Nb_a_depiler vaut tjrs 2 ici on est dans le cas d'un operateur binaire. On a fait un attribut de telle sorte a pouvoir faire un copier coller de cette classe et changer 2 par 3 dans le constructeur si on veut faire une classe d'operateurs ternaires par exemple.
    QVector<Litterale*> chargerOperande() const override; //On renvoie un tableau des litterales depilées
};



#endif // BINARYOPERATOR_H
