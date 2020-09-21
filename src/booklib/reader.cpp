#include "reader.h"

Reader::Reader(QString name)
{
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

void Reader::addBook(Book *b)
{
    _books->push_back(b);
}

void Reader::removeBook(Book *b)
{
    _books->remove(b);
}
