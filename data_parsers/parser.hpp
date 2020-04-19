/**
 * @file parser.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Odddělovač hodnot na řádku souboru
 */
#define PARSE_DELIMETER ','

class Parser{
public:
    ~Parser();
protected:
    /**
     * Otevře soubor pro čtení a vloží ukazatel do instance třídy
     *
     * @param file Soubor, který má být otevřen
     */
    void OpenFile(string file);

    /**
     * Načte do ukazatele řetězce, které jsou na řádku odděleny znakem
     * definovaným v PARSE_DELIMETER
     *
     * @param parts Ukazatel na pole, kam se uloží načtené řetězce
     * @return int Počet načtených rětězců. Nula, pokud pokud již není
     * co k přečtení (konec souboru)
     */
    int ReadLine(string** parts);

    /**
     * Korektně uzavře otevřený soubor
     */
    void CloseFile();
private:
    /**
     * Ukazatel na parsovaný soubor
     */
    ifstream* ParsedFile = nullptr;
};
