/*
#include "complexe.h"
#include "entier.h"
#include "calculatriceexception.h"
#include "reel.h"
#include "rationnel.h"
*/

/*
 * Complexe::Complexe(const LitteraleNum& re, const LitteraleNum& im) {
    //On veut construire la partie entiere !
    //On ne peut pas utiliser une liste d'initialisation car on ne sait pas quel type créer ! On doit faire des test de dynamic_cast
    const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&re);
    if (ptRationnel == 0) {
        const Reel* ptReel = dynamic_cast<const Reel*>(&re);
            if (ptReel == 0) {
                const Entier* ptEntier = dynamic_cast<const Entier*>(&re);
                    if (ptEntier ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        partRe= new Entier(ptEntier->getValeur());
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                partRe= new Reel(ptReel->getValue());
            }
    }
    else {
        partRe= new Rationnel(ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
    }

    // On construit la partie Imaginaire
    const Rationnel* ptRationnelIm = dynamic_cast<const Rationnel*>(&im);
    if (ptRationnelIm == 0) {
        const Reel* ptReelIm = dynamic_cast<const Reel*>(&im);
            if (ptReelIm == 0) {
                const Entier* ptEntierIm = dynamic_cast<const Entier*>(&im);
                    if (ptEntierIm ==  0) {
                        throw CalculatriceException("ERREUR: Dynamic_cast");
                    }
                    else {
                        partIm= new Entier(ptEntierIm->getValeur());
                    }
            }
            else {
                //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                partIm= new Reel(ptReelIm->getValue());
            }
    }
    else {
        partIm= new Rationnel(ptRationnelIm->getNumerateur(), ptRationnelIm->getDenominateur());
    }
}
*/

/*
Complexe::Complexe(const LitteraleNombre& re, const LitteraleNombre& im) {
    LitteraleNum* tmpRe = dynamic_cast<LitteraleNum*>(&re);
    LitteraleNum* tmpIm = dynamic_cast<LitteraleNum*>(&im);
    if (tmpRe == 0 || tmpIm == 0) {
        throw CalculatriceException("Construction du complexe impossible (2 litterales non complexes nécessaires !)");
    } else {
        partRe = tmpRe;
        partIm = tmpIm;
    }
}
*/


/*string Complexe::toString() const {
    stringstream s;
    if (this->getImagin() != 0) s<<this->getReelle()<<" + "<<this->getImagin() << 'i';
    else s<<this->getReelle();
    return s.str();
}*/



/*LitteraleNombre& Complexe::addition(const LitteraleNombre& lit) const {
    LitteraleNombre& ref;
    return ref;
}*/

/*LitteraleNombre& Complexe::soustraction(const LitteraleNombre& lit) const {
    Reel* res= new Reel(lit.getVa)
    LitteraleNombre& ref;
    return ref;
}


LitteraleNombre& Complexe::multiplication(const LitteraleNombre& lit) const {
    LitteraleNombre& ref;
    return ref;
}


LitteraleNombre& Complexe::division(const LitteraleNombre& lit) const {
    LitteraleNombre& ref;
    return ref;
}*/
