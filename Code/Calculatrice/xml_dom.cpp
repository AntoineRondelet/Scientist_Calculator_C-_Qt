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
    xmlWriter.writeStartElement("VARIABLES");
    QMap<QString, Litterale*>::iterator it;
    for (it = IdentificateurManager::getInstance().m_names_var.begin(); it != IdentificateurManager::getInstance().m_names_var.end(); ++it){
        //cout << it.key() << ": " << it.value() << endl;
        // -- On recupere notre litterale -- //
        Litterale* cur_lit_var = it.value();
        QString cur_str = it.key();
        // -- On teste le type de notre litterale -- //
        Entier* litEntv = dynamic_cast<Entier*>(cur_lit_var);
        Reel* litRev = dynamic_cast<Reel*>(cur_lit_var);
        Rationnel* litRav = dynamic_cast<Rationnel*>(cur_lit_var);
        Complexe* litCpxv = dynamic_cast<Complexe*>(cur_lit_var);

        if(litEntv != nullptr) {
            xmlWriter.writeStartElement("EntierVar");
                /*add one attribute and its value*/
                xmlWriter.writeAttribute("name",cur_str);
                /*add character data to tag student */
                xmlWriter.writeCharacters (cur_lit_var->toString());
                /*close tag student  */
            xmlWriter.writeEndElement();
        }
        else if (litRev !=  nullptr) {
            xmlWriter.writeStartElement("ReelVar");
                xmlWriter.writeAttribute("name",cur_str);
                xmlWriter.writeCharacters (cur_lit_var->toString());
            xmlWriter.writeEndElement();
        }
        else if (litRav !=  nullptr) {
            xmlWriter.writeStartElement("RationnelVar");
                xmlWriter.writeAttribute("name",cur_str);
                xmlWriter.writeCharacters (cur_lit_var->toString());
            xmlWriter.writeEndElement();
        }
        else if (litCpxv !=  nullptr) {
            xmlWriter.writeStartElement("ComplexeVar");
                xmlWriter.writeAttribute("name",cur_str);
                xmlWriter.writeCharacters (cur_lit_var->toString());
            xmlWriter.writeEndElement();
        }
        else {
            CALCULATRICE_EXCEPTION("MEGA BUG SUR LE XML");
        }
    }
    // -- Fin de la sauvegarde du contenu de la table des identifiants -- //

    xmlWriter.writeEndElement(); //IDENTIFIANTS
    xmlWriter.writeEndElement(); //VARIABLES

    // -- sauvegarde des programmes -- //

    xmlWriter.writeStartElement("PROGRAMMES");
    QMap<QString, Litterale*>::iterator itp;
    for (itp = IdentificateurManager::getInstance().m_names_prog.begin(); itp != IdentificateurManager::getInstance().m_names_prog.end(); ++itp){
        // -- On recupere notre litterale -- //
        Litterale* cur_lit_prog = itp.value();
        QString cur_str_prog = itp.key();
        xmlWriter.writeStartElement("Prog");
        xmlWriter.writeAttribute("name",cur_str_prog);
        xmlWriter.writeCharacters (cur_lit_prog->toString());
        xmlWriter.writeEndElement();
    }
    // -- Fin de la sauvegarde du contenu de la table des programmes -- //

    xmlWriter.writeEndElement(); //PROGRAMMES

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
            else if(Rxml.name() == "IDENTIFIANTS")
            {
                Rxml.readNext();
            }
            else if(Rxml.name() == "VARIABLES")
            {
                Rxml.readNext();
            }
            else if(Rxml.name() == "EntierVar")
            {
                QString nom;
                QString value;
                QXmlStreamAttributes attributes = Rxml.attributes();
                if(attributes.hasAttribute("name"))
                    nom = attributes.value("name").toString();
                value = Rxml.readElementText();
                Entier* ptr_lit = new Entier(value.toInt());
                IdentificateurManager::getInstance().m_names_var.insert(nom, ptr_lit);
            }
            else if(Rxml.name() == "ReelVar")
            {
                QString nom;
                QString value;
                QXmlStreamAttributes attributes = Rxml.attributes();
                if(attributes.hasAttribute("name"))
                    nom = attributes.value("name").toString();
                value = Rxml.readElementText();
                Reel* ptr_lit = new Reel(value.toFloat());
                IdentificateurManager::getInstance().m_names_var.insert(nom, ptr_lit);
            }
            else if(Rxml.name() == "RationnelVar")
            {
                QString nom;
                QString value;
                QXmlStreamAttributes attributes = Rxml.attributes();
                if(attributes.hasAttribute("name"))
                    nom = attributes.value("name").toString();

                value = Rxml.readElementText();
                QStringList list_str = value.split("/");
                Rationnel* ptr_lit = new Rationnel(list_str[0].toInt(), list_str[1].toInt());
                IdentificateurManager::getInstance().m_names_var.insert(nom, ptr_lit);
            }
            /*else if(Rxml.name() == "ComplexeVar")
            {
                QString nom;
                QString value;
                QXmlStreamAttributes attributes = Rxml.attributes();
                if(attributes.hasAttribute("name"))
                    nom = attributes.value("name").toString();

                QStringList list_str = value.split("$");
                list_str << "$" << "'"+nom+"'" << "STO";
                Controleur& ctr = Controleur::getInstance();
                ctr.commande(list_str);
            }*/
            else if(Rxml.name() == "PROGRAMMES")
            {
                Rxml.readNext();
            }
            else if(Rxml.name() == "Prog")
            {
                QString nom;
                QString value;
                QXmlStreamAttributes attributes = Rxml.attributes();
                if(attributes.hasAttribute("name"))
                    nom = attributes.value("name").toString();
                value = Rxml.readElementText();
                Programme* ptr_lit = new Programme(value);
                IdentificateurManager::getInstance().m_names_prog.insert(nom, ptr_lit);
            }
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


