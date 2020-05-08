#include "parselines.hpp"

QHash<QString, Line> ParseLines::getLines(QHash<QString, LineRoute> routes, QHash<QString, Timetable *> timetables)
{
    QHash<QString, Line> lines;

    while(!endOfFile()){
        auto line = getLine();
        if(line.count() < 3) continue;
        if(!routes.contains(line[0])) continue;
        if(!timetables.contains(line[0])) continue;

        Line l(
            line[0],
            line[1],
            line[2].trimmed(),
            routes.value(line[0]),
            *timetables.value(line[0])
        );

        lines.insert(line[0], l);
    }

    return lines;
}
