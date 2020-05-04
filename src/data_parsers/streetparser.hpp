/**
 * @file streetparser.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#ifndef STREET_PARSER
#define STREET_PARSER

#include <string>
#include "parser.hpp"
#include "../classes/street.hpp"
#include "../classes/position.hpp"
#include <stdexcept>

class StreetParser: Parser{
public:
    StreetParser(string filePath);
    void GetStreets(vector<Street> *streets);
private:
    Street *GetStreet();
};

#endif
