#include <map>
#include <list>
#include <string>

#include "line.hpp"
#include "lines.hpp"

Lines::Lines() {
    lenght = 0;
}

Lines::~Lines(){}

void Lines::AddLine(Line line) {
    lines[line.GetLineNumber()] = line;
    lenght++;
}

int Lines::RemoveLine(int number) {
    return lines.erase(number);
}

Line Lines::GetLine(int number) {
    return lines[number];
}

list<Line> Lines::GetAllLines() {
    list<Line> line_list;
    for(auto& l : lines) {
        line_list.push_back(l.second);
    }
    return line_list;
}

int Lines::GetLenght() {
    return lenght;
}




