#pragma once
#include <QJsonObject>

class ContentItem
{
public:
    virtual int getId() = 0;
    virtual void read(const QJsonObject &) = 0;
    virtual void write(QJsonObject &) const = 0;
};
