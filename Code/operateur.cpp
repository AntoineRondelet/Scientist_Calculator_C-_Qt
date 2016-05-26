#include "operateur.h"
#include "identificateurtable.h"
#include "litteralemanager.h"
#include "litteralenombre.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "pile.h"
#include <QMap>
#include <QMapIterator>


Litterale* Operateur::executerOp() const {
    //Quand on construit un nouvel opérateur: on verifie s'il est dans la table des identificateurs

    /*if (operateurBinaire) {
        Pile* ptr_stack = &Pile::getInstance();
        LitteraleManager* ptr_lit_man = &LitteraleManager::getInstance();

        Litterale& v1 = ptr_stack->top();
        cout << "V1: " << v1.toString() << endl;
        ptr_stack->pop();
        ptr_lit_man->removeLitterale(v1);
        ptr_stack->affiche();

        Litterale& v2 = ptr_stack->top();
        cout << "V2: " << v2.toString() << endl;
        ptr_stack->pop();
        ptr_lit_man->removeLitterale(v2);
        ptr_stack->affiche();

        LitteraleNombre* nbrev1 = dynamic_cast<LitteraleNombre *>(&v1);
        if (nbrev1 == 0) {
            cout << "Erreur: Operateur Numerique sur une litterale qui n'est pas un nombre" << endl;
            ptr_stack->push(v1);
            ptr_stack->push(v2);
            return nullptr;
        }
        LitteraleNombre* nbrev2 = dynamic_cast<LitteraleNombre *>(&v2); //Pour faire une operation numerique sur nos elements depilés, il faut qu'il s'agisse de nombres.
        if (nbrev2 == 0) {
            cout << "Erreur: Operateur Numerique sur une litterale qui n'est pas un nombre" << endl;
            ptr_stack->push(v1);
            ptr_stack->push(v2);
            return nullptr;
        }
        if (Opname == "ADD") {
            Litterale& res = (*nbrev1) + (*nbrev2);
        }
        else if (Opname == "SOUS") {
            Litterale& res = (*nbrev1) - (*nbrev2);
        }
        else if (Opname == "MULT") {
            Litterale& res = (*nbrev1) * (*nbrev2);
        }
        else {
            cout << "ERREUR !" << endl;
        }
        const Reel* ptReel = dynamic_cast<const Reel*>(&res);
        if (ptReel == 0) {
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&res);
                if (ptRationnel == 0) {
                    const Entier* ptEntier = dynamic_cast<const Entier*>(&res);
                        if (ptEntier ==  0) throw CalculatriceException("ERREUR Operateur.cpp: Dynamic_cast");
                        else {
                            Litterale* e = ptr_lit_man->addLitteraleEntiere(ptEntier->getValeur());
                            return e;
                        }
                }
                else {
                    Litterale* e = ptr_lit_man->addLitteraleRationnelle(ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
                    return e;
                }
        }
        else {
            Litterale* e = ptr_lit_man->addLitteraleReelle(ptReel->getValue());
            return e;
        }
    }
}
*/
        if (Opname == "ADD") {
            Pile* ptr_stack = &Pile::getInstance();
            LitteraleManager* ptr_lit_man = &LitteraleManager::getInstance();

            // Ce qu'on pop de la pile c'est des Litterale --> Or, on veut pouvoir les sommer ici, donc il nous
            // les faut convertir en LitteraleNombre

            /**** ON PEUT FACTORISER CETTE PARTIE pour chauqe opérateur binaire ****/
            Litterale& v1 = ptr_stack->top();
            cout << "V1: " << v1.toString() << endl;
            ptr_stack->pop();
            ptr_lit_man->removeLitterale(v1);
            ptr_stack->affiche();


            Litterale& v2 = ptr_stack->top();
            cout << "V2: " << v2.toString() << endl;
            ptr_stack->pop();
            ptr_lit_man->removeLitterale(v2);
            ptr_stack->affiche();


            LitteraleNombre* nbrev1 = dynamic_cast<LitteraleNombre *>(&v1);
            if (nbrev1 == 0) {
                cout << "pas un nombre" << endl;
                ptr_stack->push(v1);
                ptr_stack->push(v2);
                return nullptr;
            }

            LitteraleNombre* nbrev2 = dynamic_cast<LitteraleNombre *>(&v2);
            if (nbrev2 == 0) {
                cout << "PAS UN NOMBRE" << endl;
                ptr_stack->push(v1);
                ptr_stack->push(v2);
                return nullptr;
            }
            /**** FIN DE LA PARTIE FACTORISABLE ****/

            Litterale& res = (*nbrev1) + (*nbrev2); //On teste le type de res -> pour savoir quel objet construire

            /*** FACTORISABLE AUSSI ***/
            const Reel* ptReel = dynamic_cast<const Reel*>(&res);
            if (ptReel == 0) {
                const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&res);
                    if (ptRationnel == 0) {
                        const Entier* ptEntier = dynamic_cast<const Entier*>(&res);
                            if (ptEntier ==  0) throw CalculatriceException("ERREUR Operateur.cpp: Dynamic_cast");
                            else {
                                Litterale* e = ptr_lit_man->addLitteraleEntiere(ptEntier->getValeur());
                                return e;
                            }
                    }
                    else {
                        Litterale* e = ptr_lit_man->addLitteraleRationnelle(ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
                        return e;
                    }
            }
            else {
                Litterale* e = ptr_lit_man->addLitteraleReelle(ptReel->getValue());
                return e;
            }
          /*** FIN DE FACTORISABLE AUSSI ***/

        }
        else if (Opname == "SOUS") {
            Pile* ptr_stack = &Pile::getInstance();
            LitteraleManager* ptr_lit_man = &LitteraleManager::getInstance();

            Litterale& v1 = ptr_stack->top();
            cout << "V1: " << v1.toString() << endl;
            ptr_stack->pop();
            ptr_lit_man->removeLitterale(v1);
            ptr_stack->affiche();


            Litterale& v2 = ptr_stack->top();
            cout << "V2: " << v2.toString() << endl;
            ptr_stack->pop();
            ptr_lit_man->removeLitterale(v2);
            ptr_stack->affiche();


            LitteraleNombre* nbrev1 = dynamic_cast<LitteraleNombre *>(&v1);
            if (nbrev1 == 0) {
                cout << "pas un nombre" << endl;
                ptr_stack->push(v1);
                ptr_stack->push(v2);
                return nullptr;
            }

            LitteraleNombre* nbrev2 = dynamic_cast<LitteraleNombre *>(&v2);
            if (nbrev2 == 0) {
                cout << "PAS UN NOMBRE" << endl;
                ptr_stack->push(v1);
                ptr_stack->push(v2);
                return nullptr;
            }

            Litterale& res = (*nbrev1) - (*nbrev2); //On teste le type de res -> pour savoir quel objet construire


            const Reel* ptReel = dynamic_cast<const Reel*>(&res);
            if (ptReel == 0) {
                const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&res);
                    if (ptRationnel == 0) {
                        const Entier* ptEntier = dynamic_cast<const Entier*>(&res);
                            if (ptEntier ==  0) throw CalculatriceException("ERREUR Operateur.cpp: Dynamic_cast");
                            else {
                                Litterale* e = ptr_lit_man->addLitteraleEntiere(ptEntier->getValeur());
                                return e;
                            }
                    }
                    else {
                        Litterale* e = ptr_lit_man->addLitteraleRationnelle(ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
                        return e;
                    }
            }
            else {
                Litterale* e = ptr_lit_man->addLitteraleReelle(ptReel->getValue());
                return e;
            }
        }
        else {
            cout << "Erreur" << endl;
            return nullptr;
        }

}


