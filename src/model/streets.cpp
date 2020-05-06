#include "streets.hpp"

Streets::Streets() {}

Streets::~Streets(){}

void Streets::AddStreet(Street *street) {
    streets.insert(street->getID(), *street);
}

int Streets::RemoveStreet(QString id) {
    return streets.remove(id);
}

Street Streets::GetStreet(QString id) {
    return streets.value(id);
}

QList<Street> Streets::GetAllStreets() {
    QList<Street> street_list = streets.values();

    return street_list;
}

int Streets::GetLenght() {
    return streets.size();
}




