#include <QJsonArray>
#include "reader.h"

Reader::Reader()
{
    _books = new std::list<Book *>();
}

Reader::Reader(int id, QString name) : Reader()
{
    _id = id;
    _name = name;
}

Reader::~Reader()
{
    delete _books;
}

int Reader::getId()
{
    return _id;
}

QString Reader::getName()
{
    return _name;
}

QString Reader::toString()
{
    return QString("%1 %2").arg(QString::number(getId()), getName());
}

void Reader::addBook(Book *b)
{
    _books->push_back(b);
}

void Reader::removeBook(Book *b)
{
    _books->remove(b);
}

void Reader::read(const QJsonObject &json)
{
    if (json.contains("id") && json["id"].isDouble())
        _id = json["id"].toInt();

    if (json.contains("name") && json["name"].isString())
        _name = json["name"].toString();

    if (json.contains("books") && json["books"].isArray())
    {
        QJsonArray booksArray = json["books"].toArray();
        _books->clear();
        for (int i = 0; i < booksArray.size(); ++i)
        {
            QJsonObject bookObject = booksArray[i].toObject();
            Book *book = new Book();
            book->read(bookObject);
            book->setReader(this);
            _books->push_back(book);
        }
    }
}

void Reader::write(QJsonObject &json) const
{
    json["id"] = _id;
    json["name"] = _name;

    QJsonArray booksArray;
    for (const Book *b : *_books)
    {
        QJsonObject bookObject;
        b->write(bookObject);
        booksArray.append(bookObject);
    }

    json["books"] = booksArray;
}
