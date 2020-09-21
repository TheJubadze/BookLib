#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "unitofwork.h"

#include <QListWidget>
#include <QMainWindow>
#include <QString>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    UnitOfWork *_unitOfWork;
    std::map<QString, Book *> *_booksMap;
    std::map<QString, Reader *> *_readersMap;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void UpdateBooksList();
    void UpdateReadersList();
    void UpdateYieldButton();

private slots:
    void on_addBookButton_clicked();
    void on_addReaderButton_clicked();
    void on_booksList_itemSelectionChanged();
    void on_readersList_itemSelectionChanged();

    void on_yieldBookButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
