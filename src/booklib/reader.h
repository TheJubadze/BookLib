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
    Reader(QString name);
    ~Reader();
    int getId();
    void addBook(Book *);
    void removeBook(Book *);
};

#endif // READER_H
