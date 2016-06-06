#include "reel.h"
#include "rationnel.h"
#include "entier.h"


LitteraleNombre& Reel::addition(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
        //Ici on teste l'addition d'un reel avec un reel -> Il faudrait aussi pouvoir faire reel+entier et reel+rationnel
        if (ptReel == 0) { // => lit n'est pas un reel: On essaie de la convertir en Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                        if (ptEntier ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
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
    else {
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) + (*ptComplexe);
        return res;
    }
}


/*
Complexe* temp = this->toComplexe();
LitteraleNombre& res= (*temp) + (*ptComplexe);
//LitteraleNombre& ref = *res;
return res;
*/


LitteraleNombre& Reel::soustraction(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
        //soustraction avec un reel
        if (ptReel == 0) { // => lit n'est pas un reel
            //soustraction avec un rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    //soustraction avec un entier
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                        if (ptEntier ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
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
    else {
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) - (*ptComplexe);
        return res;
    }
}



LitteraleNombre& Reel::multiplication(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
        if (ptReel == 0) {
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                        if (ptEntier ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
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
    else {
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) * (*ptComplexe);
        return res;
    }
}



LitteraleNombre& Reel::division(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
        if (ptReel == 0) {
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                        if (ptEntier ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else {
                            //On traite le cas ou on tente la division par zero
                            if(ptReel->getValue() == 0)
                                CALCULATRICE_EXCEPTION("Division par zero");
                            Reel* res= new Reel(value/ptEntier->getValeur());
                            LitteraleNombre& ref = *res;
                            return ref;
                        }
                }
                else {
                    //On traite le cas ou on tente la division par zero
                    if (ptRationnel->getNumerateur() == 0){
                        CALCULATRICE_EXCEPTION("Erreur: Division par zero");
                    }
                    else {
                        //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                        Reel* res= new Reel(value/(static_cast<float>(ptRationnel->getNumerateur())/ptRationnel->getDenominateur()));
                        LitteraleNombre& ref = *res;
                        return ref;
                    }
                }
        }
        else {
            //On traite le cas ou on tente la division par zero
            if (ptReel->getValue() == 0){
                CALCULATRICE_EXCEPTION("Erreur: Division par zero");
            }
            else {
                Reel* res= new Reel(value/ptReel->value);
                LitteraleNombre& ref = *res;
                return ref;
            }
        }
    }
    else {
        if(ptComplexe->getPartEnt() == 0 && ptComplexe->getPartIm() == 0)
            CALCULATRICE_EXCEPTION("Division par zero");
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) / (*ptComplexe);
        return res;
    }
}




QString Reel::toString() const {
    QString s;
    s.setNum(value);
    return s;
}


Complexe* Reel::toComplexe() const {
    const LitteraleNombre& re = *this;
    const LitteraleNombre& im = *(new Reel(0.0));
    Complexe* res = new Complexe(re,im);
    return (res);
}







bool Reel::superieur(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
        // int + int = int
        if (ptEntier == 0) {
            //int + rationnel = rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    //int + reel = reel
                    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                        if (ptReel ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else {
                            if (this->value > ptReel->getValue()){
                                return true;
                             }
                            else {
                                return false;
                            }
                        }
                }
                else {
                    if (this->value > (static_cast<float>(ptRationnel->getNumerateur())/ptRationnel->getDenominateur())){
                        return true;
                     }
                    else {
                        return false;
                    }
                }
        }
        else {
            if (this->value > ptEntier->getValeur()){
                return true;
             }
            else {
                return false;
            }
        }
    }
    else {
        Complexe* cplx = this->toComplexe();
        if (cplx->getPartEnt()->superieur(*ptComplexe->getPartEnt()) || (cplx->getPartEnt()->egal(*ptComplexe->getPartEnt()) && cplx->getPartIm()->superieur(*ptComplexe->getPartIm()))){
            return true;
         }
        else {
            return false;
        }
    }
}


//PAS FAIT
bool Reel::inferieur(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
        // int + int = int
        if (ptEntier == 0) {
            //int + rationnel = rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    //int + reel = reel
                    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                        if (ptReel ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else {
                            if (this->value < ptReel->getValue()){
                                return true;
                             }
                            else {
                                return false;
                            }
                        }
                }
                else {
                    if (this->value < (static_cast<float>(ptRationnel->getNumerateur())/ptRationnel->getDenominateur())){
                        return true;
                     }
                    else {
                        return false;
                    }
                }
        }
        else {
            if (this->value < ptEntier->getValeur()){
                return true;
             }
            else {
                return false;
            }
        }
    }
    else {
        Complexe* cplx = this->toComplexe();
        if (cplx->getPartEnt()->inferieur(*ptComplexe->getPartEnt()) || (cplx->getPartEnt()->egal(*ptComplexe->getPartEnt()) && cplx->getPartIm()->inferieur(*ptComplexe->getPartIm()))){
            return true;
         }
        else {
            return false;
        }
    }
}


bool Reel::egal(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
        // int + int = int
        if (ptEntier == 0) {
            //int + rationnel = rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    //int + reel = reel
                    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                        if (ptReel ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else {
                            if (this->value == ptReel->getValue()){
                                return true;
                             }
                            else {
                                return false;
                            }
                        }
                }
                else {
                    if (this->value == (static_cast<float>(ptRationnel->getNumerateur())/ptRationnel->getDenominateur())){
                        return true;
                     }
                    else {
                        return false;
                    }
                }
        }
        else {
            if (this->value == ptEntier->getValeur()){
                return true;
             }
            else {
                return false;
            }
        }
    }
    else {
        Complexe* cplx = this->toComplexe();
        if (cplx->getPartEnt()->egal(*ptComplexe->getPartEnt()) && cplx->getPartIm()->egal(*ptComplexe->getPartIm())){
            return true;
         }
        else {
            return false;
        }
    }
}

