#ifndef VEHICLE
#define VEHICLE

#include <string>

#include "position.hpp"
#include "stop.hpp"
#include "line.hpp"
#include "street.hpp"

using namespace std;

class Vehicle {
    private:
        int number;
        Line line;
        Position map_position;
        Stop curr_stop;
        Stop next_stop;
        Street on_street;

    public:
        Vehicle();
        Vehicle(Line l, int n, Position position);
        ~Vehicle();
        int GetIdNumber();
        void SetPosition(Position position);
        Position GetPosition();
        Line GetLine();
        void ArriveOnStop(Stop next);
        Stop TellStop();
        list<string> journey;
};

#endif

