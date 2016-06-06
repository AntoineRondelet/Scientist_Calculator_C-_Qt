#include "operator.h"

#include "add.h"
#include "mult.h"
#include "div.h"
#include "sous.h"
#include "operateurcomplexe.h"
#include "oplogique.h"
#include "ift.h"


#include "neg.h"
#include "num.h"
#include "den.h"
#include "drop.h"
#include "eval.h"

#include "undo.h"
#include "redo.h"
#include "operateurspecial.h"
#include "sto.h"





Operator* getOperateur(const string& str){ //Ici c'est une factory en quelque sorte

    //---------- Operateurs Binaires ----------- //
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
    else if(str == "$") {
        return new  OperateurComplexe;
    }
    else if(str == "STO") {
        return new Sto;
    }
    else if(str == "=") {
        return new OpLogiqueEgal;
    }
    else if(str == "<") {
        return new OpLogiqueInf;
    }
    else if(str == "<=") {
        return new OpLogiqueInfEgal;
    }
    else if(str == ">") {
        return new OpLogiqueSup;
    }
    else if(str == ">=") {
        return new OpLogiqueSupEgal;
    }
    else if(str == "IFT") {
        return new Ift;
    }


    //---------- Operateurs Unaires ----------- //
    else if(str == "NEG") {
        return new Neg;
    }
    else if(str == "NUM") {
        return new Num;
    }
    else if(str == "DEN") {
        return new Den;
    }
    else if(str == "DROP") {
        return new Drop;
    }
    else if(str == "EVAL") {
        return new Eval;
    }

    //---------- Operateurs "Speciaux" -----------//
    else if(str == "UNDO") {
        return new Undo;
    }
    else if(str == "REDO") {
        return new Redo;
    }

    //---------- Si on a pas reconnu un operateur ----------- //
    cout << "Operateur inconnu ! " << endl;
    return nullptr;
}
