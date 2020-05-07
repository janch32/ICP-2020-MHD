#include "timetable.hpp"

Timetable::Timetable(){}

Timetable::~Timetable(){}

void Timetable::SetEntry(int time, string name) {
    timetable.insert(std::pair<int, string>(time, name));
}



void Timetable::Sort() {
    //BUBBLESORT
}
