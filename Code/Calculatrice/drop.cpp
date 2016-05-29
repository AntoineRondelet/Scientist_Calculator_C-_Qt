#include "drop.h"
#include "pile.h"


void Drop::execute(QVector<Litterale*> litterals) const{
    delete litterals[0];
}


//Explications:
/*
Etant un operateur unaire, on depile "automatiquement" 1 litterale de la pile. L'execution de cet operateur vide juste a aller
liberer la memoire occupée par cette Litterale
*/
