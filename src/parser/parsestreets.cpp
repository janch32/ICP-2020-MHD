/**
 * @file parsestreets.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Implementace metod třídy pro získání ulic z CSV souboru
 */

#include "parsestreets.hpp"

Street *ParseStreets::getStreet()
{
    auto line = getLine();
    if(line.count() < 7) return nullptr;

    return new Street(
        line[0],
        line[6].trimmed(),
        QPoint(line[1].toInt(), line[2].toInt()),
        QPoint(line[3].toInt(), line[4].toInt()),
        line[5].toFloat()
            );
}

StreetList ParseStreets::getStreets()
{
    StreetList streets;

    while(!endOfFile()){
        auto st = getStreet();
        if(st == nullptr) continue;

        streets.insert(st->getID(), st);
    }

    return streets;
}
