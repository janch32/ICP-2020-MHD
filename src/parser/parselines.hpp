#ifndef PARSELINES_HPP
#define PARSELINES_HPP

#include "csvparser.hpp"
#include "../model/line.hpp"

class ParseLines : public CsvParser
{
public:
    QHash<QString, Line> getLines(QHash<QString, LineRoute> routes, QHash<QString, Timetable *> timetables);
};

#endif // PARSELINES_HPP
