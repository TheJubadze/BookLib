#ifndef SHOWBOOKSDIALOG_H
#define SHOWBOOKSDIALOG_H

#include <QDialog>
#include <list>
#include "book.h"

namespace Ui {
class ShowBooksDialog;
}

class ShowBooksDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowBooksDialog(
        std::list<Book *> *books,
        QWidget *parent = nullptr);
    ~ShowBooksDialog();

private:
    Ui::ShowBooksDialog *ui;
};

#endif // SHOWBOOKSDIALOG_H
