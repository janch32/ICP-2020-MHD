#include "timetable.hpp"

TimetableCell::TimetableCell(QTime time, Street *street)
{
    this->time = time;
    this->street = street;
}

TimetableEntry::TimetableEntry()
{

}

TimetableEntry::TimetableEntry(QList<TimetableCell> cells)
{
    this->cells = cells;
}

QTime TimetableEntry::getStartTime()
{
    return cells.first().time;
}

Street *TimetableEntry::getCurrStop(QTime time)
{
    for(int i = cells.count() - 1; i <= 0; i--){
        if(cells[i].time > time) continue;
        return cells[i].street;
    }

    return nullptr;
}

Street *TimetableEntry::getNextStop(QTime time)
{
    for(int i = 0; i < cells.count(); i++){
        if(cells[i].time <= time && i != cells.count() - 1) continue;
        return cells[i].street;
    }

    return nullptr;
}

QTime TimetableEntry::getNextStopTime(QTime time)
{
    for(int i = 0; i < cells.count(); i++){
        if(cells[i].time <= time) continue;
        return cells[i].time;
    }

    return QTime();
}

void TimetableEntry::appendCell(TimetableCell cell)
{
    cells.append(cell);
}



Timetable::Timetable()
{

}

Timetable::Timetable(QList<TimetableEntry> entries)
{
    this->entries = entries;
}

QList<TimetableEntry> *Timetable::getEntries()
{
    return &entries;
}
