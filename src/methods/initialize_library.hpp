/**
 * @file initialize_library.hpp
 *
 * @author Michal Krůl (xkrulm00)
 *
 * Definice funkcí pro inicializaci simulace
 */

#include <unistd.h>
#include <QList>
#include <QString>
#include <QHash>
#include <QTime>
#include <QPoint>

#include "../model/street.hpp"
#include "../model/streets.hpp"
#include "../model/lines.hpp"
#include "../model/eventtable.hpp"
#include "../model/vehicle.hpp"

/**
 * @brief Inicializuje seznam ulic a naplní ho naparsovanými daty ulic
 * @param streets seznam ulic
 * @param parsed_streets naparsovaná data
 */
void InitializeStreets(Streets *streets, StreetList parsed_streets);
/**
 * @brief Inicializuje seznam linek a naplní ho naparsovanými daty linek
 * @param lines senzma linke
 * @param parsed_lines naparsovaná data linke
 */
void InitializeLines(Lines *lines,  QHash<QString, Line> parsed_lines);
/**
 * @brief Inicializuje seznam událostí vozidel a naplní ho událostmi začátku jízdy vozidel všech linek
 * @param lines seznam linek
 * @param table seznam událostí
 */
void InitializeVehicleEventTable(Lines lines, VehicleEventTable *table);
/**
 * @brief Inicializuje čas simulace a nastaví ho na danout hodnotu
 * @param time čas simulace
 * @param hours hodiny
 * @param minutes minuty
 */
void InitializeTime(QTime *time, int hours, int minutes);
/**
 * @brief Vytvoří nové vozidlo
 * @param line linka
 * @param number id číslo
 * @param position aktuální pozice
 * @param route seznam ulic, které má projet
 * @param entry jízdní řd vozidla
 * @return vozidlo, Vehicle
 */
Vehicle SpawnVehicle(Line line, int number, QPoint position, LineRoute route, TimetableEntry entry);
