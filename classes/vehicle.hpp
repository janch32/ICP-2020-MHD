#ifndef VEHICLE
#define VEHICLE

#include <string>

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
        Vehicle(Line l, int n, Position position);
        ~Vehicle();
        void SetPosition(Position position);
        Position GetPosition();
        Line GetLine();
        void ArriveOnStop(Stop next);
        Stop TellStop();
};

#endif

