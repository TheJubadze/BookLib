#include "addbookdialog.h"
#include "ui_addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent, UnitOfWork *unitOfWork) :
    QDialog(parent),
    ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);
    _unitOfWork = unitOfWork;
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

void AddBookDialog::on_buttonBox_accepted()
{
    auto repository = _unitOfWork->getBookRepository();
    auto id = repository->getNextId();
    auto bookName = ui->bookName->text();
    auto bookAuthor = ui->bookAuthor->text();
    repository->add(new Book(id, bookName, bookAuthor));
}
