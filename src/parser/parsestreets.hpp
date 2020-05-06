#ifndef PARSESTREETS_HPP
#define PARSESTREETS_HPP

#include "../model/street.hpp"
#include "csvparser.hpp"

class ParseStreets : public CsvParser
{
private:
    Street *getStreet();
public:
    StreetList getStreets();
};

#endif // PARSESTREETS_HPP
