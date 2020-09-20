#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
    int _id;
    QString _name;
    QString _author;
public:
    Book();
    Book(QString);
    Book(QString, QString);
    void setName(QString);
    void setAuthor(QString);
    int getId();
    QString getName();
    QString getAuthor();
};

#endif // BOOK_H
