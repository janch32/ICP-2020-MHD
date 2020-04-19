#include "c_vehicle.hpp"
#include "c_position.hpp"
#include "c_stop.hpp"
#include "c_street.hpp"

Vehicle::Vehicle(int line, int s_number, Position position){
    v_line = line;
    v_s_number = s_number;
    SetPosition(position);
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

int Vehicle::GetLine() {
    return v_line;
}

void Vehicle::ArriveOnStop(string stop, string next) {
    
}
void LeaveStop() {

}
Stop* Vehicle::TellStop() {
    return curr_stop;
}