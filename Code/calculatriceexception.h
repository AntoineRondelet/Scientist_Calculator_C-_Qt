#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

#include <string>

using namespace std;

class CalculatriceException {
    string info;
public:
    CalculatriceException(const string& str):info(str){}
    string getInfo() const {return info;}
};

#endif // CALCULATRICEEXCEPTION_H
