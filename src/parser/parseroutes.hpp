#ifndef PARSEROUTES_HPP
#define PARSEROUTES_HPP

#include <QHash>
#include "csvparser.hpp"
#include "../model/street.hpp"
#include "../model/line.hpp"

class ParseRoutes : public CsvParser
{
public:
    QHash<QString, LineRoute> getRoutes(StreetList streets);
};

#endif // PARSETRIPS_HPP
