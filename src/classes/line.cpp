#include <string>
#include <list>

#include "stop.hpp"
#include "line.hpp"

using namespace std;

Line::Line() {}

Line::Line(int n, list<Stop> s) {
    number = n;
    stops = s;
}

Line::~Line(){}

int Line::GetLineNumber() {
    return number;
}

list<Stop> Line::GetLineStops() {
    return stops;
}

