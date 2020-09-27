#ifndef REMOVEREADERCONFIRMATIONDIALOG_H
#define REMOVEREADERCONFIRMATIONDIALOG_H

#include <QDialog>
#include "unitofwork.h"
#include "entities/reader.h"

namespace Ui {
class RemoveReaderConfirmationDialog;
}

class RemoveReaderConfirmationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveReaderConfirmationDialog(
        UnitOfWork *unitOfWork,
        Reader *reader,
        QWidget *parent = nullptr);
    ~RemoveReaderConfirmationDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RemoveReaderConfirmationDialog *ui;
    UnitOfWork *_unitOfWork;
    Reader *_reader;
};

#endif // REMOVEREADERCONFIRMATIONDIALOG_H
