/**
 * @file tripsparser.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#ifndef TRIPS_PARSER
#define TRIPS_PARSER

#include <string>
#include "parser.hpp"
#include <stdexcept>

class Trip{
public:
    Trip(string routeID, string streetID);
    string RouteID;
    string StreetID;
};

class TripsParser: Parser{
public:
    TripsParser(string filePath);
    void GetTrips(vector<Trip> *streets);
private:
    Trip *GetTrip();
};

#endif
