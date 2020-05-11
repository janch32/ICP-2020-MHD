/**
 * @file line.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Definice třídy linky dopravy
 */

#ifndef LINE_HPP
#define LINE_HPP

#include <QString>
#include <QList>
#include "street.hpp"
#include "timetable.hpp"

/**
 * @brief Seznam ulic, kterými linka projíždí
 *
 * Jde o Abstrakce nad QListem. Funkčně je shodné s třídou QList
 */
class LineRoute : public QList<Street*>{
};

/**
 * @brief Informace o lince hromadné dopravy
 */
class Line
{
private:
    /**
     * @brief Identifikační řetězec linky. Musí být unikatní
     */
    QString id;

    /**
     * @brief Číslo linky, které je zobrazeno v UI
     */
    QString displayNumber;

    /**
     * @brief Název konečné zastávky (směr linky)
     */
    QString destination;

    /**
     * @brief Seznam ulic, kterými linka projíždí
     */
    LineRoute streets;

    /**
     * @brief Jízdní řád linka
     */
    Timetable timetable;
public:
    /**
     * @brief Inicializuje linku s výchozími hodnotami
     *
     * Nedoporučuje se používat. Nelze poté nastavit ID linky!
     */
    Line();

    /**
     * @brief Inicializuje linku s výchozími hodnotami
     * @param id Unikátní ID linky
     */
    Line(QString id);

    /**
     * @brief Inicializuje linku
     * @param id Unikátní ID linky
     * @param displayNumber Zobrazované číslo linky
     * @param destination Zobrazovaný směr linky
     */
    Line(QString id, QString displayNumber, QString destination);

    /**
     * @brief Inicializuje linku
     * @param id Unikátní ID linky
     * @param displayNumber Zobrazované číslo linky
     * @param destination Zobrazovaný směr linky
     * @param streets Ulice, kterými linka projíždí
     */
    Line(QString id, QString displayNumber, QString destination, LineRoute streets);

    /**
     * @brief Inicializuje linku
     * @param id Unikátní ID linky
     * @param displayNumber Zobrazované číslo linky
     * @param destination Zobrazovaný směr linky
     * @param streets Ulice, kterými linka projíždí
     * @param timetable Jízdní řád linky
     */
    Line(QString id, QString displayNumber, QString destination, LineRoute streets, Timetable timetable);

    /**
     * @brief Získat unikátní ID linky
     * @return ID linky
     */
    QString getID() const;

    /**
     * @brief Získat číslo linky pro zobrazení v UI
     * @return Číslo linky
     */
    QString getDisplayNumber() const;

    /**
     * @brief Změnit číslo linky pro zobrazení v UI
     * @param Nové číslo linky
     */
    void setDisplayNumber(const QString &value);

    /**
     * @brief Získat název konečné zastávky (směru trasy)
     * @return Směr linky
     */
    QString getDestination() const;

    /**
     * @brief Změnit zobrazovaný název konečné zastávky (směru trasy)
     * @param Nový název linky
     */
    void setDestination(const QString &value);

    /**
     * @brief Získat cestu linky
     * @return Seznam ulic, kterými linka projíždí
     */
    LineRoute getRoute() const;

    /**
     * @brief Změnit cestu linky
     * @param Nový seznam ulic, kterými linka projíždí
     */
    void setRoute(const LineRoute &value);

    /**
     * @brief Získat jízdí řád linky
     * @return Jízdní řád linky
     */
    Timetable getTimetable() const;

    /**
     * @brief Změnit jízdní řád linky
     * @param Nový jízdní řád linky
     */
    void setTimetable(const Timetable &value);
};

#endif // ROUTE_HPP
