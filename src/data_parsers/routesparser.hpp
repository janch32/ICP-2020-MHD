/**
 * @file routesparser.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#ifndef ROUTES_PARSER
#define ROUTES_PARSER

#include <string>
#include "parser.hpp"
#include <stdexcept>

class Route{
public:
    Route(string routeID, string lineNumber, string destination);
    string RouteID;
    string LineNumber;
    string Destination;
};

class RoutesParser: Parser{
public:
    RoutesParser(string filePath);
    void GetRoutes(vector<Route> *routes);
private:
    Route *GetRoute();
};

#endif
