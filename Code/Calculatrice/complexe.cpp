#include "complexe.h"

#include "entier.h"
#include "calculatriceexception.h"
#include "reel.h"
#include "rationnel.h"



Complexe::Complexe(const LitteraleNombre& re, const LitteraleNombre& im) {
    const LitteraleNum* tmpRe = dynamic_cast<const LitteraleNum*>(&re);
    const LitteraleNum* tmpIm = dynamic_cast<const LitteraleNum*>(&im);
    if (tmpRe == 0 || tmpIm == 0) {
        CALCULATRICE_EXCEPTION("Construction du complexe impossible (2 Nombres NonComplexe nécessaires !)");
    } else {
        partEnt = tmpRe;
        partIm = tmpIm;
    }
}

QString Complexe::toString() const {
    return partEnt->toString() + "$" + partIm->toString();
}

Complexe* Complexe::clone() const {
    Litterale* tmpEnt = partEnt->clone();
    Litterale* tmpIm = partIm->clone();

    LitteraleNum* pEnt = dynamic_cast<LitteraleNum*>(tmpEnt);
    LitteraleNum* pIm = dynamic_cast<LitteraleNum*>(tmpIm);

    return new Complexe(*pEnt, *pIm);
}


LitteraleNombre& Complexe::addition(const LitteraleNombre& lit) const {
    //Complexe + Complexe = complexe
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
        // Complexe + int = complexe
        if (ptEntier == 0) {
            //Complexe + rationnel = complexe
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    //Complexe + reel = complexe
                    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                        if (ptReel ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else {
                            Complexe* res= new Complexe(partEnt->addition(*ptReel), *partIm);
                            LitteraleNombre& ref = *res;
                            return ref;
                        }
                }
                else {
                    Complexe* res= new Complexe(partEnt->addition(*ptRationnel), *partIm);
                    LitteraleNombre& ref = *res;
                    return ref;
                }
        }
        else {
            Complexe* res= new Complexe(partEnt->addition(*ptEntier), *partIm);
            LitteraleNombre& ref = *res;
            return ref;
        }
    }
    else {
        Complexe* res= new Complexe(partEnt->addition(*ptComplexe->getPartEnt()), partIm->addition(*ptComplexe->getPartIm()));
        LitteraleNombre& ref = *res;
        return ref;
    }
}

LitteraleNombre& Complexe::soustraction(const LitteraleNombre& lit) const {
    //Complexe + Complexe = complexe
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
        // Complexe + int = complexe
        if (ptEntier == 0) {
            //Complexe + rationnel = complexe
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    //Complexe + reel = complexe
                    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                        if (ptReel ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else {
                            Complexe* res= new Complexe(partEnt->soustraction(*ptReel), *partIm);
                            LitteraleNombre& ref = *res;
                            return ref;
                        }
                }
                else {
                    Complexe* res= new Complexe(partEnt->soustraction(*ptRationnel), *partIm);
                    LitteraleNombre& ref = *res;
                    return ref;
                }
        }
        else {
            Complexe* res= new Complexe(partEnt->soustraction(*ptEntier), *partIm);
            LitteraleNombre& ref = *res;
            return ref;
        }
    }
    else {
        Complexe* res= new Complexe(partEnt->soustraction(*ptComplexe->getPartEnt()), partIm->soustraction(*ptComplexe->getPartIm()));
        LitteraleNombre& ref = *res;
        return ref;
    }
}



LitteraleNombre& Complexe::multiplication(const LitteraleNombre& lit) const {
    //Complexe + Complexe = complexe
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
        // Complexe + int = complexe
        if (ptEntier == 0) {
            //Complexe + rationnel = complexe
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    //Complexe + reel = complexe
                    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                        if (ptReel ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else {
                            Complexe* res= new Complexe(partEnt->multiplication(*ptReel), *partIm);
                            LitteraleNombre& ref = *res;
                            return ref;
                        }
                }
                else {
                    Complexe* res= new Complexe(partEnt->multiplication(*ptRationnel), *partIm);
                    LitteraleNombre& ref = *res;
                    return ref;
                }
        }
        else {
            Complexe* res= new Complexe(partEnt->multiplication(*ptEntier), *partIm);
            LitteraleNombre& ref = *res;
            return ref;
        }
    }
    else {
        Complexe* res= new Complexe(((partEnt->multiplication(*ptComplexe->getPartEnt()))-(partIm->multiplication(*ptComplexe->getPartIm()))), ((partEnt->multiplication(*ptComplexe->getPartIm()))+(partIm->multiplication(*ptComplexe->getPartEnt()))));
        LitteraleNombre& ref = *res;
        return ref;
    }
}



LitteraleNombre& Complexe::division(const LitteraleNombre& lit) const {
    //Complexe + Complexe = complexe
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
        // Complexe + int = complexe
        if (ptEntier == 0) {
            //Complexe + rationnel = complexe
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
                if (ptRationnel == 0) {
                    //Complexe + reel = complexe
                    const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                        if (ptReel ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else {
                            Complexe* res= new Complexe(partEnt->division(*ptReel), *partIm);
                            LitteraleNombre& ref = *res;
                            return ref;
                        }
                }
                else {
                    Complexe* res= new Complexe(partEnt->division(*ptRationnel), *partIm);
                    LitteraleNombre& ref = *res;
                    return ref;
                }
        }
        else {
            Complexe* res= new Complexe(partEnt->division(*ptEntier), *partIm);
            LitteraleNombre& ref = *res;
            return ref;
        }
    }
    else {
        LitteraleNombre& tmpRe = ((partEnt->multiplication(*ptComplexe->getPartEnt())).addition(partIm->multiplication(*ptComplexe->getPartIm()))).division(((*ptComplexe->getPartEnt()).multiplication(*ptComplexe->getPartEnt())).addition(((*ptComplexe->getPartIm()).multiplication(*ptComplexe->getPartIm()))));
        LitteraleNombre& tmpIm = ((partIm->multiplication(*ptComplexe->getPartEnt())).soustraction(partEnt->multiplication(*ptComplexe->getPartIm()))).division(((*ptComplexe->getPartEnt()).multiplication(*ptComplexe->getPartEnt())).addition(((*ptComplexe->getPartIm()).multiplication(*ptComplexe->getPartIm()))));

        Complexe* res= new Complexe(tmpRe, tmpIm);
        LitteraleNombre& ref = *res;
        return ref;
    }
}







