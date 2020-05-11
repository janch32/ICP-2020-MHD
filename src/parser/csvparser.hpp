/**
 * @file csvparser.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice třídy pro parsování CSV souborů
 */

#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <QStringList>
#include <QFile>

/**
 * @brief Třída pro parsování dat ze souboru formátu .csv
 *
 * Tuto třídu rozšiřují další třidy parsující již konkrétní data
 */
class CsvParser
{
private:
    /**
     * @brief Otevřený soubor, který je parsován
     */
    QFile file;

protected:
    /**
     * @brief Zpracovat následující řádek souboru
     * @return Seznam hodnot na řádku (hodnoty jsou odděleny čárkou)
     */
    QStringList getLine();

    /**
     * @brief Získat informaci o tom, zda byl celý soubor zpracován
     * @return Nastal konec souboru
     */
    bool endOfFile();
public:
    ~CsvParser();

    /**
     * @brief Otevřít souborp pro čtení a parsování
     * @param Cesta k souboru
     * @return Podařilo se otevřít soubor pro čtení
     */
    bool openFile(QString fileName);
};

#endif // CSVPARSER_HPP
