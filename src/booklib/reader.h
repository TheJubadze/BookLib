#ifndef READER_H
#define READER_H

#include <QString>
#include <list>
#include "book.h"

class Book;
class Reader
{
    int _id;
    QString _name;
    std::list<Book *> *_books;
public:
    Reader(int id, QString name);
    ~Reader();
    int getId();
    QString getName();
    QString toString();
    void addBook(Book *);
    void removeBook(Book *);
};

#endif // READER_H
