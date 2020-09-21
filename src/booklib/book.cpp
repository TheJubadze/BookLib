#include "book.h"

#include <QString>

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

void Book::removeReader()
{
    _reader = nullptr;
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

Reader *Book::getReader()
{
    return _reader;
}

bool Book::isAvailable()
{
    return _reader == nullptr;
}

QString Book::toString()
{
    return QString("%1 %2: %3")
            .arg(QString::number(getId()), getAuthor(), getName());
}
