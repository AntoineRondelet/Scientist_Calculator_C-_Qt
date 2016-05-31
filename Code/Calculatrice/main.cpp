#include "mainwindow.h"
#include <QApplication>
#include "pile.h"
#include "litterale.h"
#include "reel.h"
#include "entier.h"
#include "rationnel.h"
#include "atome.h"
#include "analyser.h"
#include "controleur.h"
#include "calculatriceexception.h"
#include <QTextStream>

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include<QStringList>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */

/*
   try {
        Pile& stack = Pile::getInstance();
        Controleur controle(stack);
        controle.boucleExcecution();
    }
    catch (CalculatriceException &e) {
        cout << e.what();
    }
    catch (...) {
        cout << "On a catch" << endl;
    }
*/

    cout << "TESTTT" << endl;

/* ------------ CA MARCHE ------------
    //"(?:'[^']+')" -> with group 0
    QRegularExpression re("(?:'[^']+')");
    QRegularExpressionMatchIterator i = re.globalMatch("3+4 SIN(3x+10)'");
    QStringList words;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(0);
        words << word;
    }
    while(words.empty() == false) {
       QString mot = words.takeFirst();
       cout << mot.toStdString() << endl;
    }
*/
    /* MARCHEEEEEE DEFINITIVEMENT*/
   // QStringList words;
/*
    QString mot;
    string test;

    cout << "Entrez un mot ! " << endl;
    QString word;
    string phrase;
    getline(cin,phrase);
    cout << phrase << endl;
    QRegularExpression re("(?:'[^']+')");
    QRegularExpressionMatch str_match = re.match(QString::fromStdString(phrase));
    if(str_match.hasMatch()) {
        mot = str_match.captured(0);
    }
    cout << " ----- MATCH ----- " << endl;
    cout << mot.remove(QRegularExpression("\\s+$")).toStdString() << endl;
    //A voir pour afficher la QString matchées sans espaces a l'interieur -> Pour l'affichage
*/

    QTextStream cin(stdin);
    QTextStream cout(stdout);

    QString test;


    cout << "Enter another value: ";
    cout.flush();
    cin.skipWhiteSpace(); //Important line!
    test = cin.readLine();
    cout << test;

/*
 *
 * QTextStream qtin(stdin);
QString line = qtin.readLine();  // This is how you read the entire line

QString word;
qtin >> word;


QString line;
QStringList list = line.split(":");
*/




//CES DEUX LA A FUSIONNER POUR MATCHER LES EXPRESSIONS



    /* MARCHEEEEEE*/
   /* QStringList words;
    QString mot;
    QRegularExpression re("(?:'[^']+')");
    QRegularExpressionMatch str_match = re.match(QString::fromStdString("'3+4 SIN(3x+10) 0'"));
    if(str_match.hasMatch()) {
        //words = str_match.capturedTexts();
        mot = str_match.captured(0);
    }
    QString str_expression = words.join("BLABLA");
    cout << mot.toStdString() << endl;

    while(words.empty() == false) {
       QString mot = words.takeFirst();
       cout << mot.toStdString() << endl;
    }
*/
/*

//SI j'arrive a fusionner celle ci et celle du dessus -> ca devrait etre bon pour matcher les expressions->celle ci serait a modifier pour l'adapter au matching des entier etc
    QRegularExpression re("'|(\\w+)|[[:digit:]]|[[:alnum:]]|\\+|\\-");
    QRegularExpressionMatchIterator i = re.globalMatch("'the quick fox -34+X2'");
    QStringList words;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(0);
        words << word;
    }
    while(words.empty() == false) {
       QString mot = words.takeFirst();
       cout << mot.toStdString() << endl;
    }

    // words contains "the", "quick", "fox"


*/


    /* MARCHEEEEEE DEFINITIVEMENT*/
   // QStringList words;
   /*
    QString mot;
    string test;

    cout << "Entrez un mot ! " << endl;
    //cin >> test; //"'3+4 SIN(3x+10) 0'"
    QString word;
    string phrase;
    getline(cin,phrase);
    cout << phrase << endl;
    //cout << "test vaut : " << word.toStdString() << endl;
    QRegularExpression re("(?:'[^']+')");
    QRegularExpressionMatch str_match = re.match(QString::fromStdString(phrase));
    if(str_match.hasMatch()) {
        //words = str_match.capturedTexts();
        mot = str_match.captured(0);
    }
    //QString str_expression = words.join("BLABLA");
    cout << " ----- MATCH ----- " << endl;
    cout << mot.toStdString() << endl;
    //A voir pour afficher la QString matchées sans espaces a l'interieur -> Pour l'affichage
    */

    /*while(words.empty() == false) {
       QString mot = words.takeFirst();
       cout << mot.toStdString() << endl;
    }*/








    return 0;
}
