/**
 * @file move_library.hpp
 *
 * @author Michal Krůl (xkrulm00)
 *
 * Definice funkcí pro pohyb spojů v simulaci
 */

#include <QPoint>
#include <QtMath>

#include "../model/vehicle.hpp"

#include "../model/streets.hpp"

/**
 * @brief Vypočítá pozici po dalším kroku vozidla
 * @param dest finální poloha vozila
 * @param vd směr, kterým vozidlo míří
 * @param vp aktuální pozice vozidla
 * @param percentualy procento délky ze délky vd-vp, kterému odpovídá jeden krok
 * @return true pokud by krok přesáhl vd, false jinak
 */
bool GetDestination(QPoint *dest, QPoint vd, QPoint vp, float percentualy);
/**
 * @brief Provede jeden krok pobyhu vozidla
 * @param vehicle vozidlo
 */
void Step(Vehicle *vehicle);
/**
 * @brief Posune vozidlo na danou pozici, nastaví aktuální polohu vozidla
 * @param vehicle vozidlo
 * @param position pozice
 */
void MoveVehicle(Vehicle *vehicle, QPoint position);
/**
 * @brief Vypočítá délku kroku, kterým se vozidlo má pohybovat na následujícím úseku mezi dvěma zastávkami v závislosti na vzdáloenosti a čase dojezdu
 * @param vehicle vozidlo
 * @param streets seznam ulic
 * @param time aktuální čas
 * @param steptime délka jednoho kroku simulace v sekundách
 * @return krok, float
 */
float ComputeStep(Vehicle *vehicle, Streets streets, QTime time, int steptime);
/**
 * @brief Přepočítá aktuální délku kroku v reakci na najetí na ulici se zvýšeným provozem
 * @param vehicle vozidlo
 * @param streets seznam ulic
 * @param time aktuální čas
 * @param steptime délka jednoho kroku simulace v sekundách
 * @return krok, float
 */
float RecomputeStep(Vehicle *vehicle, Streets streets, QTime time, int steptime);
/**
 * @brief Aktualizuje časy všech ještě neprojetých zastávek v jízdním řádu vozidla dle aktuálního zpomalení z důvodu zvýšeného provozu na ulici
 * @param vehicle vozidlo
 */
void MakeDelay(Vehicle *vehicle);
/**
 * @brief Vypočítá pozici zastávky na ulici
 * @param A začátek ulice
 * @param B konec ulice
 * @param percent poloha zastávky v procentech vzdálenosti ze začátku do konce
 * @return pozice, bod
 */
QPoint GetAbsolutePosition(QPoint A, QPoint B, float percent);
/**
 * @brief Vrátí vzdálenost dvou bodů
 * @param A bod
 * @param B bod
 * @return vzdálenost, float
 */
float GetLenght(QPoint A, QPoint B);

