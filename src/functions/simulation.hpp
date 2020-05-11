/**
 * @file simulation.hpp
 *
 * @author Michal Krůl (xkrulm00)
 *
 * Definice hlavní třídy simulace
 */

#ifndef SIMULATION
#define SIMULATION

#include <QThread>
#include <QList>

#include "../model/streets.hpp"
#include "../model/lines.hpp"
#include "../model/eventtable.hpp"
#include "../model/vehicles.hpp"

#include "../methods/initialize_library.hpp"
#include "../methods/move_library.hpp"

class Simulation{
private:
    /**
     * @brief seznam ulic v simulaci
     */
    Streets streets;
    /**
     * @brief seznam linek v simulaci
     */
    Lines lines;
    /**
     * @brief čas simulace
     */
    QTime time;
    /**
     * @brief aktuální krok simulace v sekundách
     */
    int steptime;
    /**
     * @brief seznam vozidel v simulaci
     */
    Vehicles vehicles;
public:
    /**
     * @brief seznam všech vozidel na mapě s jejich aktuální polohou
     */
    QHash<int, QPoint> move_log;
    /**
     * @brief seznam událostí simulace
     */
    VehicleEventTable event_table;
    /**
     * @brief Hlavní funkce programu, provádí simulaci
     * @param délka simulace v sekundách
     */
    void Simulate(int seconds);
    /**
     * @brief Provede inicializaci simulace, používá funkce z initialize_library
     * @param parsed_streets parsovaná data o ulicích
     * @param parsed_lines parsovaná data o linkách
     */
    void InitializeSimulation(StreetList parsed_streets, QHash<QString, Line> parsed_lines);
    /**
     * @brief Nastaví čas na hodnotu
     * @param start_hours hodiny
     * @param start_minutes minuty
     */
    void SetTime(int start_hours, int start_minutes);
    /**
     * @brief Vrátí vozidlo ze seznamu dle jeho id čísla
     * @param vehicleId id číslo vozidla
     * @return vozidlo, vehicle
     */
    Vehicle GetVehicleById(int vehicleId);
    /**
     * @brief Kontroluje zda seznam obsahuje vozidlo s daným id číslem
     * @param vehicleId id číslo vozidla
     * @return true pokud ano, false jinak
     */
    bool HasVehicleById(int vehicleId);
    /**
     * @brief Vrátí aktuální krok simulace v sekundách
     * @return krok, int
     */
    int GetStepTime();
    /**
     * @brief Nastaví aktuální krok simulace
     * @param steptime nový krok simulace v sekundách
     */
    void SetStepTime(int steptime);
    /**
     * @brief celkévý počet vozidel v celém čase simulace, využívá se pro unikátnost id vozidel
     */
    int vehicle_count = 0;
    /**
     * @brief TODO: Změní trasu vozidel
     * @param no
     */
    void AlternateLineRoute(int no);
    /**
     * @brief Provede restart simulace, využívá Restart funkce seznamů
     */
    void Restart();
};

#endif
