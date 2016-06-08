#include "stackdialog.h"
#include "ui_stackdialog.h"

/*
#include "pile.h"

StackDialog::StackDialog(QWidget *parent, int dim): QDialog(parent), ui(new Ui::StackDialog), dimension(dim) {

    ui->setupUi(this);

    // -- On precise le nombre de lignes et le nombre de colonnes (ici 1) qu'on veut afficher -- //
    // -- QTableWidget: c'est juste une coquille. On a des rangées pour mettre ce que l'on veut -- //
    // -- MAIS, on va devoir allouer dynamiquement ce qu'on va mettre dedans: ATTENTION -- //
    ui->tableWidgetPile->setRowCount(dim);
    ui->tableWidgetPile->setColumnCount(1);


    // -- Allocation des widgets a l'interieur du tableau -- //
    for(unsigned int i=0; i < dim; i++)
        //setItem est une methode de la classe QTableWidget
        ui->tableWidgetPile->setItem(i,0,new QTableWidgetItem(""));

    // -- Rendre invisible le header horizontal -- //
    ui->tableWidgetPile->horizontalHeader()->setVisible(false);

    // -- Ajuster la largeur de la derniere colonne (ici on en a qu'une) automatiquement -- //
    ui->tableWidgetPile->horizontalHeader()->setStretchLastSection(true);

    // -- On ajoute un peu de couleur -- //
    ui->tableWidgetPile->setStyleSheet("background: grey; color: black");

    // -- Changer les labels de chaque ligne -- //
    QStringList liste;
    for(unsigned int i=dim; i>0; i--) {
        QString str = QString::number(i);
        str+=" :";
        liste<<str;
    }
    ui->tableWidgetPile->setVerticalHeaderLabels(liste);

    // -- Empecher l'edition du QTableWidget: on ne peut que voir les valeurs dans les champs et pas les modifier directement -- //
    ui->tableWidgetPile->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

StackDialog::~StackDialog()
{
    delete ui;
}*/
