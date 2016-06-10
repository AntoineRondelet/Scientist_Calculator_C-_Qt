#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>

namespace Ui {
class DialogEdit;
}

class DialogEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEdit(QWidget *parent = 0, const QString& str="");
    ~DialogEdit();

    QString getTextSaisie() const;
    void setTextSaisie(const QString& name);

private slots:
    void on_buttonBox_accepted();


private:
    Ui::DialogEdit *ui;
    QString str;
};

#endif // DIALOGEDIT_H
