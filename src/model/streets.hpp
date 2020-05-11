#ifndef STREETS
#define STREETS

#include <QMap>
#include <QString>
#include <QList>

#include "street.hpp"

using namespace std;

class Streets {
    private:
        /**
         * @brief seznam (map) ulic v mapě, uložených dle id
         */
        QMap<QString, Street*> streets;
    public:
        /**
         * @brief Přidá ulici do seznamu
         * @param street přidávaná ulice
         */
        void AddStreet(Street *street);
        /**
         * @brief Odebere ulici ze seznamu
         * @param id odebírané ulice
         * @return počet odebraných ulic
         */
        int RemoveStreet(QString id);
        /**
         * @brief Vrátí ulici dle id
         * @param id ulice
         * @return ulice
         */
        Street GetStreet(QString id);
        /**
         * @brief Vrátí list všech ulic ze seznamu
         * @return list ulic
         */
        QList<Street> GetAllStreets();
        /**
         * @brief Vrátí délku seznamu
         * @return délka seznamu, int
         */
        int GetLenght();
        /**
         * @brief Smaže všechny ulice ze seznamu
         */
        void Restart();

        Streets();
        ~Streets();

};

#endif
