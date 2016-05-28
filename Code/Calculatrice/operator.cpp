#include "operator.h"

#include "add.h"
#include "mult.h"
#include "div.h"

#include "neg.h"
#include "num.h"




Operator* getOperateur(const string& str){ //Ici c'est une factory en quelque sorte
    //On teste tous les operateurs binaires d'abord
    if(str == "+") {
        return new Add;
    }
    else if(str == "*") {
        return new Mult;
    }
    else if(str == "/") {
        return new Div;
    }
    //on teste ensuite les operateurs unaires (on fait ca juste pour s'y retrouver)
    else if(str == "NEG") {
        return new Neg;
    }
    else if(str == "NUM") {
        return new Num;
    }
    cout << "Operateur inconnu ! " << endl;
    return nullptr;
}
