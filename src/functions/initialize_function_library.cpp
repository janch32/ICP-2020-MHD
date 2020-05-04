#include <unistd.h>
#include <list>
#include <string>

#include "../classes/street.hpp"
#include "../classes/stop.hpp"
#include "../classes/position.hpp"
#include "../classes/vehicle.hpp"

#include "../classes/streets.hpp"
#include "../classes/stops.hpp"
#include "../classes/lines.hpp"
#include "../classes/vehicles.hpp"

#include "../data_parsers/streetparser.hpp"

#include "initialize_function_library.hpp"

using namespace std;


void InitializeStreets(Streets *streets, StreetParser parser) {
    /* MOCK */
    Street s1("hlavn", "Hlavni nadrazi", 1.0, Position(0, 0), Position(1, 0));
    Street s2("rovna", "Rovna", 0.8, Position(1, 0), Position(1, 1));
    Street s3("horak", "Horakova", 1.0, Position(1, 1), Position(2, 1));
    Street s4("malin", "Malinovskeho namesti", 1.0, Position(2, 1), Position(0, 0));
    /* END MOCK */

    /*TODO
    *   Parsing
    */

   streets->AddStreet(s1);
   streets->AddStreet(s2);
   streets->AddStreet(s3);
   streets->AddStreet(s4);
}

void InitializeStops(Stops *stops/*, StopParser parser*/) {
    /* MOCK */
    Stop s1("Hlavni nadrazi", Position (0, 0));
    Stop s2("Rovna", Position(1, 0));
    Stop s3("Horakova", Position(1, 1));
    Stop s4("Malinovskeho namesti", Position(2, 1));
    /* END MOCK */

    /*TODO
    *   Parsing
    */

   stops->AddStop(s1);
   stops->AddStop(s2);
   stops->AddStop(s3);
   stops->AddStop(s4);

}

void InitializeLines(Stops stops, Lines *lines /*, LinesParser parser */) {
    /*TODO
    *   Parsing
    */
   list<Stop> s1;
   s1.push_back(stops.GetStop("Hlavni nadrazi"));
   s1.push_back(stops.GetStop("Rovna"));
   list<Stop> s2;
   s2.push_back(stops.GetStop("Horakova"));
   s2.push_back(stops.GetStop("Malinovskeho namesti"));

    /* MOCK */
    Line l1(42, s1);
    Line l2(70, s2);
    /* END MOCK */

    lines->AddLine(l1);
    lines->AddLine(l2);
}

Vehicle StartVehicle(Vehicles vehicles, Line line, int number, Position position) {
    Vehicle vehicle(line, number, position);

    vehicles.AddVehicle(vehicle);

    return vehicle;
}
