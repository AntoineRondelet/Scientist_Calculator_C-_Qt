/**
 * @file forget.h
 * @brief Fichier header de la classe Forget
 * @author Rondelet Antoine et Joubert Guillaume
 */


#ifndef FORGET_H
#define FORGET_H

#include "unaryoperator.h"

class Forget: public UnaryOperator{
public:
    Forget(): UnaryOperator(){}
    void execute(QVector<Litterale*> litterals) const override;
};


#endif // FORGET_H
