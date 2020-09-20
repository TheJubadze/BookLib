#ifndef READER_H
#define READER_H

#include <QString>
#include <list>
#include "book.h"

class Reader
{
    QString _name;
    std::list<Book*>* _books;
public:
    Reader(QString name);
    ~Reader();
    void addBook(Book*);
    void removeBook(Book*);
};

#endif // READER_H
