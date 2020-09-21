#include "reader.h"

Reader::Reader(int id, QString name)
{
    _id = id;
    _name = name;
    _books = new std::list<Book*>();
}

Reader::~Reader()
{
    for(auto const b : *_books)
    {
        delete b;
    }
    _books->clear();
    delete _books;
}

int Reader::getId()
{
    return _id;
}

QString Reader::getName()
{
    return _name;
}

QString Reader::toString()
{
    return QString("%1 %2").arg(QString::number(getId()), getName());
}

void Reader::addBook(Book *b)
{
    _books->push_back(b);
}

void Reader::removeBook(Book *b)
{
    _books->remove(b);
}
