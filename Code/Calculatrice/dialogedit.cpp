#include "dialogedit.h"
#include "ui_dialogedit.h"

#include "identificateurmanager.h"
#include "controleur.h"

DialogEdit::DialogEdit(QWidget *parent, const QString& st): QDialog(parent), ui(new Ui::DialogEdit), str(st){
    ui->setupUi(this);
}

DialogEdit::~DialogEdit()
{
    delete ui;
}


QString DialogEdit::getTextSaisie() const {
   QString res = ui->textSaisie->toPlainText();
}

void DialogEdit::setTextSaisie(const QString& name) {
    ui->textSaisie->clear();
    ui->textSaisie->setText(name);
}

void DialogEdit::on_buttonBox_accepted(){
    IdentificateurManager& id_man = IdentificateurManager::getInstance();
    QString str_value = ui->textSaisie->toPlainText();
    id_man.forgetIdentificateur(str);

    QString entier = "^-?[[:digit:]]+$";
    QString reel = "^(-?)[[:digit:]]*(\\.)([[:digit:]]*)$";
    QString rationnel = "^(?<numerateur>(-?)[[:digit:]]+)/(?<denominateur>(-?)[[:digit:]]+)$";
    QString complexe = "^(?<partRE>(-?)[[:digit:]]+(([\\.]|[\\/])[[:digit:]]+)?)[\\$](?<partIM>(-?)[[:digit:]]+(([\\.]|[\\/])[[:digit:]]+)?)$";

    const QString litNb = entier+"|"+reel+"|"+rationnel+"|"+complexe;
    const QString programme = "\\[(.)*\\]";

    QRegularExpression regexNb(litNb);
    QRegularExpression regexPg(programme);

    QRegularExpressionMatch str_match_var = regexNb.match(str_value);
    QRegularExpressionMatch str_match_prog = regexPg.match(str_value);
    if(str_match_var.hasMatch() || str_match_prog.hasMatch()) {
        QStringList list_str;
        list_str << str_value << "'"+str+"'" << "STO";
        Controleur::getInstance().commande(list_str);
    }
    else {
        QApplication::beep();
    }


}

