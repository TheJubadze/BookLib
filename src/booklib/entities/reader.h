#ifndef READER_H
#define READER_H

#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <list>
#include "book.h"
#include "contentitem.h"

class Book;
class Reader final : public ContentItem
{
    int _id;
    QString _name;
    std::list<int> *_bookIds;
    std::list<Book *> *_books;

public:
    Reader();
    Reader(int id, QString name);
    ~Reader();
    virtual int getId() const override;
    QString getName();
    QString toString();
    void addBook(Book *);
    void returnBook(Book *);
    void clear();
    void setBooks(std::list<Book *> *);
    std::list<Book *> *getBooks();
    bool hasBooks();


    virtual void read(const QJsonObject &) override;
    virtual void write(QJsonObject &) const override;
};

#endif // READER_H
