#pragma once
#include <QJsonObject>

class ContentItem
{
public:
    virtual int getId() const = 0;
    virtual void read(const QJsonObject &) = 0;
    virtual void write(QJsonObject &) const = 0;
};
