#include <unistd.h>
#include <list>
#include <string>

#include "c_street.hpp"
#include "c_stop.hpp"
#include "c_position.hpp"
#include "c_vehicle.hpp"

#include "function_library.hpp"

using namespace std;

std::list<Street> GStreetsList;
std::list<Stop> GStopsList;
std::list<Vehicle> GVehicleList;


void InitializeStreets() {
    Street s1("hlavn", "Hlavni nadrazi", 1.0, Position(0, 0), Position(1, 0));
    Street s2("rovna", "Rovna", 0.8, Position(1, 0), Position(1, 1));
    Street s3("horak", "Horakova", 1.0, Position(1, 1), Position(2, 1));
    Street s4("malin", "Malinovskeho namesti", 1.0, Position(2, 1), Position(0, 0));

    GStreetsList.push_back(s1);
    GStreetsList.push_back(s2);
    GStreetsList.push_back(s3);
    GStreetsList.push_back(s4);
}

void InitializeStops(){
    for (Street s : GStreetsList) {
        GStopsList.push_back(Stop(s.GetID()));
    }
}

void PrintCurrentStatus() {
    
}

void RunTraffic() {
    string trip[3] = {"hlavn", "rovna", "horak"};
    for (int i = 0; i < 10; i++) {
        if(i == 0 || i == 4 || i == 7) {
            Vehicle v (42, i, Position(1,1));
            GVehicleList.push_back(v);
            v.ArriveOnStop(trip[0],trip[1]);
        }  

     PrintCurrentStatus();      
     usleep(1000);   
    }
}