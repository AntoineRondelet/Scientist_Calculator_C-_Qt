#ifndef PROGRAMME_H
#define PROGRAMME_H


#include "litterale.h"

class Programme: public Litterale {
    QString textProg;
public:
    Programme(const QString& s): Litterale(), textProg(s){}

    QString toString() const {return textProg;} //Lors du passage a Qt : il faudra utiliser the "maxLength : int" property de la classe QLineEdit pour permettre a l'affichage des "...'" a la fin des Programmes trop longues
    Programme* clone() const;

    QStringList eval(Litterale* lit) const;
};

inline Programme* Programme::clone() const {return new Programme(*this);}


#endif // PROGRAMME_H
