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
#include"entieranalyser.h"

#include "litterale.h"

typedef std::function<Litterale*(QRegularExpressionMatch)> func_t;


class Analyser {
    //QMap<QString, EntierAnalyseur> m_matchers;
    QMap<QString, func_t> m_matchers;
public:
    //Analyser(): m_matchers(QMap<QString, EntierAnalyseur>()){}
    Analyser(): m_matchers(QMap<QString, func_t>()){}
    void init();
    //string reconnaitre(const string& src);
    Litterale* reconnaitre(const string& src);
};

#endif // ANALYSER_H
