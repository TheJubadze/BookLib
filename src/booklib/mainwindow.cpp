#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addbookdialog.h"
#include "addreaderdialog.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _unitOfWork = new UnitOfWork();
    _booksMap = new std::map<QString, Book *>();
    _readersMap = new std::map<QString, Reader *>();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _unitOfWork;
    delete _booksMap;
    delete _readersMap;
}

void MainWindow::UpdateBooksList()
{
    ui->booksList->clear();
    for(auto b : *_unitOfWork->getBookRepository()->getAll()) {
        auto s = b->toString();
        (*_booksMap)[s] = b;
        ui->booksList->addItem(s);
    };
}

void MainWindow::UpdateReadersList()
{
    ui->readersList->clear();
    for(auto r : *_unitOfWork->getReaderRepository()->getAll()) {
        auto s = r->toString();
        (*_readersMap)[s] = r;
        ui->readersList->addItem(s);
    };
}

void MainWindow::UpdateYieldButton()
{
    auto bRow = ui->booksList->currentIndex().row();
    auto rRow = ui->readersList->currentIndex().row();
    if(bRow > -1 && rRow > -1){
        auto book = (*_booksMap)[ui->booksList->currentItem()->text()];
        auto reader = (*_readersMap)[ui->readersList->currentItem()->text()];
        if(book->getReader() != reader){
            ui->yieldBookButton->setEnabled(true);
        }
        else{
            ui->yieldBookButton->setEnabled(false);
        }
    }
    else
    {
        ui->yieldBookButton->setEnabled(false);
    }
}

void MainWindow::on_addBookButton_clicked()
{
    AddBookDialog dialog(this, _unitOfWork);
    dialog.exec();
    UpdateBooksList();
}

void MainWindow::on_addReaderButton_clicked()
{
    AddReaderDialog dialog(this, _unitOfWork);
    dialog.exec();
    UpdateReadersList();
}

void MainWindow::on_booksList_itemSelectionChanged()
{
    UpdateYieldButton();
}

void MainWindow::on_readersList_itemSelectionChanged()
{
    UpdateYieldButton();
}

void MainWindow::on_yieldBookButton_clicked()
{
    auto book = (*_booksMap)[ui->booksList->currentItem()->text()];
    auto reader = (*_readersMap)[ui->readersList->currentItem()->text()];
    book->setReader(reader);
    reader->addBook(book);
    UpdateYieldButton();
}
