/**
 * @file tripsparser.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#include "tripsparser.hpp"

using namespace std;

Trip::Trip(string routeID, string streetID){
    RouteID = routeID;
    StreetID = streetID;
}

TripsParser::TripsParser(string filePath){
    OpenFile(filePath);
}

void TripsParser::GetTrips(vector<Trip> *trips){
    Trip *t;

    while((t = GetTrip()) != nullptr){
        trips->push_back(*t);
    }
}

Trip *TripsParser::GetTrip(){
    vector<string> vals;
    int count = ReadLine(&vals);

    if(count == 0) return nullptr;

    if(count != 2){
        throw new invalid_argument("Trips definition contains invalid number of values on line");
    }

    return new Trip(vals[0], vals[1]);
}
