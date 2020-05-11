#ifndef TIMETABLE_HPP
#define TIMETABLE_HPP

#include <QTime>
#include <QList>
#include "street.hpp"

class TimetableCell{
public:
    QTime time;
    Street* street;
    TimetableCell();
    TimetableCell(QTime time, Street *street);
};

class TimetableEntry{
private:
    QList<TimetableCell> cells;

public:
    TimetableEntry();
    TimetableEntry(QList<TimetableCell> cells);

    QTime getStartTime();
    Street* getCurrStop(QTime time);
    Street* getNextStop(QTime time);
    QTime getNextStopTime(QTime time);
    void appendCell(TimetableCell cell);
    QList<TimetableCell>* GetCells();
};

class Timetable
{
private:
    QList<TimetableEntry> entries;
public:
    Timetable();
    Timetable(QList<TimetableEntry> entries);

    QList<TimetableEntry> *getEntries();
};

#endif // TIMETABLE_HPP
