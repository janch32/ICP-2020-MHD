/**
 * @file eventtable.cpp
 *
 * @author Michal Krůl (xkrulm00)
 *
 * TODO
 */

#include "eventtable.hpp"

Action::Action() {
    type = ActionType::End;
}


Action::Action(ActionType a) {
    type = a;
}

ActionType Action::GetType()
{
    return type;
}

Event::Event(QString line, Action action){
    this->line = line;
    this->action = action;
}

Event::Event(int number, Action action){
    this->number = number;
    this->action = action;
}

EventTable::EventTable(){}

QList<Event> EventTable::GetEventsFromTime(QTime time) {
    QList<Event> event_list;

    QHash<QTime, Event>::iterator i = event_table.find(time);

    while(i != event_table.end() && i.key() == time) {
        event_list.append(i.value());
        ++i;
    }

    return event_list;
}

void VehicleEventTable::InitializeTable(QHash<QString, QTime> line_spawn) {
    QHash<QString, QTime>::iterator i;

    for(i = line_spawn.begin(); i != line_spawn.end(); ++i) {
        Event e(i.key(), Spawn);
        event_table.insertMulti(i.value(), e);
    }
}

void EventTable::InsertEvent(QTime key, Event value) {
    event_table.insert(key,value);
}

void EventTable::Restart(){
    event_table.clear();
}
