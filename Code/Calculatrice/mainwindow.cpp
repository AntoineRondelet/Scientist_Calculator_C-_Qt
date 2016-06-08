#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QString>
#include <QStringList>
#include <QKeyEvent>

#include <QMessageBox>
#include "dialogedit.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // -- On initialise l'apparence de la fenetre principale -- //
    init();
    // on établit les connections entre les boutons
    connections();
}


MainWindow::~MainWindow(){delete ui;}


void MainWindow::init() {
    // -- On met le fond de la QLineEdit du message en noir -- //
    ui->lineEditMessage->setStyleSheet("background: black; color: white");

    // -- Ne plus pouvoir ecrire dans la zone de texte destinee a afficher des messages a l'utilisateur -- //
    ui->lineEditMessage->setReadOnly(true);


    // -- On precise le nombre de lignes et le nombre de colonnes (ici 1) qu'on veut afficher -- //
    // -- QTableWidget: c'est juste une coquille. On a des rangées pour mettre ce que l'on veut -- //
    // -- MAIS, on va devoir allouer dynamiquement ce qu'on va mettre dedans: ATTENTION -- //
    ui->tableWidgetPile->setRowCount(Pile::getInstance().getNbAffiche());
    ui->tableWidgetPile->setColumnCount(1);


    // -- Allocation des widgets a l'interieur du tableau -- //
    for(unsigned int i=0; i < Pile::getInstance().getNbAffiche(); i++)
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
    for(unsigned int i=Pile::getInstance().getNbAffiche(); i>0; i--) {
        QString str = QString::number(i);
        str+=" :";
        liste<<str;
    }
    ui->tableWidgetPile->setVerticalHeaderLabels(liste);

    // -- Empecher l'edition du QTableWidget: on ne peut que voir les valeurs dans les champs et pas les modifier directement -- //
    ui->tableWidgetPile->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->setWindowTitle("CALCULATRICE LO21"); //Donner un titre a sa fenetre
}


// connection
void MainWindow::connections() {
    // -- Connection pour les chiffres [0-9] -- //
    connect(ui->but0, SIGNAL(clicked()), this, SLOT(but0Appuye()));
    connect(ui->but1, SIGNAL(clicked()), this, SLOT(but1Appuye()));
    connect(ui->but2, SIGNAL(clicked()), this, SLOT(but2Appuye()));
    connect(ui->but3, SIGNAL(clicked()), this, SLOT(but3Appuye()));
    connect(ui->but4, SIGNAL(clicked()), this, SLOT(but4Appuye()));
    connect(ui->but5, SIGNAL(clicked()), this, SLOT(but5Appuye()));
    connect(ui->but6, SIGNAL(clicked()), this, SLOT(but6Appuye()));
    connect(ui->but7, SIGNAL(clicked()), this, SLOT(but7Appuye()));
    connect(ui->but8, SIGNAL(clicked()), this, SLOT(but8Appuye()));
    connect(ui->but9, SIGNAL(clicked()), this, SLOT(but9Appuye()));

    // -- Operateur complexe -- //
    connect(ui->pButCplx, SIGNAL(clicked()), this, SLOT(butOpCplxAppuye()));

    // -- Espace -- //
    //connect(ui->butdollar, SIGNAL(clicked()), this, SLOT(butDollarAppuye()));


    // -- Point -- //
    connect(ui->pButDot, SIGNAL(clicked()), this, SLOT(butDotAppuye()));

    // -- Opérations de base -- //
    connect(ui->pButAdd, SIGNAL(clicked()), this, SLOT(butAddAppuye()));
    connect(ui->pButSous, SIGNAL(clicked()), this, SLOT(butSousAppuye()));
    connect(ui->pButMult, SIGNAL(clicked()), this, SLOT(butMultAppuye()));
    connect(ui->pButDiv, SIGNAL(clicked()), this, SLOT(butDivAppuye()));

    // -- Connection si l'utilisateur appuie sur la touche enter -- //
    connect(ui->pButEnter, SIGNAL(clicked()), this, SLOT(butEnterAppuye()));
    // -- Connection si l'utilisateur appuie sur la touche enter du clavier ! -- //
    //connect(ui->actionKeyboard, SIGNAL(clicked()), this, SLOT(keyPressEvent()));

    // -- Connection entre le Controleur et la fenetre pour refresh la pile quand on fait une modif -- //
    connect(&Controleur::getInstance(), SIGNAL(modificationEtat()), this, SLOT(refresh()));


    // -- Elements de syntaxe -- //
    connect(ui->pButCrochets, SIGNAL(clicked()), this, SLOT(butCrochetsAppuye()));
    connect(ui->pButParenth, SIGNAL(clicked()), this, SLOT(butParenthAppuye()));
    connect(ui->pButQuote, SIGNAL(clicked()), this, SLOT(butQuoteAppuye()));
    connect(ui->pButSpace, SIGNAL(clicked()), this, SLOT(butSpaceAppuye()));

    // -- Efface le dernier caractere entré dans la QLineEdit -- //
    connect(ui->pButDelete, SIGNAL(clicked()), this, SLOT(butDeleteAppuye()));
}


