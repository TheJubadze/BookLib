#include "removebookconfirmationdialog.h"
#include "ui_removebookconfirmationdialog.h"
#include "book.h"

RemoveBookConfirmationDialog::RemoveBookConfirmationDialog(
        UnitOfWork *unitOfWork,
        Book *book,
        QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveBookConfirmationDialog)
{
    ui->setupUi(this);
    _unitOfWork = unitOfWork;
    _book = book;
}

RemoveBookConfirmationDialog::~RemoveBookConfirmationDialog()
{
    delete ui;
}

void RemoveBookConfirmationDialog::on_buttonBox_accepted()
{
    auto repository = _unitOfWork->getBookRepository();
    repository->remove(_book);
}
