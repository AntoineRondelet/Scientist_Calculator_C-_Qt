#ifndef Edit_H
#define Edit_H

#include <QDialog>

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = 0);
    ~Edit();

private:
    Ui::Edit *ui;
};

#endif // Edit_H
