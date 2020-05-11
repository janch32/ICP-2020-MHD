/**
 * @file parselines.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice třídy pro získání linek z CSV souboru
 */

#ifndef PARSELINES_HPP
#define PARSELINES_HPP

#include "csvparser.hpp"
#include "../model/line.hpp"

/**
 * @brief Třída, která získá seznam linek ze souboru
 */
class ParseLines : public CsvParser
{
public:
    /**
     * @brief Získat všechny linky z otevřeného souboru
     *
     * Před zavoláním této metody je nutné otevřít soubor metodou `openFile`
     *
     * @param routes Seznam cest. Data získáná třídou `ParseRoutes`
     * @param timetables Jízdní řády linek. Data získaná třídou `ParseTimetables`
     * @return Mapovaný seznam, kde klíčem je id linky a hodnotou data samotné linky
     */
    QHash<QString, Line> getLines(QHash<QString, LineRoute> routes, QHash<QString, Timetable *> timetables);
};

#endif // PARSELINES_HPP
