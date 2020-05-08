#include "parsetimetables.hpp"
#include <QtDebug>

QPair<QString, TimetableEntry> ParseTimetables::getEntry(QHash<QString, LineRoute> *routes)
{
    QPair<QString, TimetableEntry> res;

    auto line = getLine();
    if(line.count() < 1 || !routes->contains(line[0])) return res;

    auto streets = routes->value(line[0]);
    auto cols = streets.count();

    if(line.count() < cols + 1){
        qDebug() << "Line " << line << " has incorrent number of columns - expected " << cols << " got " << line.count() - 1;
        return res;
    }

    for(int i=1; i < line.count(); i++){
        if(line[i].isEmpty()) continue;

        TimetableCell cell(QTime::fromString(line[i], "hh:mm"), streets[i-1]);
        res.second.appendCell(cell);
    }

    res.first = line[0];
    return res;
}

QHash<QString, Timetable *> ParseTimetables::getTimetables(QHash<QString, LineRoute> routes)
{
    QHash<QString, Timetable *> timetable;

    while(!endOfFile()){
        auto entry = getEntry(&routes);
        if(entry.first.isEmpty()) continue;

        if(!timetable.contains(entry.first)){
            timetable.insert(entry.first, new Timetable());
        }

        timetable.value(entry.first)->getEntries()->append(entry.second);
    }

    return timetable;
}
