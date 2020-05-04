/**
 * @file timetableparser.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#ifndef TIMETABLE_PARSER
#define TIMETABLE_PARSER

#include <string>
#include "parser.hpp"
#include "time.hpp"
#include <stdexcept>
#include <stdio.h>

class TimetableEntry{
public:
    TimetableEntry(string routeID, string streetID, Time arrival);
    string RouteID;
    string StreetID;
    Time Arrival;
};

class TimetableParser: Parser{
public:
    TimetableParser(string filePath);
    void GetTimetable(vector<TimetableEntry> *streets);
private:
    TimetableEntry *GetTimetableEntry();
};

#endif
