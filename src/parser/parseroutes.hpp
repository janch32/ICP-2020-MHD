/**
 * @file parseroutes.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice třídy pro získání cest linek z CSV souboru
 */

#ifndef PARSEROUTES_HPP
#define PARSEROUTES_HPP

#include <QHash>
#include "csvparser.hpp"
#include "../model/street.hpp"
#include "../model/line.hpp"

/**
 * @brief Třída pro načtení cest linek ze souboru
 */
class ParseRoutes : public CsvParser
{
public:
    /**
     * @brief Získá všechny cesty z otevřeného souboru
     *
     * Před zavoláním této metody je nutné otevřít soubor metodou `openFile`
     *
     * @param streets Seznam ulic. Data získáná třídou `ParseStreets`
     * @return Mapovaný seznam, kde klíčem je id linky a hodnotou cesta dané linky
     */
    QHash<QString, LineRoute> getRoutes(StreetList streets);
};

#endif // PARSETRIPS_HPP
