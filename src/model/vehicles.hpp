/**
 * @file vehicles.hpp
 *
 * @author Michal Krůl (xkrulm00)
 *
 * Definice třídy obsahující seznam spojů na trase (v simulaci)
 */

#ifndef VEHICLES
#define VEHICLES

#include <QMap>
#include <QString>
#include <QList>

#include "vehicle.hpp"

using namespace std;

class Vehicles {
    public:
        /**
         * @brief Seznam(map) všech vozidel, uložených dle id čísla
         */
        QMap<int, Vehicle> vehicles;

        /**
         * @brief Přidá vozidlo do seznamu
         * @param Přidávané vozidlo
         */
        void AddVehicle(Vehicle vehicle);
        /**
         * @brief Odebere vozidlo ze seznamu
         * @param id číslo vozidla
         * @return počet odstraněných vozidel
         */
        int RemoveVehicle(int number);
        /**
         * @brief Vrátí vozidlo ze seznamu dle id čísla
         * @param id číslo vozidla
         * @return vozidlo
         */
        Vehicle GetVehicle(int number);
        /**
         * @brief Kontrolu přítomnost vozidla v seznamu
         * @param id číslo vozidla
         * @return true pokud přítomno, false jinak
         */
        bool HasVehicle(int number);
        /**
         * @brief Vrátí kopii seznamu všech vozidel
         * @return Seznam vozidel
         */
        QList<Vehicle> GetAllVehicles();
        /**
         * @brief Vrátí délku seznamu vozidel
         * @return int, délka seznamu
         */
        int GetLenght();
        /**
         * @brief Smaže všechny záznamy ze seznamu
         */
        void Restart();

        Vehicles();
        ~Vehicles();

};

#endif
