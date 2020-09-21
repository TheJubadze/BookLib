#ifndef BOOK_H
#define BOOK_H

#include "reader.h"

#include <QString>

class Reader;
class Book
{
    int _id;
    QString _name;
    QString _author;
    Reader *_reader;
public:
    Book(int, QString, QString);
    void setName(QString);
    void setAuthor(QString);
    void setReader(Reader *);

    int getId();
    QString getName();
    QString getAuthor();
};

#endif // BOOK_H
