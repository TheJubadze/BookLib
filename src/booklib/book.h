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
    void removeReader();

    int getId();
    QString getName();
    QString getAuthor();
    Reader *getReader();

    bool isAvailable();

    QString toString();
};

#endif // BOOK_H
