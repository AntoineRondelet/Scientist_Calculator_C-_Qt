#include "xml_dom.h"

#include <iostream>
using namespace std;
#include <QFileDialog>
#include <QFile>

#include "pile.h"
#include "controleur.h"
#include "identificateurmanager.h"


Xml_Dom::Xml_Dom() : QWidget(){}

Xml_Dom::~Xml_Dom(){}


// -- Fonction de sauvegarde des données XML -- //
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

    // -- On sauvegarde le contenu de la pile -- //
    xmlWriter.writeStartElement("STACK");
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
    // -- Fin de la sauvegarde du contenu de la pile -- //

    // -- Sauvegarde du contenu de la table des identifiants -- //
    xmlWriter.writeStartElement("IDENTIFIANTS");
    QStack<Litterale*>::iterator it;
    for (it = stack.begin(); it != stack.end(); ++it) {
        // -- On recupere notre litterale -- //
        Litterale *cur_lit = *it;
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
    // -- Fin de la sauvegarde du contenu de la table des identifiants -- //

    xmlWriter.writeEndDocument();

    file.close();
}


// -- Fonction de lecture et restauration des données a partir du fichier XML -- //

void Xml_Dom::RestoreXML() {

    Pile& stack = Pile::getInstance();

    QXmlStreamReader Rxml;

    QString filename = QFileDialog::getOpenFileName(this,tr("Open Xml"), ".",tr("Xml files (*.xml)"));

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        std::cerr << "Error: Cannot read file " << qPrintable(filename)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
    }

    Rxml.setDevice(&file);
    Rxml.readNext();

    while(!Rxml.atEnd())
    {
        if(Rxml.isStartElement())
        {
            if(Rxml.name() == "SAVE")
            {
               Rxml.readNext();
            }
            else if (Rxml.name() == "STACK")
            {
                Rxml.readNext();
            }
            else if(Rxml.name() == "Entier")
            {
                QString str_entier = Rxml.readElementText();
                stack.push(new Entier(str_entier.toInt()));
            }
            else if(Rxml.name() == "Reel")
            {
                QString str_reel = Rxml.readElementText();
                stack.push(new Reel(str_reel.toFloat()));
            }
            else if(Rxml.name() == "Rationnel")
            {
                QString str_rationnel = Rxml.readElementText();
                QStringList list_str = str_rationnel.split("/");
                stack.push(new Rationnel(list_str[0].toInt(), list_str[1].toInt()));
            }
            else if(Rxml.name() == "Complexe")
            {
                QString str_cplx = Rxml.readElementText();
                QStringList list_str = str_cplx.split("$");
                list_str << "$";
                Controleur& ctr = Controleur::getInstance();
                ctr.commande(list_str);
            }
            else if(Rxml.name() == "Expression")
            {
                QString str_exp = Rxml.readElementText();
                stack.push(new Expression(str_exp));
            }
            else if(Rxml.name() == "Atome")
            {
                QString str_atome = Rxml.readElementText();
                stack.push(new Atome(str_atome));
            }
            else if(Rxml.name() == "Programme")
            {
                QString str_prog = Rxml.readElementText();
                stack.push(new Programme(str_prog));
            }
            /*
            else if(Rxml.name() == "IDENTIFIANTS")
            {
                Rxml.readNext();
            }
            else if(Rxml.name() == "Idvariables")
            {
                QString str_prog = Rxml.readElementText();
                stack.push(new Programme(str_prog));
            }
            else if(Rxml.name() == "Idprogrammes")
            {
                QString str_prog = Rxml.readElementText();
                stack.push(new Programme(str_prog));
            }
            */
            else
            {
              Rxml.raiseError(QObject::tr("Not a bookindex file"));
            }
        }
        else
        {
            Rxml.readNext();
        }
   }

   file.close();

   if (Rxml.hasError())
   {
          std::cerr << "Error: Failed to parse file "
                    << qPrintable(filename) << ": "
                    << qPrintable(Rxml.errorString()) << std::endl;
   }
   else if (file.error() != QFile::NoError)
   {
      std::cerr << "Error: Cannot read file " << qPrintable(filename)
                << ": " << qPrintable(file.errorString())
                << std::endl;
   }
}


