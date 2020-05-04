#include <map>
#include <list>
#include <string>

#include "street.hpp"
#include "streets.hpp"

Streets::Streets() {
    lenght = 0;
}

Streets::~Streets(){}

void Streets::AddStreet(Street street) {
    streets[street.GetID()] = street;
    lenght++;
}

int Streets::RemoveStreet(string id) {
    return streets.erase(id);
}

Street Streets::GetStreet(string id) {
    return streets[id];
}

list<Street> Streets::GetAllStreets() {
    list<Street> street_list;
    for(auto& s : streets) {
        street_list.push_back(s.second);
    }
    return street_list;
}

int Streets::GetLenght() {
    return lenght;
}




