#include"entier.h"
#include"calculatriceexception.h"
#include "reel.h"
#include "rationnel.h"

LitteraleNombre& Entier::addition(const LitteraleNombre& lit) const {
    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
    // int + int = int
    if (ptEntier == 0) {
        //int + rationnel = rationnel
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
            if (ptRationnel == 0) {
                //int + reel = reel
                const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                    if (ptReel ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        Reel* res= new Reel(valeur+ptReel->getValue());
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                Rationnel* res= new Rationnel(ptRationnel->getNumerateur()+ptRationnel->getDenominateur()*valeur, ptRationnel->getDenominateur());
                LitteraleNombre& ref = *res;
                return ref;
            }
    }
    else {
        Entier* res= new Entier(valeur+ptEntier->valeur);
        LitteraleNombre& ref = *res;
        return ref;
    }
}




LitteraleNombre& Entier::soustraction(const LitteraleNombre& lit) const {
    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
    // int + int = int
    if (ptEntier == 0) {
        //int + rationnel = rationnel
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
            if (ptRationnel == 0) {
                //int + reel = reel
                const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                    if (ptReel ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        Reel* res= new Reel(valeur-ptReel->getValue());
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                Rationnel* res= new Rationnel(ptRationnel->getDenominateur()*valeur-ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
                LitteraleNombre& ref = *res;
                return ref;
            }
    }
    else {
        Entier* res= new Entier(valeur-ptEntier->valeur);
        LitteraleNombre& ref = *res;
        return ref;
    }
}



LitteraleNombre& Entier::multiplication(const LitteraleNombre& lit) const {
    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
    // int + int = int
    if (ptEntier == 0) {
        //int + rationnel = rationnel
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
            if (ptRationnel == 0) {
                //int + reel = reel
                const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                    if (ptReel ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        Reel* res= new Reel(valeur*ptReel->getValue());
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                Rationnel* res= new Rationnel(valeur*ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
                LitteraleNombre& ref = *res;
                return ref;
            }
    }
    else {
        Entier* res= new Entier(valeur*ptEntier->valeur);
        LitteraleNombre& ref = *res;
        return ref;
    }
}





LitteraleNombre& Entier::division(const LitteraleNombre& lit) const {
    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
    // int + int = int
    if (ptEntier == 0) {
        //int + rationnel = rationnel
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
            if (ptRationnel == 0) {
                //int + reel = reel
                const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                    if (ptReel ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        Reel* res= new Reel(valeur/ptReel->getValue());
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                Rationnel* res= new Rationnel(valeur*ptRationnel->getDenominateur(), ptRationnel->getNumerateur());
                LitteraleNombre& ref = *res;
                return ref;
            }
    }
    else { //Cf énoncé
        if (valeur%ptEntier->valeur == 0) {
            Entier* res= new Entier(valeur/ptEntier->valeur);
            LitteraleNombre& ref = *res;
            return ref;
        }
        else {
            Rationnel* res= new Rationnel(valeur, ptEntier->valeur);
            LitteraleNombre& ref = *res;
            return ref;
        }
    }
}





string Entier::toString() const {
    stringstream s;
    s<<valeur;
    return s.str();
}
