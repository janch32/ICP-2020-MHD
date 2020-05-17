/**
 * @file streets.cpp
 *
 * @author Michal Krůl (xkrulm00)
 *
 * Implementace metod třídy, která obsahuje seznam ulic v simulaci
 */

#include "streets.hpp"

Streets::Streets() {}

Streets::~Streets(){}

void Streets::AddStreet(Street *street) {
    streets.insert(street->getID(), street);
}

int Streets::RemoveStreet(QString id) {
    return streets.remove(id);
}

Street Streets::GetStreet(QString id) {
    return *streets.value(id);
}

QList<Street> Streets::GetAllStreets() {
    QList<Street> street_list;

    foreach (Street *s, streets.values()) {
        street_list.append(*s);
    }

    return street_list;
}

int Streets::GetLenght() {
    return streets.size();
}

void Streets::Restart() {
    streets.clear();
}




