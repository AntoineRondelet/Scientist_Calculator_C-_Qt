#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "litterale.h"

class Expression: public Litterale {
    QString textExpr;
public:
    Expression(const QString& s): Litterale(), textExpr(s){}

    QString toString() const {return textExpr;} //Lors du passage a Qt : il faudra utiliser the "maxLength : int" property de la classe QLineEdit pour permettre a l'affichage des "...'" a la fin des Expressions trop longues
    Expression* clone() const;
};

inline Expression* Expression::clone() const {return new Expression(*this);}

#endif // EXPRESSION_H
