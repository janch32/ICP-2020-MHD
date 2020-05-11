#include "vehicle.hpp"

Vehicle::Vehicle() {
    number = 0;
    line_no= "0";
    map_position = QPoint(0, 0);
    //curr_stop = "ghost_street";
    //next_stop = "ghost_street";
    on_street = "ghost_street";
    slowed = 0;
}

Vehicle::Vehicle(QString l, int n, QPoint position, LineRoute route, TimetableEntry timetable, Line line){
    rawLine = line;
    line_no = l;
    number = n;
    map_position = position;
    //curr_stop = "ghost_street";
    //next_stop = "ghost_street";
    on_street = "ghost_street";
    journey = route;
    this->timetable = timetable;
    slowed = 0;
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

QString Vehicle::getNextStop() const
{
    return next_stop;
}

Line Vehicle::getRawLine() const
{
    return rawLine;
}

void Vehicle::setRawLine(const Line &value)
{
    rawLine = value;
}

QPoint Vehicle::GiveDirection(Street last, Street curr){
    QPoint dir;
    if (((curr.getBegin().x() == last.getEnd().x()) &&
         (curr.getBegin().y() == last.getEnd().y())) ||
     ((curr.getBegin().x() == last.getBegin().x()) &&
      (curr.getBegin().y() == last.getBegin().y()))
         ) {
        dir = curr.getEnd();
    }
    else {
        dir = curr.getBegin();
    }
    return dir;
}

void Vehicle::CommenceRide(QTime time){
    Street street = *(journey.first());
    Street n_stop = *timetable.getNextStop(time);
    Street next = *(journey[journey_no+1]);

    if (((street.getBegin().x() == next.getEnd().x()) &&
         (street.getBegin().y() == next.getEnd().y())) ||
         ((street.getBegin().x() == next.getBegin().x()) &&
         (street.getBegin().y() == next.getBegin().y()))
        ) {
            this->direction = street.getBegin();
        }
        else {
            this->direction = street.getEnd();
        }

    on_street = street.getID();
    journey_no = 0;
    next_stop = n_stop.getID();
}

void Vehicle::TurnOnStreet(){
    Street last = *(journey[journey_no]);
    this->journey_no++;
    Street curr = *(journey[journey_no]);
    this->on_street = curr.getID();
    this->direction = GiveDirection(last, curr);
    FlipSlow(0);
}

void Vehicle::ArriveOnStop(QTime time) {
    if(next_stop != on_street){
        direction = GiveDirection(*(journey[journey_no]), *(journey[journey_no+1]));
        on_street = next_stop;
        journey_no++;      
    }
    if(timetable.getNextStopTime(time).second() != 0) {
        time = time.addSecs(60);
    }
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

void Vehicle::SetSteps(int steps) {
    this->steps = steps;
}

int Vehicle::GetSteps() {
    return steps;
}

void Vehicle::DecrementSteps() {
    steps--;
}

void Vehicle::FlipSlow(int i){
    slowed = i;
}
/*
void Vehicle::SetSlowStep(float step){
    this->slow_step = step;
}

float Vehicle::GetSlowStep() {
    return this->slow_step;
}
void Vehicle::SetSlowSteps(int steps){
    this->slow_step_count = steps;
}

int Vehicle::GetSlowSteps(){
    return this->slow_step_count;
}

void Vehicle::DecrementSlowSteps(){
    slow_step_count--;
}
*/
