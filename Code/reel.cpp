#include "reel.h"
#include "rationnel.h"
#include "entier.h"


LitteraleNombre& Reel::addition(const LitteraleNombre& lit) const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
    //Ici on teste l'addition d'un reel avec un reel -> Il faudrait aussi pouvoir faire reel+entier et reel+rationnel
    if (ptReel == 0) { // => lit n'est pas un reel: On essaie de la convertir en Rationnel
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
            if (ptRationnel == 0) {
                const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                    if (ptEntier ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        Reel* res= new Reel(value+ptEntier->getValeur());
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                Reel* res= new Reel(value+(static_cast<float>(ptRationnel->getNumerateur())/ptRationnel->getDenominateur()));
                LitteraleNombre& ref = *res;
                return ref;
            }
    }
    else {
        Reel* res= new Reel(value+ptReel->value);
        LitteraleNombre& ref = *res;
        return ref;
    }
}



LitteraleNombre& Reel::soustraction(const LitteraleNombre& lit) const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
    //soustraction avec un reel
    if (ptReel == 0) { // => lit n'est pas un reel
        //soustraction avec un rationnel
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
            if (ptRationnel == 0) {
                //soustraction avec un entier
                const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                    if (ptEntier ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        Reel* res= new Reel(value-ptEntier->getValeur());
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                Reel* res= new Reel(value-(static_cast<float>(ptRationnel->getNumerateur())/ptRationnel->getDenominateur()));
                LitteraleNombre& ref = *res;
                return ref;
            }
    }
    else {
        Reel* res= new Reel(value-ptReel->value);
        LitteraleNombre& ref = *res;
        return ref;
    }
}




LitteraleNombre& Reel::multiplication(const LitteraleNombre& lit) const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
    if (ptReel == 0) {
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
            if (ptRationnel == 0) {
                const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                    if (ptEntier ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        Reel* res= new Reel(ptEntier->getValeur()*value);
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                Reel* res= new Reel(value*(static_cast<float>(ptRationnel->getNumerateur())/ptRationnel->getDenominateur()));
                LitteraleNombre& ref = *res;
                return ref;
            }
    }
    else {
        Reel* res= new Reel(ptReel->value*value);
        LitteraleNombre& ref = *res;
        return ref;
    }
}



LitteraleNombre& Reel::division(const LitteraleNombre& lit) const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
    if (ptReel == 0) {
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
            if (ptRationnel == 0) {
                const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                    if (ptEntier ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        Reel* res= new Reel(value/ptEntier->getValeur());
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                Reel* res= new Reel(value/(static_cast<float>(ptRationnel->getNumerateur())/ptRationnel->getDenominateur()));
                LitteraleNombre& ref = *res;
                return ref;
            }
    }
    else {
        Reel* res= new Reel(value/ptReel->value);
        LitteraleNombre& ref = *res;
        return ref;
    }
}




string Reel::toString() const {
    stringstream s;
    s<<value;
    return s.str();
}
