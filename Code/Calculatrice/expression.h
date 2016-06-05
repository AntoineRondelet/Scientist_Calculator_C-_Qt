#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "litterale.h"

class Expression: public Litterale {
    QString textExpr;
public:
    Expression(const QString& s): Litterale(), textExpr(s){}

    QString toString() const {return (textExpr);} //Lors du passage a Qt : il faudra utiliser the "maxLength : int" property de la classe QLineEdit pour permettre a l'affichage des "...'" a la fin des Expressions trop longues
    Expression* clone() const;

    Litterale& addition(const Litterale& lit) const;
    Litterale& soustraction(const Litterale& lit) const;
    Litterale& multiplication(const Litterale& lit) const;
    Litterale& division(const Litterale& lit) const;

    void eval(Litterale* lit) const;
};

inline Expression* Expression::clone() const {return new Expression(*this);}

#endif // EXPRESSION_H

//UTILISER le Validator pour valider la saisie dans une QLineEdit avec Qt.
//De cette maniere on peut eviter les espaces dans les expressions -> on les interdit dans la regex

/*
QRegExp re("^[[,(]{1,1}(0|[1-9]{1,1}[0-9]{0,9})[,]{1,1}(0|[1-9]{1,1}[0-9]{0,9})[],)]{1,1}$");
QRegExpValidator *validator = new QRegExpValidator(re, this);
ui->lineEdit->setValidator(validator);
*/
