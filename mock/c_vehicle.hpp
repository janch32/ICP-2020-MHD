#ifndef VEHICLE
#define VEHICLE

#include <string>

#include "c_position.hpp"
#include "c_stop.hpp"
#include "c_street.hpp"

using namespace std;

class Vehicle
{
private:
    int v_line;
    int v_s_number;
    Position map_position;
    Stop *curr_stop;
    Stop *next_stop;
    Street *on_street;

public:
    Vehicle(int line, int s_number, Position position);
    ~Vehicle();
    void SetPosition(Position position);
    Position GetPosition();
    int GetLine();
    void ArriveOnStop(string stop, string next);
    void LeaveStop();
    Stop* TellStop();
};

#endif

