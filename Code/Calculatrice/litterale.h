#ifndef LITTERALE_H
#define LITTERALE_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Litterale {
public:
    Litterale(){}
    virtual string toString() const = 0;
    virtual Litterale* clone() const = 0; //Important pour faire l'operateur DUP
    //Important de la mettre ici en tant que methode virtual pure pour que toutes les litterales l'implementent
    //et ainsi, pour qu'on puisse cloner toutes les litterales

    virtual ~Litterale(){}
};

#endif // LITTERALE_H
