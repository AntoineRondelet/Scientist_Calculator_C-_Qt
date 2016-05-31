#include"rationnel.h"
#include"calculatriceexception.h"
#include "reel.h"
#include "entier.h"


Rationnel::Rationnel(int num, int den): numerateur(num), denominateur(den) {
    if (this->denominateur!=0) this->denominateur = den;
    else CALCULATRICE_EXCEPTION("Erreur Creation: Denominateur nul");
    this->simplification();
}

void Rationnel::simplification(){
  if (numerateur==0) {
    denominateur=1;
    return;
  }
  //un denominateur ne devrait pas être 0; si c’est le cas, on sort de la methode
  if (denominateur==0)
    return;

  //utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun Denominateur (PGCD) entre le numerateur et le denominateur
  int a=numerateur;
  int b=denominateur;

  // on ne travaille qu’avec des valeurs positives...
  if (a<0) a=-a;
  if (b<0) b=-b;

  while(a!=b)
  {
    if (a>b) a=a-b;
    else b=b-a;
  }

  // on divise le numerateur et le denominateur par le PGCD=a
  numerateur/=a; denominateur/=a;
  // si le denominateur est negatif, on fait passer le signe - au denominateur
  if (denominateur<0)
  {
    denominateur=-denominateur;
    numerateur=-numerateur;
  }
}


QString Rationnel::toString() const {
    QString s1, s2, s;
    s1.setNum(numerateur);
    s2.setNum(denominateur);

    if (denominateur != 1)
        s = s1 + '/' + s2;
    else s = s1;
    return s;
}


LitteraleNombre& Rationnel::addition(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
        //Ici on teste l'addition d'un Rationnel avec un Rationnel -> Il faudrait aussi pouvoir faire Rationnel+entier et Rationnel+rationnel
        if (ptRationnel == 0) { // => lit n'est pas un Rationnel: On essaie de la convertir en Rationnel
            const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                if (ptReel == 0) {
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                        if (ptEntier ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else { //cf: enoncé page 4 -> on renvoie un int si apres simplification on a un den = 1
                            Rationnel* res= new Rationnel(numerateur+ptEntier->getValeur()*denominateur, denominateur);
                            res->simplification();
                            if (res->denominateur== 1) {
                                Entier* resultat = new Entier(res->numerateur);
                                LitteraleNombre& ref = *resultat;
                                return ref;
                            }
                            else {
                                LitteraleNombre& ref = *res;
                                return ref;
                            }
                        }
                }
                else {
                    //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                    Reel* res= new Reel(ptReel->getValue()+(static_cast<float>(numerateur)/denominateur));
                    LitteraleNombre& ref = *res;
                    return ref;
                }
        }
        else { //cf: enoncé page 4 -> on renvoie un int si apres simplification on a un den = 1
            Rationnel* res= new Rationnel(numerateur*ptRationnel->denominateur+ptRationnel->numerateur*denominateur, denominateur*ptRationnel->denominateur);
            res->simplification();
            if (res->denominateur== 1) {
                Entier* resultat = new Entier(res->numerateur);
                LitteraleNombre& ref = *resultat;
                return ref;
            }
            else {
                LitteraleNombre& ref = *res;
                return ref;
            }
        }
    }
    else {
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) + (*ptComplexe);
        return res;
    }
}





LitteraleNombre& Rationnel::soustraction(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
        //Ici on teste l'addition d'un Rationnel avec un Rationnel -> Il faudrait aussi pouvoir faire Rationnel+entier et Rationnel+rationnel
        if (ptRationnel == 0) { // => lit n'est pas un Rationnel: On essaie de la convertir en Rationnel
            const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                if (ptReel == 0) {
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                        if (ptEntier ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else { //cf: enoncé page 4 -> on renvoie un int si apres simplification on a un den = 1
                            Rationnel* res= new Rationnel(numerateur-ptEntier->getValeur()*denominateur, denominateur);
                            res->simplification();
                            if (res->denominateur== 1) {
                                Entier* resultat = new Entier(res->numerateur);
                                LitteraleNombre& ref = *resultat;
                                return ref;
                            }
                            else {
                                LitteraleNombre& ref = *res;
                                return ref;
                            }
                        }
                }
                else {
                    //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                    Reel* res= new Reel(ptReel->getValue()-(static_cast<float>(numerateur)/denominateur));
                    LitteraleNombre& ref = *res;
                    return ref;
                }
        }
        else { //cf: enoncé page 4 -> on renvoie un int si apres simplification on a un den = 1
            Rationnel* res= new Rationnel(numerateur*ptRationnel->denominateur-ptRationnel->numerateur*denominateur, denominateur*ptRationnel->denominateur);
            res->simplification();
            if (res->denominateur== 1) {
                Entier* resultat = new Entier(res->numerateur);
                LitteraleNombre& ref = *resultat;
                return ref;
            }
            else {
                LitteraleNombre& ref = *res;
                return ref;
            }
        }
    }
    else {
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) - (*ptComplexe);
        return res;
    }
}





