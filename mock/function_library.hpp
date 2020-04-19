#include <fstream>
#include <iostream>
#include <list>

#include "c_street.hpp"
#include "c_stop.hpp"
#include "c_vehicle.hpp"

extern std::list<Street> GStreetsList;
extern std::list<Stop> GStopsList;
extern std::list<Vehicle> GVehicleList;

void InitializeStreets();

void InitializeStops();

void RunTraffic();



