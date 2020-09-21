#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addbookdialog.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _unitOfWork = new UnitOfWork();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _unitOfWork;
}

void MainWindow::UpdateBooksList()
{
    ui->booksList->clear();
    for(auto b : *_unitOfWork->getBookRepository()->getAll()) {
        ui->booksList->addItem(QString("%1 %2: %3")
                               .arg(QString::number(b->getId()), b->getAuthor(), b->getName()));
    };
}

void MainWindow::on_addBookButton_clicked()
{
    AddBookDialog dialog(this, _unitOfWork);
    dialog.exec();
    UpdateBooksList();
}
