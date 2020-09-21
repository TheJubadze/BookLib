#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <book.h>
#include <list>

template <class T>
class Repository
{
    std::list<T*>* _items;
    int _nextIndex;
public:
    Repository();
    virtual ~Repository();
    virtual int getNextId();
    virtual T* getById(int id);
    virtual std::list<T*>* getAll();
    virtual void add(T*);
};

#endif // REPOSITORY_H
