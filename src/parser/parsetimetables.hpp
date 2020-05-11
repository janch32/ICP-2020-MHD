/**
 * @file parsetimetables.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice třídy pro získání jízdního řádu všech linek z CSV souboru
 */

#ifndef PARSETIMETABLES_HPP
#define PARSETIMETABLES_HPP

#include <QHash>
#include <QString>
#include <QPair>
#include "csvparser.hpp"
#include "../model/timetable.hpp"
#include "../model/line.hpp"

class ParseTimetables : public CsvParser
{
private:
    /**
     * @brief Zpracování jednoho řádku souboru
     * @param routes Seznam cest. Data získáná třídou `ParseRoutes`
     * @return Získaný řádek jízdního řádu.
     *         První hodnota je id linky a druhá hodnota jsou načtené časy odjezdů ze zastávek jednoho spoje
     */
    QPair<QString, TimetableEntry> getEntry(QHash<QString, LineRoute> *routes);
public:
    /**
     * @brief Načte jízdní řády všech linek z otevřeného souboru
     *
     * Před zavoláním této metody je nutné otevřít soubor metodou `openFile`
     *
     * @param routes Seznam cest. Data získáná třídou `ParseRoutes`
     * @return Mapovaný seznam, kde klíčem je id linky a hodnotou její jízdní řád
     */
    QHash<QString, Timetable *> getTimetables(QHash<QString, LineRoute> routes);
};

#endif // PARSETIMETABLES_HPP
