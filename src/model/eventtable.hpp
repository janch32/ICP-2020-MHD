#ifndef EVENTTABLE_H
#define EVENTTABLE_H

#include <QHash>
#include <QTime>
#include <QList>
#include "../model/vehicle.hpp"


enum ActionType {Spawn, Move, End};

class Action {
public:
    Action();
    Action(ActionType a);
    ActionType GetType();
private:
    ActionType type;

};

class Event {
public:
    Event(QString line, Action action);
    Event(int number, Action action);
    QString line;
    int number;
    Action action;
};

class EventTable {
protected:
    QHash<QTime, Event> event_table;
public:
    EventTable();
    QList<Event> GetEventsFromTime(QTime time);
    void InsertEvent(QTime key, Event value);
    void Restart();

};

class VehicleEventTable : public EventTable {
private:

public:
    void InitializeTable(QHash<QString, QTime> line_spawn);
};



#endif // EVENTTABLE_H
