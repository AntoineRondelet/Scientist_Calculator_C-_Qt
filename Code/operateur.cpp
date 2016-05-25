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

/*
void Operateur::executerOp() const {
    //Quand on construit un nouvel opérateur: on verifie s'il est dans la table des identificateurs

        if (Opname == "ADD") {
            Pile* ptr_stack = &Pile::getInstance();
            LitteraleManager* ptr_lit_man = &LitteraleManager::getInstance();

            // Ce qu'on pop de la pile c'est des Litterale --> Or, on veut pouvoir les sommer ici, donc il nous
            // les faut convertir en LitteraleNombre
            Litterale& v1 = ptr_stack->top();
            cout << "V1: " << v1.toString() << endl;
            ptr_stack->pop();
            ptr_lit_man->removeLitterale(ptr_stack->top());
            ptr_stack->affiche();


            Litterale& v2 = ptr_stack->top();
            cout << "V2: " << v2.toString() << endl;
            ptr_stack->pop();
            ptr_lit_man->removeLitterale(ptr_stack->top());
            ptr_stack->affiche();


            LitteraleNombre* nbrev1 = dynamic_cast<LitteraleNombre *>(&v1);
            if (nbrev1 == 0) {
                cout << "pas un nombre" << endl;
                ptr_stack->push(v1);
                ptr_stack->push(v2);
                return;
            }

            LitteraleNombre* nbrev2 = dynamic_cast<LitteraleNombre *>(&v2);
            if (nbrev2 == 0) {
                cout << "pas un nombre" << endl;
                ptr_stack->push(v1);
                ptr_stack->push(v2);
                return;
            }

            Litterale& res = (*nbrev1) + (*nbrev2); //On teste le type de res -> pour savoir quel objet construire


            const Reel* ptReel = dynamic_cast<const Reel*>(&res);
            if (ptReel == 0) {
                const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&res);
                    if (ptRationnel == 0) {
                        const Entier* ptEntier = dynamic_cast<const Entier*>(&res);
                            if (ptEntier ==  0) throw CalculatriceException("ERREUR Operateur.cpp: Dynamic_cast");
                            else {
                                Litterale* e = ptr_lit_man->addLitteraleEntiere(ptEntier->getValeur());
                                ptr_stack->push(*e);
                            }
                    }
                    else {
                        Litterale* e = ptr_lit_man->addLitteraleRationnelle(ptRationnel->getNumerateur(), ptRationnel->getDenominateur());
                        ptr_stack->push(*e);
                    }
            }
            else {
                Litterale* e = ptr_lit_man->addLitteraleReelle(ptReel->getValue());
                ptr_stack->push(*e);
            }
        }
        else {
            cout << "On est dans le default du switch" << endl;
        }
}
*/

