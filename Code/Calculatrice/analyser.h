#ifndef ANALYSER_H
#define ANALYSER_H

#include<QMap>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include<QStringList>
#include<QString>
#include <functional>

#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "atome.h"
#include"entieranalyser.h"

#include "litterale.h"

typedef std::function<Litterale*(QRegularExpressionMatch)> func_t;
//C++11: Pour appeller nos "pointers" vers les focntions qui vont nous construire nos Litterales en fonctions des matchs des regex

class Analyser {
    QMap<QString, func_t> m_matchers; //QMap pour a construction et les regex
public:
    Analyser(): m_matchers(QMap<QString, func_t>()){}
    void init();
    Litterale* reconnaitre(const string& src);
};

#endif // ANALYSER_H
