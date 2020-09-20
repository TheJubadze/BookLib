#ifndef MEMORYREPOSITORY_H
#define MEMORYREPOSITORY_H

#include <list>
#include "repository.h"

class MemoryRepository : public IRepository
{
    std::list<Book*>* _books;
public:
    MemoryRepository();
    ~MemoryRepository();

    // Repository interface
public:
    virtual Book* getBookById(int id) override;
    virtual std::list<Book*>* getBooks() override;
    virtual void addBook(Book *) override;
};

#endif // MEMORYREPOSITORY_H
