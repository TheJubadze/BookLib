#include <QFile>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "unitofwork.h"

UnitOfWork::UnitOfWork()
{
    _bookRepository = new Repository<Book>("bookRepository");
    _readerRepository = new Repository<Reader>("readerRepository");
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

void UnitOfWork::write(QJsonObject &json) const
{
    write(json, _bookRepository);
    write(json, _readerRepository);
}

void UnitOfWork::read(const QJsonObject &json)
{
    read(json, _bookRepository);
    read(json, _readerRepository);
    for(auto reader : *_readerRepository->getAll())
        reader->setBooks(_bookRepository->getAll());
}

bool UnitOfWork::save() const
{
    QFile saveFile(_dbFileName);

    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open db file.");
        return false;
    }

    QJsonObject libObject;
    write(libObject);
    saveFile.write(QJsonDocument(libObject).toJson());

    return true;
}

bool UnitOfWork::load()
{
    QFile loadFile(_dbFileName);

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open db file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    read(loadDoc.object());

    return true;
}

//-------------------Private members-------------------

template <class T>
void UnitOfWork::read(const QJsonObject &json, Repository<T> *repository)
{
    auto id = repository->getId();
    auto name = id.c_str();
    if (json.contains(name) && json[name].isArray())
    {
        QJsonArray itemArray = json[name].toArray();
        repository->clear();
        for (int i = 0; i < itemArray.size(); ++i)
        {
            QJsonObject itemObject = itemArray[i].toObject();
            T *item = new T();
            item->read(itemObject);
            repository->add(item);
        }
    }
}

template <class T>
void UnitOfWork::write(QJsonObject &json, Repository<T> *repository) const
{
    QJsonArray itemsArray;
    for (const T *item : *repository->getAll())
    {
        QJsonObject itemObject;
        item->write(itemObject);
        itemsArray.append(itemObject);
    }

    json[repository->getId().c_str()] = itemsArray;
}
