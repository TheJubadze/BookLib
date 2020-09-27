#ifndef ADDREADERDIALOG_H
#define ADDREADERDIALOG_H

#include "unitofwork.h"
#include <QDialog>

namespace Ui {
class AddReaderDialog;
}

class AddReaderDialog : public QDialog
{
    Q_OBJECT
    UnitOfWork *_unitOfWork;

public:
    explicit AddReaderDialog(QWidget *parent = nullptr, UnitOfWork *unitOfWork = nullptr);
    ~AddReaderDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddReaderDialog *ui;
};

#endif // ADDREADERDIALOG_H
