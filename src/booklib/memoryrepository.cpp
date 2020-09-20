#include "memoryrepository.h"

MemoryRepository::MemoryRepository()
{
    _books = new std::list<Book*>();
}

MemoryRepository::~MemoryRepository()
{
    for(auto b : *_books){
        delete b;
    }
    _books->clear();
    delete _books;
}

Book *MemoryRepository::getBookById(int id)
{
    return *std::find_if(
                _books->begin(),
                _books->end(),
                [id](Book* b){return b->getId() == id;});
}

std::list<Book *> *MemoryRepository::getBooks()
{
    return _books;
}

void MemoryRepository::addBook(Book *b)
{
    _books->push_back(b);
}
