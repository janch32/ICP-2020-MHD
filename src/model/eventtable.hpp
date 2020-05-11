/**
 * @file eventtable.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * TODO
 */

#ifndef EVENTTABLE_H
#define EVENTTABLE_H

#include <QHash>
#include <QTime>
#include <QList>
#include "../model/vehicle.hpp"

/**
 * @brief Typ akce, enum
 */
enum ActionType {Spawn, Move, End};

class Action {
public:
    Action();
    Action(ActionType a);
    /**
     * @brief Vrátí typ akce
     * @return
     */
    ActionType GetType();
private:
    /**
     * @brief typ akce
     */
    ActionType type;

};

class Event {
public:
    Event(QString line, Action action);
    Event(int number, Action action);
    /**
     * @brief id linky
     */
    QString line;
    /**
     * @brief id vozidla
     */
    int number;
    /**
     * @brief typ akce události
     */
    Action action;
};

class EventTable {
protected:
    /**
     * @brief seznam událostí uložený dle jejich času
     */
    QHash<QTime, Event> event_table;
public:

    EventTable();
    /**
     * @brief Vrátí všechny uálosti z daného času
     * @param time čas
     * @return list událostí
     */
    QList<Event> GetEventsFromTime(QTime time);
    /**
     * @brief Přidá událost do seznamu
     * @param key čas události
     * @param value událost
     */
    void InsertEvent(QTime key, Event value);
    /**
     * @brief Smaže všechny události ze seznamu
     */
    void Restart();

};

class VehicleEventTable : public EventTable {
public:
    /**
     * @brief Vytvoří události v seznamu pro vytváření vozidel
     * @param line_spawn seznam dvojic linka-čas definující časy vytváření vozidel pro linky
     */
    void InitializeTable(QHash<QString, QTime> line_spawn);
};



#endif // EVENTTABLE_H
