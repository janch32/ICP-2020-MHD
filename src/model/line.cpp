#include "line.hpp"

Line::Line()
{
    id = "";
    displayNumber = "--";
    destination = "UNKNOWN";
    streets = LineRoute();
}

Line::Line(QString id)
{
    this->id = id;
    displayNumber = "--";
    destination = "UNKNOWN";
    streets = LineRoute();
}

Line::Line(QString id, QString displayNumber, QString destination)
{
    this->id = id;
    this->displayNumber = displayNumber;
    this->destination = destination;
    streets = LineRoute();
}

Line::Line(QString id, QString displayNumber, QString destination, LineRoute streets)
{
    this->id = id;
    this->displayNumber = displayNumber;
    this->destination = destination;
    this->streets = streets;
}

Line::Line(QString id, QString displayNumber, QString destination, LineRoute streets, Timetable timetable)
{
    this->id = id;
    this->displayNumber = displayNumber;
    this->destination = destination;
    this->streets = streets;
    this->timetable = timetable;
}

LineRoute Line::getRoute() const
{
    return streets;
}

void Line::setRoute(const LineRoute &value)
{
    streets = value;
}

QString Line::getDisplayNumber() const
{
    return displayNumber;
}

void Line::setDisplayNumber(const QString &value)
{
    displayNumber = value;
}

QString Line::getDestination() const
{
    return destination;
}

void Line::setDestination(const QString &value)
{
    destination = value;
}

QString Line::getID() const
{
    return id;
}

Timetable Line::getTimetable() const
{
    return timetable;
}

void Line::setTimetable(const Timetable &value)
{
    timetable = value;
}
