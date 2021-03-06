/**
 * @file initialize_library.cpp
 *
 * @author Michal Krůl (xkrulm00)
 *
 * Implementace inicializace simulace
 */

#include <QtDebug>

#include "initialize_library.hpp"


void InitializeStreets(Streets *streets, StreetList parsed_streets) {
    StreetList::iterator i;

    for (i = parsed_streets.begin(); i != parsed_streets.end(); ++i) {
        streets->AddStreet(i.value());
    }
}

void InitializeLines(Lines *lines,  QHash<QString, Line> parsed_lines) {
    QHash<QString, Line>::iterator i;

    for (i = parsed_lines.begin(); i != parsed_lines.end(); ++i)
        lines->AddLine(i.value());
}

void InitializeVehicleEventTable(Lines lines, VehicleEventTable *vehicle_table) {
    QHash<QString, QTime> line_spawn;

    QList<Line> lines_list = lines.GetAllLines();

    QList<Line>::iterator i;
    Timetable t_table;
    QList<TimetableEntry> *entries;

    for( i = lines_list.begin(); i != lines_list.end(); ++i) {
        //DEBUG
        //qDebug() << i->getID();
        t_table = i->getTimetable();
        entries = t_table.getEntries();

        foreach (TimetableEntry e, *entries) {
            line_spawn.insertMulti(i->getID(),e.getStartTime());
        }
    }

    vehicle_table->InitializeTable(line_spawn);
}

void InitializeTime(QTime *time, int hours, int minutes) {
    time->setHMS(hours, minutes, 0);
}

Vehicle SpawnVehicle(Line line, int number, QPoint position, LineRoute route, TimetableEntry entry) {

    return Vehicle(line.getID(), number, position, route, entry, line);
}




