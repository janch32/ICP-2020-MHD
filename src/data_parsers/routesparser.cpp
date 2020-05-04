/**
 * @file routesparser.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#include "routesparser.hpp"

using namespace std;

Route::Route(string routeID, string lineNumber, string destination){
    RouteID = routeID;
    LineNumber = lineNumber;
    Destination = destination;
}

RoutesParser::RoutesParser(string filePath){
    OpenFile(filePath);
}

void RoutesParser::GetRoutes(vector<Route> *routes){
    Route *r;

    while((r = GetRoute()) != nullptr){
        routes->push_back(*r);
    }
}

Route *RoutesParser::GetRoute(){
    vector<string> vals;
    int count = ReadLine(&vals);

    if(count == 0) return nullptr;

    if(count != 3){
        throw new invalid_argument("Routes definition contains invalid number of values on line");
    }

    return new Route(vals[0], vals[1], vals[2]);
}
