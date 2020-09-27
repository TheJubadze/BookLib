#include "removereaderconfirmationdialog.h"
#include "ui_removereaderconfirmationdialog.h"

RemoveReaderConfirmationDialog::RemoveReaderConfirmationDialog(
        UnitOfWork *unitOfWork,
        Reader *reader,
        QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveReaderConfirmationDialog)
{
    ui->setupUi(this);
    _unitOfWork = unitOfWork;
    _reader = reader;
}

RemoveReaderConfirmationDialog::~RemoveReaderConfirmationDialog()
{
    delete ui;
}

void RemoveReaderConfirmationDialog::on_buttonBox_accepted()
{
    auto repository = _unitOfWork->getReaderRepository();
    repository->remove(_reader);
}
