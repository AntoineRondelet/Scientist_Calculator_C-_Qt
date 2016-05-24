#include "item.h"
#include "calculatriceexception.h"


Litterale& Item::getLitterale() const{
        if (item_lit==0) throw CalculatriceException("Erreur Item: Acces à une Litterale inexistante");
        return *item_lit;
}
