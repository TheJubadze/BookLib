#ifndef UNITOFWORK_H
#define UNITOFWORK_H

#include "reader.h"
#include "repository.h"
#include <QFile>
#include <QString>
#include <QDataStream>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

class UnitOfWork
{
    Repository<Book> *_bookRepository;
    Repository<Reader> *_readerRepository;

    const QString _dbFileName = "db.json";

public:
    UnitOfWork();
    ~UnitOfWork();
    Repository<Book> *getBookRepository();
    Repository<Reader> *getReaderRepository();

    bool load();
    bool save() const;

    void read(const QJsonObject &);
    void write(QJsonObject &) const;

private:
    template <class T>
    void read(const QJsonObject &, Repository<T> *);

    template <class T>
    void write(QJsonObject &, Repository<T> *) const;
};

#endif // UNITOFWORK_H
