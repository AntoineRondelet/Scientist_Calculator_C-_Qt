#include"entier.h"
#include"calculatriceexception.h"
#include "reel.h"
#include "complexe.h"
#include "rationnel.h"

LitteraleNombre& Entier::addition(const LitteraleNombre& lit) const {
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
    else {
        //Complexe* res= new Complexe(ptComplexe->getPartEnt()->addition(*this), *ptComplexe->getPartIm());
        //Complexe* res= new Complexe(this->addition(*ptComplexe->getPartEnt()), *ptComplexe->getPartIm());
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) + (*ptComplexe);
        //LitteraleNombre& ref = *res;
        return res;
    }
}



LitteraleNombre& Entier::soustraction(const LitteraleNombre& lit) const {
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
    else {
        /*Entier temp(-1); //nous permet juste de réutiliser les fonctions deja implémentées(beneficier du polymorphisme)
        Complexe* res= new Complexe(this->soustraction(*ptComplexe->getPartEnt()), temp.multiplication(*ptComplexe->getPartIm()));
        LitteraleNombre& ref = *res;
        return ref;*/
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) - (*ptComplexe);
        return res;
    }
}


LitteraleNombre& Entier::multiplication(const LitteraleNombre& lit) const {
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
    else {
        /*Complexe* res= new Complexe(this->multiplication(*ptComplexe->getPartEnt()), this->multiplication(*ptComplexe->getPartIm()));
        LitteraleNombre& ref = *res;
        return ref;*/
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) * (*ptComplexe);
        return res;
    }
}





LitteraleNombre& Entier::division(const LitteraleNombre& lit) const {
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
    else {
            Complexe* temp = this->toComplexe();
            LitteraleNombre& res= (*temp) / (*ptComplexe);
            return res;
    }
}





QString Entier::toString() const {
    QString s;
    s.setNum(valeur);
    return s;
}


Complexe* Entier::toComplexe() const {
    // Entier -> Complexe
    const LitteraleNombre& re = *this;
    //Ici on "encapsule" notre entier dans un Complexe de telle sorte a pouvoir beneficier du code qu'on a fait dans la classe complexe
    //Le fait de convertir notre entier en Complexe => on se ramene au cas deja traité Complexe+complexe dans la classe Complexe
    //On s'affranchit des erreurs de recopie pour profiter du code stable deja existant
    const LitteraleNombre& im = *(new Entier(0));
    Complexe* res = new Complexe(re,im);
    return (res);
}

