#ifndef DIALOGEDITPILE_H
#define DIALOGEDITPILE_H

#include <QDialog>

namespace Ui {
class DialogEditPile;
}

class DialogEditPile : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditPile(QWidget *parent = 0);
    ~DialogEditPile();
    void setTextSaisie(const QString& name);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogEditPile *ui;
};

#endif // DIALOGEDITPILE_H
