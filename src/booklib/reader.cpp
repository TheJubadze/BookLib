#include <QJsonArray>
#include "reader.h"

Reader::Reader()
{
    _bookIds = new std::list<int>();
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

int Reader::getId() const
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
    b->setReader(this);
}

void Reader::removeBook(Book *b)
{
    _books->remove(b);
    b->removeReader();
}

void Reader::clear()
{
    for(auto b : *_books)
        removeBook(b);
}

void Reader::setBooks(std::list<Book *> *books)
{
    for(auto b : *books)
        if(std::find(_bookIds->begin(), _bookIds->end(), b->getId()) != _bookIds->end())
            addBook(b);
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
        for (int i = 0; i < booksArray.size(); ++i)
        {
            QJsonObject bookObject = booksArray[i].toObject();
            int bookId;
            if (json.contains("id") && json["id"].isDouble())
                bookId = json["id"].toInt();
            _bookIds->push_back(bookId);
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
        bookObject["id"] = b->getId();
        booksArray.append(bookObject);
    }

    json["books"] = booksArray;
}
