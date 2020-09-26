#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <book.h>
#include <list>

template <class T>
class Repository
{
    std::string _id;
    std::list<T *> *_items;
    int _nextIndex;
public:
    Repository(std::string);
    virtual ~Repository();
    std::string getId() { return _id; };
    virtual int getNextId();
    virtual T *getById(int id);
    virtual std::list<T *> *getAll();
    virtual void add(T *);
    virtual void clear();

    template <typename _Predicate>
    std::list<T *> *filter(_Predicate p);
};

#endif // REPOSITORY_H
