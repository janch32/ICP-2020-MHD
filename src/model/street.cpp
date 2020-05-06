#include "street.hpp"

Street::Street(QString id)
{
    this->id = id;
    name = "UNNAMED STREET";
    begin = QPoint(0, 0);
    end = QPoint(0, 0);
    stopPos = -1.0;
}

Street::Street(QString id, QString name, QPoint beginPos, QPoint endPos, float stopPos)
{
    this->id = id;
    this->name = name;
    this->begin = beginPos;
    this->end = endPos;
    this->stopPos = stopPos;
}

bool Street::operator==(const Street& rhs) const
{
    return id == rhs.id;
}

bool Street::operator==(const QString& rhs) const
{
    return id == rhs;
}

QString Street::getID() const
{
    return id;
}

QString Street::getName() const
{
    return name;
}

void Street::setName(const QString &value)
{
    name = value;
}

QPoint Street::getBegin() const
{
    return begin;
}

void Street::setBegin(const QPoint &value)
{
    begin = value;
}

QPoint Street::getEnd() const
{
    return end;
}

void Street::setEnd(const QPoint &value)
{
    end = value;
}

float Street::getStopPos() const
{
    return stopPos;
}

void Street::setStopPos(float value)
{
    stopPos = value;
}
