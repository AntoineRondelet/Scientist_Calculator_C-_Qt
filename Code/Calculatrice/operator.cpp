#include "operator.h"

#include "add.h"
#include "mult.h"


Operator* getOperateur(const string& str){ //Ici c'est une factory en quelque sorte
    if(str == "ADD") {
        return new Add;
    }
    else if(str == "MULT") {
        return new Mult;
    }
    cout << "Operateur inconnu ! " << endl;
    return nullptr;
}
