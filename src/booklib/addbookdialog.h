#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include "unitofwork.h"

#include <QDialog>

namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT
    UnitOfWork *_unitOfWork;

public:
    explicit AddBookDialog(QWidget *parent = nullptr, UnitOfWork *unitOfWork = nullptr);
    ~AddBookDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddBookDialog *ui;
};

#endif // ADDBOOKDIALOG_H
