#include "repository.h"

template <class T>
Repository<T>::Repository(std::string id)
{
    _id = id;
    _items = new std::list<T*>();
    _nextIndex = 0;
}

template <class T>
Repository<T>::~Repository()
{
    for(auto b : *_items){
        delete b;
    }
    _items->clear();
    delete _items;
}

template <class T>
int Repository<T>::getNextId()
{
    return _nextIndex++;
}

template <class T>
T *Repository<T>::getById(int id)
{
    return *std::find_if(
                _items->begin(),
                _items->end(),
                [id](T *b){return b->getId() == id;});
}

template <class T>
std::list<T *> *Repository<T>::getAll()
{
    return _items;
}

template <class T>
template <typename _Predicate>
std::list<T *> *Repository<T>::filter(_Predicate p)
{
    std::list<T*> result = new std::list<T*>();
    std::copy_if (_items->begin(), _items->end(), std::back_inserter(result), p);
    return result;
}

template <class T>
void Repository<T>::add(T *b)
{
    _items->push_back(b);
}

template <class T>
void Repository<T>::clear()
{
    _items->clear();
}

template class Repository<Book>;
template class Repository<Reader>;
