/**
 * @file parseroutes.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Implementace metod třídy pro získání cest linek z CSV souboru
 */

#include "parseroutes.hpp"

QHash<QString, LineRoute> ParseRoutes::getRoutes(StreetList streets)
{
    QHash<QString, LineRoute> routes;

    while(!endOfFile()){
        auto line = getLine();
        if(line.count() < 2) continue;

        QString streetID = line[1].trimmed();
        if(!streets.contains(streetID)) continue;

        if(!routes.contains(line[0])){
            LineRoute lr;
            routes.insert(line[0], lr);
        }

        routes[line[0]].append(streets.value(streetID));
    }

    return routes;
}
