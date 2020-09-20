#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include "repository.h"

#include <QDialog>

namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT
    IRepository* _repository;

public:
    explicit AddBookDialog(QWidget *parent = nullptr, IRepository* repository = nullptr);
    ~AddBookDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddBookDialog *ui;
};

#endif // ADDBOOKDIALOG_H
