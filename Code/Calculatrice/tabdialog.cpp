#include "tabdialog.h"
#include "ui_tabdialog.h"

#include "pile.h"

TabDialog::TabDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(but0Appuye()));
}

TabDialog::~TabDialog()
{
    delete ui;
}

void TabDialog::on_spinBox_valueChanged(int arg1){
    Pile::getInstance().setNbAffiche(arg1);
}

void TabDialog::but0Appuye() {ui->lineEdit->setText(ui->lineEdit->text()+"0");}
