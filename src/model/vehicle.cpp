#include "vehicle.hpp"

Vehicle::Vehicle() {
    number = 0;
    line_no= 0;
    map_position = QPoint(0, 0);
    curr_stop = "ghost_street";
    next_stop = "ghost_street";
    on_street = "ghost_street";
}

Vehicle::Vehicle(int l, int n, QPoint position){
    line_no = l;
    number = n;
    map_position = position;
    curr_stop = "ghost_street";
    next_stop = "ghost_street";
    on_street = "ghost_street";
}

Vehicle::~Vehicle(){}

int Vehicle::GetIdNumber(){
    return number;
}

void Vehicle::SetPosition(QPoint position) {
    map_position.setX(position.x());
    map_position.setY(position.y());
}

QPoint Vehicle::GetPosition() {
    return map_position;
}

int Vehicle::GetLine() {
    return line_no;
}

void Vehicle::ArriveOnStop(Street next) {
    curr_stop = next_stop;
    next_stop = next.getID();
}

QString Vehicle::TellStop() {
    return curr_stop;
}
