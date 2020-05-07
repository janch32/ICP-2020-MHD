#ifndef LINE_HPP
#define LINE_HPP

#include <QString>
#include <QList>
#include "street.hpp"
#include "timetable.hpp"

class LineRoute : public QList<Street*>{
};

class Line
{
private:
    QString id;
    QString displayNumber;
    QString destination;
    LineRoute streets;
    Timetable timetable;
public:
    Line();
    Line(QString id);
    Line(QString id, QString displayNumber, QString destination);
    Line(QString id, QString displayNumber, QString destination, LineRoute streets);
    Line(QString id, QString displayNumber, QString destination, LineRoute streets, Timetable timetable);

    QString getID() const;

    QString getDisplayNumber() const;
    void setDisplayNumber(const QString &value);

    QString getDestination() const;
    void setDestination(const QString &value);

    LineRoute getRoute() const;
    void setRoute(const LineRoute &value);

    Timetable getTimetable() const;
    void setTimetable(const Timetable &value);
};

#endif // ROUTE_HPP
