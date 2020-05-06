#ifndef PARSETIMETABLES_HPP
#define PARSETIMETABLES_HPP

#include <QHash>
#include <QString>
#include <QPair>
#include "csvparser.hpp"
#include "../model/timetable.hpp"
#include "../model/line.hpp"

class ParseTimetables : public CsvParser
{
private:
    QPair<QString, TimetableEntry> getEntry(QHash<QString, LineRoute> *routes);
public:
    QHash<QString, Timetable> getTimetables(QHash<QString, LineRoute> routes);
};

#endif // PARSETIMETABLES_HPP
