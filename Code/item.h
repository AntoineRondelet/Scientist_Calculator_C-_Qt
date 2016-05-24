#ifndef ITEM_H
#define ITEM_H

#include "litterale.h"

//Un item c'est ce qui est empilé sur la pile -> pointe sur une litterale
class Item {
    Litterale* item_lit;
public:
    Item():item_lit(0){}

    void setLitterale(Litterale& e) { item_lit=&e; } //on a e qui est une reference (PAS const) car on part du principe qu'on pourra modifier la valeur pointée a travers elle
    void raz() { item_lit=0; } //Foncton de remise a zero

    Litterale& getLitterale() const; //Permet d'avoir la valeur pointée par notre item_lit
    ~Item(){}
};

#endif // ITEM_H
