#include "addreaderdialog.h"
#include "ui_addreaderdialog.h"

AddReaderDialog::AddReaderDialog(QWidget *parent, UnitOfWork *unitOfWork) :
    QDialog(parent),
    ui(new Ui::AddReaderDialog)
{
    ui->setupUi(this);
    _unitOfWork = unitOfWork;
}

AddReaderDialog::~AddReaderDialog()
{
    delete ui;
}

void AddReaderDialog::on_buttonBox_accepted()
{
    auto repository = _unitOfWork->getReaderRepository();
    auto id = repository->getNextId();
    auto name = ui->readerName->text();
    repository->add(new Reader(id, name));
}
