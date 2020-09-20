#include "book.h"

Book::Book()
{
}

Book::Book(QString name)
{
    _name = name;
}

Book::Book(QString name, QString author)
{
    _name = name;
    _author = author;
}

void Book::setName(QString name)
{
    _name = name;
}

void Book::setAuthor(QString author)
{
    _author = author;
}

int Book::getId()
{
    return _id;
}

QString Book::getName()
{
    return _name;
}

QString Book::getAuthor()
{
    return _author;
}
