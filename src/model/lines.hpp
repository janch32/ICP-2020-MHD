/**
 * @file lines.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * TODO
 */

#ifndef LINES
#define LINES

#include <QMap>
#include <QString>
#include <QList>

#include "line.hpp"

using namespace std;

class Lines {
    private:
        /**
         * @brief seznam (map) všech linek, uložených dle jejich id
         */
        QMap<QString, Line> lines;
    public:
        /**
         * @brief Přidá linku do seznamu
         * @param přidávaná linka
         */
        void AddLine(Line line);
        /**
         * @brief Odebere linku ze seznamu
         * @param id obedírané linky
         * @return počet odebraných linek
         */
        int RemoveLine(QString id);
        /**
         * @brief Vrátí linku dle id
         * @param id linky
         * @return linka
         */
        Line GetLine(QString id);
        /**
         * @brief Vrátí list všech linek
         * @return list linek
         */
        QList<Line> GetAllLines();
        /**
         * @brief Vrátí délku seznamu linek
         * @return délka, int
         */
        int GetLenght();
        /**
         * @brief Smaže všechny linky ze seznamu
         */
        void Restart();

        Lines();
        ~Lines();

};

#endif
