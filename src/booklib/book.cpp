#include "book.h"

Book::Book(int id, QString name, QString author)
{
    _id = id;
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

void Book::setReader(Reader *reader)
{
    _reader = reader;
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
