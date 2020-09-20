#include "addbookdialog.h"
#include "book.h"
#include "repository.h"
#include "ui_addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent, IRepository* repository) :
    QDialog(parent),
    ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);
    _repository = repository;
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

void AddBookDialog::on_buttonBox_accepted()
{
    auto book = new Book(ui->bookName->text(), ui->bookAuthor->text());
    _repository->addBook(book);
}
