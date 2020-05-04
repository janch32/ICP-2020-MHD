/**
 * @file timetableparser.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#include "timetableparser.hpp"

using namespace std;

TimetableEntry::TimetableEntry(string routeID, string streetID, Time arrival){
    RouteID = routeID;
    StreetID = streetID;
    Arrival = arrival;
}

TimetableParser::TimetableParser(string filePath){
    OpenFile(filePath);
}

void TimetableParser::GetTimetable(vector<TimetableEntry> *timetable){
    TimetableEntry *te;

    while((te = GetTimetableEntry()) != nullptr){
        timetable->push_back(*te);
    }
}

TimetableEntry *TimetableParser::GetTimetableEntry(){
    vector<string> vals;
    int count = ReadLine(&vals);

    if(count == 0) return nullptr;

    if(count != 3){
        throw new invalid_argument("Timetable definition contains invalid number of values on line");
    }

    int hours = 0;
    int minutes = 0;
    sscanf(vals[2].c_str(), "%d:%d", &hours, &minutes);

    Time arrival(hours, minutes, 0);

    return new TimetableEntry(vals[0], vals[1], arrival);
}
