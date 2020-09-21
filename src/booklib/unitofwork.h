#ifndef UNITOFWORK_H
#define UNITOFWORK_H

#include "reader.h"
#include "repository.h"



class UnitOfWork
{
    Repository<Book> *_bookRepository;
    Repository<Reader> *_readerRepository;
public:
    UnitOfWork();
    ~UnitOfWork();
    Repository<Book> *getBookRepository();
    Repository<Reader> *getReaderRepository();
};

#endif // UNITOFWORK_H
