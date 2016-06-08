#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "pile.h"
#include "litterale.h"
#include "reel.h"
#include "entier.h"
#include "rationnel.h"
#include "atome.h"
#include "analyser.h"
#include "controleur.h"
#include "calculatriceexception.h"
#include "pilecaretaker.h"
#include "identificateurmanager.h"
#include "operator.h"

#include <iterator>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QChar>

#include "stackdialog.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void show();
    void connections();
    void init(int dim = 5);

private:
    Ui::MainWindow *ui;
    //StackDialog* stack;


private slots:
        //  -- Chiffres de 0 à 9 -- //
        void but0Appuye();
        void but1Appuye();
        void but2Appuye();
        void but3Appuye();
        void but4Appuye();
        void but5Appuye();
        void but6Appuye();
        void but7Appuye();
        void but8Appuye();
        void but9Appuye();

        // -- Opérations de base -- //
        void butAddAppuye();
        void butSousAppuye();
        void butMultAppuye();
        void butDivAppuye();

        //-- Operateur complexe ($) -- //
        void butOpCplxAppuye();

        //-- Point (.) -- //
        void butDotAppuye();

        //-- Enter -- //
        void butEnterAppuye();

        // -- Refresh l'affichage de la pile -- //
        void refresh();

        // -- Manipulation de la pile et Operateurs -- //
        void on_pButSwap_clicked();
        void on_pButDup_clicked();
        void on_pButDrop_clicked();
        void on_pButClear_clicked();
        void on_pButUndo_clicked();
        void on_pButRedo_clicked();

        void on_pButNeg_clicked();
        void on_pButIft_clicked();

        void on_pButSto_clicked();
        void on_pButForget_clicked();

        void on_pButEval_clicked();

        void on_pButDen_clicked();
        void on_pButNum_clicked();

        // -- Operateurs logiques -- //
        void on_pButAnd_clicked();
        void on_pButOr_clicked();
        void on_pButNot_clicked();
        void on_pButInf_clicked();
        void on_pButSup_clicked();
        void on_pButEgal_clicked();

        // -- Elements de syntaxe -- //
        void butCrochFAppuye();
        void butCrochOAppuye();
        void butParenthOAppuye();
        void butParenthFAppuye();
        void butQuoteAppuye();
        void butDeleteAppuye();
        void butSpaceAppuye();

        // -- Operateur EDIT -- //
        void on_pButEdit_clicked();


        void checkModeScientist(bool);
        void on_spinBoxDimPile_valueChanged(int arg1);
};


#endif // MAINWINDOW_H
