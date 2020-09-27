#ifndef REMOVEBOOKCONFIRMATIONDIALOG_H
#define REMOVEBOOKCONFIRMATIONDIALOG_H

#include <QDialog>
#include "unitofwork.h"
#include "entities/book.h"

namespace Ui {
class RemoveBookConfirmationDialog;
}

class RemoveBookConfirmationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveBookConfirmationDialog(
            UnitOfWork *unitOfWork,
            Book *book,
            QWidget *parent = nullptr);
    ~RemoveBookConfirmationDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RemoveBookConfirmationDialog *ui;
    UnitOfWork *_unitOfWork;
    Book *_book;
};

#endif // REMOVEBOOKCONFIRMATIONDIALOG_H
