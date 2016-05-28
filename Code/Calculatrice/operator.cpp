#include "operator.h"

#include "add.h"
#include "mult.h"
#include "div.h"
#include "sous.h"

#include "neg.h"
#include "num.h"
#include "den.h"




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
    else if(str == "-") {
        return new Sous;
    }
    //on teste ensuite les operateurs unaires (on fait ca juste pour s'y retrouver)
    else if(str == "NEG") {
        return new Neg;
    }
    else if(str == "NUM") {
        return new Num;
    }
    else if(str == "DEN") {
        return new Den;
    }
    cout << "Operateur inconnu ! " << endl;
    return nullptr;
}
