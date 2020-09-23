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

    ui->yieldBookButton->setEnabled(false);
    ui->returnBookButton->setEnabled(false);
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

void MainWindow::UpdateForm()
{
    UpdateButtons();
}

//-------------------Slots-------------------
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
    UpdateForm();
}

void MainWindow::on_readersList_itemSelectionChanged()
{
    UpdateForm();
}

void MainWindow::on_yieldBookButton_clicked()
{
    auto book = GetSelectedBook();
    auto reader = GetSelectedReader();
    book->setReader(reader);
    reader->addBook(book);
    UpdateForm();
}

void MainWindow::on_returnBookButton_clicked()
{
    auto book = GetSelectedBook();
    auto reader = GetSelectedReader();
    book->removeReader();
    reader->removeBook(book);
    UpdateForm();
}

//-------------------Private members-------------------
void MainWindow::UpdateButtons()
{
    auto bRow = ui->booksList->currentIndex().row();
    auto rRow = ui->readersList->currentIndex().row();
    if(bRow > -1 && rRow > -1){
        auto book = (*_booksMap)[ui->booksList->currentItem()->text()];
        if(book->isAvailable()){
            ui->yieldBookButton->setEnabled(true);
            ui->returnBookButton->setEnabled(false);
        }
        else{
            ui->yieldBookButton->setEnabled(false);
            ui->returnBookButton->setEnabled(true);
        }
    }
    else
    {
        ui->yieldBookButton->setEnabled(false);
        ui->returnBookButton->setEnabled(false);
    }
}

Book *MainWindow::GetSelectedBook()
{
    return (*_booksMap)[ui->booksList->currentItem()->text()];
}

Reader *MainWindow::GetSelectedReader()
{
    return (*_readersMap)[ui->readersList->currentItem()->text()];
}
