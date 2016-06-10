#include "dialogeditpile.h"
#include "ui_dialogeditpile.h"

#include "controleur.h"
#include <QMessageBox>

DialogEditPile::DialogEditPile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditPile)
{
    ui->setupUi(this);
}

DialogEditPile::~DialogEditPile()
{
    delete ui;
}


void DialogEditPile::setTextSaisie(const QString& name) {
    ui->textEdit->clear();
    ui->textEdit->setText(name);
}

void DialogEditPile::on_buttonBox_accepted(){
    QString str_value = ui->textEdit->toPlainText();

    const QString programme = "\\[(.)*\\]";

    QRegularExpression regexPg(programme);

    QRegularExpressionMatch str_match_prog = regexPg.match(str_value);
    if(str_match_prog.hasMatch()) {
        if (ui->lineEdit->text() == "") {
            QStringList list_str;
            list_str << str_value;
            Controleur::getInstance().commande(list_str);
        }
        else {
            const QString atome = "^[A-Z]([A-Z0-9]*)$";
            QRegularExpression regexAt(atome);

            QString textLineEdit = ui->lineEdit->text();
            QRegularExpressionMatch str_match_at = regexAt.match(textLineEdit);
            if(str_match_at.hasMatch()) {
                QStringList list_str;
                list_str << str_value << "'"+textLineEdit+"'" << "STO";
                Controleur::getInstance().commande(list_str);
            }
            else {
                QStringList list_str;
                list_str << str_value;
                Controleur::getInstance().commande(list_str);
                QApplication::beep();
                QMessageBox msg;
                msg.setText("Nom invalide ! Le programme est dans la Pile !");
                msg.exec();
            }
        }
    }
    else {
        QApplication::beep();
        QMessageBox msg;
        msg.setText("Erreur de saisie, le changement n'a pas eu lieu");
        msg.exec();
    }
}
