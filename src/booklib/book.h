#ifndef BOOK_H
#define BOOK_H

#include "reader.h"
#include "contentitem.h"
#include <QString>
#include <QJsonObject>

class Reader;
class Book final : public ContentItem
{
    int _id;
    QString _name;
    QString _author;
    Reader *_reader;

public:
    Book();
    Book(int, QString, QString);
    virtual int getId() const override;
    void setName(QString);
    void setAuthor(QString);
    void setReader(Reader *);
    void removeReader();

    QString getName();
    QString getAuthor();
    Reader *getReader();
    bool isAvailable();
    QString toString();

    virtual void read(const QJsonObject &) override;
    virtual void write(QJsonObject &) const override;
};

#endif // BOOK_H
