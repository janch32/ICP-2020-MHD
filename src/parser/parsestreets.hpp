/**
 * @file parsestreets.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice třídy pro získání ulic z CSV souboru
 */
#ifndef PARSESTREETS_HPP
#define PARSESTREETS_HPP

#include "../model/street.hpp"
#include "csvparser.hpp"

/**
 * @brief Třída pro načtení cest ze souboru
 */
class ParseStreets : public CsvParser
{
private:
    /**
     * @brief Zpracování jednoho řádku souboru
     * @return Získané informace o ulici ze souborů.
     *         Metoda vrátí nullptr, pokud data na řádku nejsou ve správném formátu
     */
    Street *getStreet();
public:
    /**
     * @brief Načte všechny ulice z otevřeného souboru.
     *
     * Před zavoláním této metody je nutné otevřít soubor metodou `openFile`
     *
     * @return Mapovaný seznam, kde klíčem je id ulice a hodnotou ukazatel na instanci ulice
     */
    StreetList getStreets();
};

#endif // PARSESTREETS_HPP
