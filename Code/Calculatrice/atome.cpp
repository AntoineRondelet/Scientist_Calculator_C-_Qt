#include "atome.h"

string Atome::toString() const {
    stringstream s;
    s<<name.toStdString();
    return s.str();
}
