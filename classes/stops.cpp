#include <map>
#include <list>
#include <string>

#include "stop.hpp"
#include "stops.hpp"

Stops::Stops() {
    lenght = 0;
}

Stops::~Stops(){}

void Stops::AddStop(Stop stop) {
    stops[stop.GetName()] = stop;
    lenght++;
}

int Stops::RemoveStop(string name) {
    return stops.erase(name);
}

Stop Stops::GetStop(string name) {
    return stops[name];
}

list<Stop> Stops::GetAllStops() {
    list<Stop> stop_list;
    for(auto& s : stops) {
        stop_list.push_back(s.second);
    }
    return stop_list;
}

int Stops::GetLenght() {
    return lenght;
}




