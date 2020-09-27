#include "showbooksdialog.h"
#include "ui_showbooksdialog.h"

ShowBooksDialog::ShowBooksDialog(
    std::list<Book *> *books,
    QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowBooksDialog)
{
    ui->setupUi(this);
    for(auto b : *books)
        ui->booksList->addItem(b->toString());
}

ShowBooksDialog::~ShowBooksDialog()
{
    delete ui;
}
