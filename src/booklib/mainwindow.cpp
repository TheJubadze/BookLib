#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "addbookdialog.h"
#include "addreaderdialog.h"
#include "removebookconfirmationdialog.h"
#include "removereaderconfirmationdialog.h"

#include <QString>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _unitOfWork = new UnitOfWork();
    _booksMap = new std::map<QString, Book *>();
    _readersMap = new std::map<QString, Reader *>();

    _unitOfWork->load();

    updateBooksList();
    updateReadersList();
    updateButtons();
    ui->booksList->setCurrentRow(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _unitOfWork;
    delete _booksMap;
    delete _readersMap;
}

//-------------------Slots-------------------
void MainWindow::on_addBookButton_clicked()
{
    AddBookDialog dialog(this, _unitOfWork);
    dialog.exec();
    _unitOfWork->save();
    updateBooksList();
}

void MainWindow::on_addReaderButton_clicked()
{
    AddReaderDialog dialog(this, _unitOfWork);
    dialog.exec();
    _unitOfWork->save();
    updateReadersList();
}

void MainWindow::on_booksList_itemSelectionChanged()
{
    updateButtons();
}

void MainWindow::on_readersList_itemSelectionChanged()
{
    updateButtons();
}

void MainWindow::on_yieldBookButton_clicked()
{
    auto book = getSelectedBook();
    auto reader = getSelectedReader();
    reader->addBook(book);
    _unitOfWork->save();
    updateButtons();
}

void MainWindow::on_returnBookButton_clicked()
{
    auto book = getSelectedBook();
    auto reader = getSelectedReader();
    reader->removeBook(book);
    _unitOfWork->save();
    updateButtons();
}

void MainWindow::on_removeBookButton_clicked()
{
    RemoveBookConfirmationDialog dialog(_unitOfWork, getSelectedBook(), this);
    if(dialog.exec())
    {
        _unitOfWork->save();
        updateBooksList();
        updateButtons();
    }
}

void MainWindow::on_showReaderButton_clicked()
{
    auto readerItems = ui->readersList->findItems(getSelectedBook()->getReader()->toString(), Qt::MatchExactly);
    if(!readerItems.isEmpty()){
        ui->readersList->setCurrentItem(readerItems[0]);
    }
}

void MainWindow::on_removeReaderButton_clicked()
{
    RemoveReaderConfirmationDialog dialog(_unitOfWork, getSelectedReader(), this);
    if(dialog.exec())
    {
        _unitOfWork->save();
        updateReadersList();
        updateButtons();
    }
}

//-------------------Private members-------------------
void MainWindow::updateButtons()
{
    auto book = getSelectedBook();
    ui->removeBookButton->setEnabled(isBookSelected());
    ui->yieldBookButton->setEnabled(isBookSelected() && book->isAvailable() && isReaderSelected());
    ui->returnBookButton->setEnabled(isBookSelected() && !book->isAvailable());
    ui->showReaderButton->setEnabled(ui->returnBookButton->isEnabled());

    auto reader = getSelectedReader();
    ui->removeReaderButton->setEnabled(isReaderSelected());
    ui->showBooksButton->setEnabled(isReaderSelected() && reader->hasBooks());
}

void MainWindow::updateBooksList()
{
    ui->booksList->setCurrentRow(-1);
    ui->booksList->clear();
    for(auto b : *_unitOfWork->getBookRepository()->getAll()) {
        auto s = b->toString();
        (*_booksMap)[s] = b;
        ui->booksList->addItem(s);
    };
}

void MainWindow::updateReadersList()
{
    ui->readersList->setCurrentRow(-1);
    ui->readersList->clear();
    for(auto r : *_unitOfWork->getReaderRepository()->getAll()) {
        auto s = r->toString();
        (*_readersMap)[s] = r;
        ui->readersList->addItem(s);
    };
}

Book *MainWindow::getSelectedBook()
{
    return isBookSelected()
        ? (*_booksMap)[ui->booksList->currentItem()->text()]
        : nullptr;
}

Reader *MainWindow::getSelectedReader()
{
    return isReaderSelected()
        ? (*_readersMap)[ui->readersList->currentItem()->text()]
        : nullptr;
}

bool MainWindow::isBookSelected()
{
    return ui->booksList->currentIndex().row() > -1;
}

bool MainWindow::isReaderSelected()
{
    return ui->readersList->currentIndex().row() > -1;
}

