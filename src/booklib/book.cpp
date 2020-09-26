#include "book.h"
#include <QString>
#include <QJsonObject>

Book::Book()
{
    _reader = nullptr;
}

Book::Book(int id, QString name, QString author) : Book()
{
    _id = id;
    _name = name;
    _author = author;
}

void Book::setName(QString name)
{
    _name = name;
}

void Book::setAuthor(QString author)
{
    _author = author;
}

void Book::setReader(Reader *reader)
{
    _reader = reader;
}

void Book::removeReader()
{
    _reader = nullptr;
}

int Book::getId() const
{
    return _id;
}

QString Book::getName()
{
    return _name;
}

QString Book::getAuthor()
{
    return _author;
}

Reader *Book::getReader()
{
    return _reader;
}

bool Book::isAvailable()
{
    return _reader == nullptr;
}

QString Book::toString()
{
    return QString("%1 %2: %3")
        .arg(QString::number(getId()), getAuthor(), getName());
}

void Book::read(const QJsonObject &json)
{
    if (json.contains("id") && json["id"].isDouble())
        _id = json["id"].toInt();

    if (json.contains("name") && json["name"].isString())
        _name = json["name"].toString();

    if (json.contains("author") && json["author"].isString())
        _author = json["author"].toString();
}

void Book::write(QJsonObject &json) const
{
    json["id"] = _id;
    json["name"] = _name;
    json["author"] = _author;
}
