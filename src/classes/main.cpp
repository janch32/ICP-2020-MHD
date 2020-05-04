#include <iostream>


#include "clock.hpp"
#include "position.hpp"
#include "stop.hpp"
#include "line.hpp"
#include "street.hpp"
#include "vehicle.hpp"
#include "vehicles.hpp"
#include "stops.hpp"
#include "streets.hpp"
#include "lines.hpp"

using namespace std;

int main() {

    Stop stop("Karnikova", Position(1,1));

    list<Stop> stops;
    stops.push_back(stop);

    Line line(42, stops);

    Vehicle vehicle(line, 4201, Position(1,1));

    Street street("karni", "Karnikova", 1.0, Position(1,1), Position(1,2));

    Clock clock;

    Vehicles vehicles;
    vehicles.AddVehicle(vehicle);
    Lines lines;
    lines.AddLine(line);
    Streets streets;
    streets.AddStreet(street);
    Stops stops_c;
    stops_c.AddStop(stop);
    return 0;
}
