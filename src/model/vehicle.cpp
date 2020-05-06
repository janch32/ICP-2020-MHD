#include "vehicle.hpp"

Vehicle::Vehicle() {
    number = 0;
    line_no= "0";
    map_position = QPoint(0, 0);
    //curr_stop = "ghost_street";
    //next_stop = "ghost_street";
    on_street = "ghost_street";
}

Vehicle::Vehicle(QString l, int n, QPoint position, LineRoute route, TimetableEntry timetable){
    line_no = l;
    number = n;
    map_position = position;
    //curr_stop = "ghost_street";
    //next_stop = "ghost_street";
    on_street = "ghost_street";
    journey = route;
    this->timetable = timetable;
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

QString Vehicle::GetLine() {
    return line_no;
}

void Vehicle::CommenceRide(QTime time){
    Street street = *(journey.first());
    Street next = *(timetable.getNextStop(time));
    if (street.getEnd() == next.getBegin() ||
        street.getBegin() == next.getBegin()) {
            direction = next.getBegin();
    }
    else {
        direction = next.getEnd();
    }

    on_street = street.getID();
    journey_no = 0;
    next_stop = next.getID();
}

void Vehicle::TurnOnStreet(){
    Street last = on_street;
    journey_no++;
    Street curr = *(journey[journey_no]);
    on_street = curr.getID();
    if (last.getEnd() == curr.getBegin() ||
        last.getBegin() == curr.getBegin()) {
            direction = curr.getEnd();
    }
    else {
        direction = curr.getBegin();
    }
}

void Vehicle::ArriveOnStop(QTime time) {
    next_stop = timetable.getNextStop(time)->getID();
}

QString Vehicle::TellStop() {
    return on_street;
}

QString Vehicle::TellNextStop() {
    return next_stop;
}

void Vehicle::SetStep(float step) {
    this->step = step;
}

float Vehicle::GetStep() {
    return step;
}

QPoint Vehicle::GetDirection() {
    return direction;
}