// ------------- LES SLOTS -------------- //


// --  Chiffres [0-9] -- //
void MainWindow::but0Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"0");}
void MainWindow::but1Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"1");}
void MainWindow::but2Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"2");}
void MainWindow::but3Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"3");}
void MainWindow::but4Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"4");}
void MainWindow::but5Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"5");}
void MainWindow::but6Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"6");}
void MainWindow::but7Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"7");}
void MainWindow::but8Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"8");}
void MainWindow::but9Appuye() {ui->lineEditCommande->setText(ui->lineEditCommande->text()+"9");}


// -- Operateur complexe -- //
void MainWindow::butOpCplxAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"$"); }


/*// -- Espace -- //
void MainWindow::butEspaceAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+" "); } */

// -- Point -- //
void MainWindow::butDotAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"."); }


// -- Opérations de base -- //
void MainWindow::butAddAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"+"); }
void MainWindow::butSousAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"-"); }
void MainWindow::butMultAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"*"); }
void MainWindow::butDivAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"/"); }


// -- Elements de synatxe -- //
void MainWindow::butCrochetsAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"[  ]"); }
void MainWindow::butParenthAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"(  )"); }
void MainWindow::butQuoteAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+"'  '"); }
void MainWindow::butSpaceAppuye(){ ui->lineEditCommande->setText(ui->lineEditCommande->text()+" "); }

// -- Clear la ligne de saisie -- //
void MainWindow::butDeleteAppuye(){ ui->lineEditCommande->clear();}



// -- Lorsque l'on appuie sur le bouton Enter -- //
void MainWindow::butEnterAppuye() {
    Pile::getInstance().setMessage("");
    // -- Interpreter l'entrée de l'utilisateur -- //
    QString str_in = ui->lineEditCommande->text();
    // -- Extraction de chaque element de la ligne on suppose que le séparateur est l'espace -- //
    QStringList liste_param = str_in.split(QRegularExpression("[[:space:]]+"));
    if (str_in!="Q") Controleur::getInstance().commande(liste_param);

    // -- On remet le message de la QListEdit de message a zero -- //
    ui->lineEditCommande->clear();
}


// -- Permet d'actualiser la pile quand on fait des changements -- //
void MainWindow::refresh() {
    ui->lineEditMessage->setText(Pile::getInstance().getMessage());
    for(unsigned int i=0; i<Pile::getInstance().getNbAffiche(); i++)
    {
        // -- Pour remettre a zero les donnees de ma pile -- //
        ui->tableWidgetPile->item(i,0)->setText("");
    }
    // -- Affichage -- //
    unsigned int nb=0;
    for(Pile::iterator it=Pile::getInstance().begin(); it!=Pile::getInstance().end() && nb<Pile::getInstance().getNbAffiche(); ++it) {
            ui->tableWidgetPile->item(Pile::getInstance().getNbAffiche()-nb-1,0)->setText((*it)->toString());
            nb++;
    }
}

