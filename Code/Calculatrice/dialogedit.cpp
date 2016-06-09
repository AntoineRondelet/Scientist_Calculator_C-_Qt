#include "dialogedit.h"
#include "ui_dialogedit.h"

DialogEdit::DialogEdit(QWidget *parent): QDialog(parent), ui(new Ui::DialogEdit){
    ui->setupUi(this);
}

DialogEdit::~DialogEdit()
{
    delete ui;
}
