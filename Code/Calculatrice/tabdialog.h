#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QDialog>

namespace Ui {
class TabDialog;
}

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabDialog(QWidget *parent = 0);
    ~TabDialog();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void but0Appuye();

private:
    Ui::TabDialog *ui;
};

#endif // TABDIALOG_H
