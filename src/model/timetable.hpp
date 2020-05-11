/**
 * @file timetable.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Definice tříd pro práci s jízdním řádem
 */

#ifndef TIMETABLE_HPP
#define TIMETABLE_HPP

#include <QTime>
#include <QList>
#include "street.hpp"

/**
 * @brief Buňka v tabulce jízdního řádu (čas příjezdu do zastávky)
 */
class TimetableCell{
public:
    /**
     * @brief time Čas příjezdu na zastávku
     */
    QTime time;

    /**
     * @brief street Zastávka ulice, pro kterou tento čas platí
     */
    Street* street;

    TimetableCell();

    /**
     * @brief Inicializace buňky tabulky jízdního řádu
     * @param time Čas příjezdu na zastávku
     * @param street Zastávka ulice, pro kterou tento čas platí
     */
    TimetableCell(QTime time, Street *street);
};

/**
 * @brief Třída reprezentující řádek tabulky jízdního řádu
 *
 * Jedná se o itinerář jednoho spoje
 */
class TimetableEntry{
private:
    /**
     * @brief Buňky tabulky spoje jízdního řádu (časy příjezdu do zastávek)
     */
    QList<TimetableCell> cells;

public:
    TimetableEntry();

    /**
     * @brief Inicilizace informací o časování jednoho spoje
     * @param cells Buňky tabulky spoje jízdního řádu (časy příjezdu do zastávek)
     */
    TimetableEntry(QList<TimetableCell> cells);

    /**
     * @brief Získat čas odjezdu z první zastávky
     * @return Čas odjezdu z první zastávky
     */
    QTime getStartTime();

    /**
     * @brief Podle času time vrátí poslední projetou zastávku
     * @param time Akutální čas
     * @return Ulice s poslední projetou zastávku
     */
    Street* getCurrStop(QTime time);

    /**
     * @brief Podle času time vrátí následující zastávku
     * @param time Akutální čas
     * @return Ulice s následující zastávkou
     */
    Street* getNextStop(QTime time);

    /**
     * @brief Podle času time vrátí čas příjezdu do následující zastávky
     * @param time Akutální čas
     * @return Čas příjezdu do následující zastávky
     */
    QTime getNextStopTime(QTime time);

    /**
     * @brief Přidá na konec buňku obsahující čas příjezdu do zastávky
     * @param cell Buňka obsahující čas příjezdu do zastávky
     */
    void appendCell(TimetableCell cell);

    /**
     * @brief Vrátit seznam všech zastávek a časů příjezdu spoje
     * @return Seznam všech zastávek a časů příjezdu spoje
     */
    QList<TimetableCell>* GetCells();
};

/**
 * @brief Jízdní řád linky obsahující informace o časech průjezdů všech spojů této linky
 */
class Timetable
{
private:
    /**
     * @brief Časy jízd jednotlivých spojů
     */
    QList<TimetableEntry> entries;
public:
    Timetable();

    /**
     * @brief Inicializuje jízdní řád jednoho spoje
     * @param entries jízdy jednotlivých spojů
     */
    Timetable(QList<TimetableEntry> entries);

    /**
     * @brief Získat jízdy jednotlivých spojů
     * @return Seznam jízd jednotlivých spojů
     */
    QList<TimetableEntry> *getEntries();
};

#endif // TIMETABLE_HPP