/*
void MainWindow::keyPressEvent(QKeyEvent *ev){
    if (ev->key() == Qt::Key_Enter){
        butEnterAppuye();
    }
    else{
        QMainWindow::keyPressEvent(ev);
    }
}
*/

/* Pour fair ele ctrl-z et le undo etc
QShortcut* shortcut = new QShortcut(QKeySequence("Ctrl+W"), this);
QObject::connect(shortcut, SIGNAL(activated()), tonObject, SLOT(tonSlot()));
*/




/*

// enter et eval
connect(ui->butenter, SIGNAL(clicked()), this, SLOT(butEnterAppuye()));
connect(ui->buteval, SIGNAL(clicked()), this, SLOT(butEvalAppuye()));

// delete
connect(ui->butdel, SIGNAL(clicked()), this, SLOT(butDelAppuye()));


// checkbox mode complex = annuler qq boutons
connect(ui->checkBoxComplex, SIGNAL(clicked(bool)), this, SLOT(checkModeComplex(bool)));

// boutton backspace
connect(ui->butBackspace, SIGNAL(clicked()), this, SLOT(butBackspace()));

// Edition : actions Undo et Redo
connect(ui->actionAnnuler, SIGNAL(triggered()), this, SLOT(annulerEtatPile()));
connect(ui->actionRetablir, SIGNAL(triggered()), this, SLOT(retablirEtatPile()));
*/


// ------------------------------------------------------------------------------------- //
// ------------------------------------ Les operateurs --------------------------------- //
// ------------------------------------------------------------------------------------- //

// -- On a fait clic droit sur le bouton: "aller a slot" et ici on definit le comportement de notr slot -- //
void MainWindow::on_pButSwap_clicked(){
    QStringList str_list;
    str_list.push_back("SWAP");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButDup_clicked(){
    QStringList str_list;
    str_list.push_back("DUP");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButDrop_clicked(){
    QStringList str_list;
    str_list.push_back("DROP");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButClear_clicked(){
    QStringList str_list;
    str_list.push_back("CLEAR");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButUndo_clicked(){
    QStringList str_list;
    str_list.push_back("UNDO");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButRedo_clicked(){
    QStringList str_list;
    str_list.push_back("REDO");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButNeg_clicked(){
    QStringList str_list;
    str_list.push_back("NEG");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButIft_clicked(){
    QStringList str_list;
    str_list.push_back("IFT");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButSto_clicked(){
    QStringList str_list;
    str_list.push_back("STO");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButForget_clicked(){
    QStringList str_list;
    str_list.push_back("FORGET");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButEval_clicked(){
    QStringList str_list;
    str_list.push_back("EVAL");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButAnd_clicked(){
    QStringList str_list;
    str_list.push_back("AND");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButOr_clicked(){
    QStringList str_list;
    str_list.push_back("OR");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButNot_clicked(){
    QStringList str_list;
    str_list.push_back("NOT");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButDen_clicked(){
    QStringList str_list;
    str_list.push_back("DEN");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButNum_clicked(){
    QStringList str_list;
    str_list.push_back("NUM");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButInf_clicked(){
    QStringList str_list;
    str_list.push_back("<");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButSup_clicked(){
    QStringList str_list;
    str_list.push_back(">");
    Controleur::getInstance().commande(str_list);
}

void MainWindow::on_pButEgal_clicked(){
    QStringList str_list;
    str_list.push_back("=");
    Controleur::getInstance().commande(str_list);
}


// -- Operateur EDIT -- //


void MainWindow::on_pButEdit_clicked(){
    DialogEdit edit;
    edit.setModal(true);
    edit.exec();
}

