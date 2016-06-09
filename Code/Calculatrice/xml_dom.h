#ifndef XML_DOM_H
#define XML_DOM_H

#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMessageBox>

class Xml_Dom : public QWidget{
    Q_OBJECT

    public:
    Xml_Dom();
    ~Xml_Dom();
    // On rajoutera des variables et des méthodes après.

public slots:
    void saveXML();
    void RestoreXML();
};

#endif // XML_DOM_H
