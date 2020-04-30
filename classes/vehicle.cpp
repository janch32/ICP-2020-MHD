#include "position.hpp"
#include "stop.hpp"
#include "street.hpp"
#include "line.hpp"
#include "vehicle.hpp"

Vehicle::Vehicle(Line l, int n, Position position){
    line = l;
    number = n;
    map_position = position;
}

Vehicle::~Vehicle()
{
}

void Vehicle::SetPosition(Position position) {
    map_position.SetXPosition(position.GetXPosition());
    map_position.SetYPosition(position.GetYPosition());
}

Position Vehicle::GetPosition() {
    return map_position;
}

Line Vehicle::GetLine() {
    return line;
}

void Vehicle::ArriveOnStop(Stop next) {
    curr_stop = next_stop;
    next_stop = next;
}

Stop Vehicle::TellStop() {
    return curr_stop;
}
