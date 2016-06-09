#include "xml_dom.h"

#include <iostream>
using namespace std;
#include <QFileDialog>
#include <QFile>

#include "pile.h"
#include "identificateurmanager.h"

Xml_Dom::Xml_Dom() : QWidget(){}

Xml_Dom::~Xml_Dom(){}


void Xml_Dom::saveXML() {
    QString filename = QFileDialog::getSaveFileName(this,tr("Save Xml"), ".",tr("Xml files (*.xml)"));
    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    Pile& stack = Pile::getInstance();
    IdentificateurManager& id_man = IdentificateurManager::getInstance();

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("SAVE");

    xmlWriter.writeStartElement("STACK");

    xmlWriter.writeStartElement("Litterale");

    QStack<Litterale*>::iterator i;
    for (i = stack.begin(); i != stack.end(); ++i) {
        // -- On recupere notre litterale -- //
        Litterale *cur_lit = *i;
        // -- On teste le type de notre litterale -- //
        Entier* litEnt = dynamic_cast<Entier*>(cur_lit);
        Reel* litRe = dynamic_cast<Reel*>(cur_lit);
        Rationnel* litRa = dynamic_cast<Rationnel*>(cur_lit);
        Complexe* litCpx = dynamic_cast<Complexe*>(cur_lit);
        Atome* litAt = dynamic_cast<Atome*>(cur_lit);
        Expression* litExp = dynamic_cast<Expression*>(cur_lit);
        Programme* litPg = dynamic_cast<Programme*>(cur_lit);

        if(litEnt != nullptr) {
            xmlWriter.writeTextElement("Entier", litEnt->toString());
        }
        else if (litRe !=  nullptr) {
            xmlWriter.writeTextElement("Reel", litRe->toString());
        }
        else if (litRa !=  nullptr) {
            xmlWriter.writeTextElement("Rationnel", litRa->toString());
        }
        else if (litCpx !=  nullptr) {
            xmlWriter.writeTextElement("Complexe", litCpx->toString());
        }
        else if (litAt !=  nullptr) {
            xmlWriter.writeTextElement("Atome", litAt->toString());
        }
        else if (litExp !=  nullptr) {
            xmlWriter.writeTextElement("Expression", litExp->toString());
        }
        else if (litPg !=  nullptr) {
            xmlWriter.writeTextElement("Programme", litPg->toString());
        }
        else {
            CALCULATRICE_EXCEPTION("MEGA BUG SUR LE XML");
        }
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
/*
    xmlWriter.writeTextElement("Entier", "lit3value");
    xmlWriter.writeTextElement("Reel", "lit3value");
    xmlWriter.writeTextElement("Litterale", "lit3value");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("IDs");

    xmlWriter.writeTextElement("Identifiant", "id1value" );
    xmlWriter.writeTextElement("Identifiant", "id2value");
    xmlWriter.writeTextElement("Identifiant", "id3value");
    xmlWriter.writeEndElement();*/

    xmlWriter.writeEndDocument();

    file.close();
}


/*
void Xml_Dom::SaveXML()
{
  QString filename = QFileDialog::getSaveFileName(this,
                                       tr("Save Xml"), ".",
                                       tr("Xml files (*.xml)"));

  QFile file(filename);
  file.open(QIODevice::WriteOnly);

  QXmlStreamWriter xmlWriter(&file);
  xmlWriter.setAutoFormatting(true);
  xmlWriter.writeStartDocument();

  xmlWriter.writeStartElement("LAMPS");

  xmlWriter.writeStartElement("LIGHT1");
  xmlWriter.writeTextElement("State", ui.pushButton1->isChecked()?"Off":"On" );
  xmlWriter.writeTextElement("Room",ui.comboBox1->currentText());
  xmlWriter.writeTextElement("Potencial",QString::number(ui.spinBox1->value()));

  xmlWriter.writeStartElement("LIGHT4");
  xmlWriter.writeTextElement("State", ui.pushButton4->isChecked()?"Off":"On" );
  xmlWriter.writeTextElement("Room",ui.comboBox4->currentText());
  xmlWriter.writeTextElement("Potencial",QString::number(ui.spinBox4->value()));

  file.close();
  ShowXmlOnScreen();
  statusBar()->showMessage(tr("Xml Saved"));
}
*/


