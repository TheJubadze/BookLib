#include "unitofwork.h"

UnitOfWork::UnitOfWork()
{
    _bookRepository = new Repository<Book>();
    _readerRepository = new Repository<Reader>();
}

UnitOfWork::~UnitOfWork()
{
    delete _bookRepository;
    delete _readerRepository;
}

Repository<Book> *UnitOfWork::getBookRepository()
{
    return _bookRepository;
}

Repository<Reader> *UnitOfWork::getReaderRepository()
{
    return _readerRepository;
}
