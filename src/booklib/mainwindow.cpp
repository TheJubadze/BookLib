#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "memoryrepository.h"
#include "addbookdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _repository = new MemoryRepository();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _repository;
}

void MainWindow::UpdateBooksList()
{
    ui->booksList->clear();
    for(auto b : *_repository->getBooks()) {
        ui->booksList->addItem(b->getName());
    };
}

void MainWindow::on_addBookButton_clicked()
{
    AddBookDialog dialog(this, _repository);
    dialog.exec();
    UpdateBooksList();
}
