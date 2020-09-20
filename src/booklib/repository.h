#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <book.h>
#include <list>

class IRepository
{
public:
    virtual ~IRepository(){};
    virtual Book* getBookById(int id) = 0;
    virtual std::list<Book*>* getBooks() = 0;
    virtual void addBook(Book*) = 0;
};

#endif // REPOSITORY_H
