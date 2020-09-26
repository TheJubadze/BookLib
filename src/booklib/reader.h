#ifndef READER_H
#define READER_H

#include <QString>
#include <QJsonObject>
#include <list>
#include "book.h"
#include "contentitem.h"

class Book;
class Reader final : public ContentItem
{
    int _id;
    QString _name;
    std::list<Book *> *_books;

public:
    Reader();
    Reader(int id, QString name);
    ~Reader();
    virtual int getId() override;
    QString getName();
    QString toString();
    void addBook(Book *);
    void removeBook(Book *);

    virtual void read(const QJsonObject &) override;
    virtual void write(QJsonObject &) const override;
};

#endif // READER_H
