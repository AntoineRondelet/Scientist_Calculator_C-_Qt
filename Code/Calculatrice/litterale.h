#ifndef LITTERALE_H
#define LITTERALE_H

#include <string>
#include <iostream>

using namespace std;

class Litterale {
public:
    Litterale(){}
    virtual string toString() const = 0;

    virtual ~Litterale(){}
};

#endif // LITTERALE_H