LitteraleNombre& Rationnel::multiplication(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
        //Ici on teste l'addition d'un Rationnel avec un Rationnel -> Il faudrait aussi pouvoir faire Rationnel+entier et Rationnel+rationnel
        if (ptRationnel == 0) { // => lit n'est pas un Rationnel: On essaie de la convertir en Rationnel
            const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                if (ptReel == 0) {
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                        if (ptEntier ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else { //cf: enoncé page 4 -> on renvoie un int si apres simplification on a un den = 1
                            Rationnel* res= new Rationnel(numerateur*ptEntier->getValeur(), denominateur);
                            res->simplification();
                            if (res->denominateur== 1) {
                                Entier* resultat = new Entier(res->numerateur);
                                LitteraleNombre& ref = *resultat;
                                return ref;
                            }
                            else {
                                LitteraleNombre& ref = *res;
                                return ref;
                            }
                        }
                }
                else {
                    //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                    Reel* res= new Reel(ptReel->getValue()*(static_cast<float>(numerateur)/denominateur));
                    LitteraleNombre& ref = *res;
                    return ref;
                }
        }
        else { //cf: enoncé page 4 -> on renvoie un int si apres simplification on a un den = 1
            Rationnel* res= new Rationnel(numerateur*ptRationnel->numerateur, denominateur*ptRationnel->denominateur);
            res->simplification();
            if (res->denominateur== 1) {
                Entier* resultat = new Entier(res->numerateur);
                LitteraleNombre& ref = *resultat;
                return ref;
            }
            else {
                LitteraleNombre& ref = *res;
                return ref;
            }
        }
    }
    else {
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) * (*ptComplexe);
        return res;
    }
}







LitteraleNombre& Rationnel::division(const LitteraleNombre& lit) const {
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&lit);
    if (ptComplexe == nullptr) {
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&lit);
        //Ici on teste l'addition d'un Rationnel avec un Rationnel -> Il faudrait aussi pouvoir faire Rationnel+entier et Rationnel+rationnel
        if (ptRationnel == 0) { // => lit n'est pas un Rationnel: On essaie de la convertir en Rationnel
            const Reel* ptReel = dynamic_cast<const Reel*>(&lit);
                if (ptReel == 0) {
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&lit);
                        if (ptEntier ==  0) {
                            CALCULATRICE_EXCEPTION("ERREUR: Dynamic_cast");
                        }
                        else { //cf: enoncé page 4 -> on renvoie un int si apres simplification on a un den = 1
                            Rationnel* res= new Rationnel(numerateur, denominateur*ptEntier->getValeur());
                            res->simplification();
                            if (res->denominateur== 1) {
                                Entier* resultat = new Entier(res->numerateur);
                                LitteraleNombre& ref = *resultat;
                                return ref;
                            }
                            else {
                                LitteraleNombre& ref = *res;
                                return ref;
                            }
                        }
                }
                else {
                    //ATTENTION, on oublie pas le static_cast<> pour contourner le probleme de la division de 2 int
                    Reel* res= new Reel((static_cast<float>(numerateur)/denominateur)/ptReel->getValue());
                    LitteraleNombre& ref = *res;
                    return ref;
                }
        }
        else { //cf: enoncé page 4 -> on renvoie un int si apres simplification on a un den = 1
            Rationnel* res= new Rationnel(numerateur*ptRationnel->denominateur, denominateur*ptRationnel->numerateur);
            res->simplification();
            if (res->denominateur== 1) {
                Entier* resultat = new Entier(res->numerateur);
                LitteraleNombre& ref = *resultat;
                return ref;
            }
            else {
                LitteraleNombre& ref = *res;
                return ref;
            }
        }
    }
    else {
        Complexe* temp = this->toComplexe();
        LitteraleNombre& res= (*temp) * (*ptComplexe);
        return res;
    }
}



Complexe* Rationnel::toComplexe() const {
    const LitteraleNombre& re = *this;
    const LitteraleNombre& im = *(new Rationnel(0));
    Complexe* res = new Complexe(re,im);
    return (res);
}

