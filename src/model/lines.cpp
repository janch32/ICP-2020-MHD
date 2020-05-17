/**
 * @file lines.cpp
 *
 * @author Michal Krůl (xkrulm00)
 *
 * Implementace metod třídy, která obsahuje seznam linek
 */

#include "lines.hpp"

Lines::Lines() {}

Lines::~Lines(){}

void Lines::AddLine(Line line) {
    lines.insert(line.getID(), line);
}

int Lines::RemoveLine(QString id) {
    return lines.remove(id);
}

Line Lines::GetLine(QString id) {
    return lines.value(id);
}

QList<Line> Lines::GetAllLines() {
    QList<Line> line_list = lines.values();

    return line_list;
}

int Lines::GetLenght() {
    return lines.size();
}

void Lines::Restart() {
    lines.clear();
}
