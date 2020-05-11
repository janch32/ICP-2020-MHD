/**
 * @file map.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice grafické scény (mapy) pro zobrazení ulic a spojů
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <QWheelEvent>
#include <QGraphicsScene>
#include "../model/street.hpp"
#include "mapstreet.hpp"
#include "mapbus.hpp"

/**
 * @brief Scéna zobrazující ulice a aktivní spoje
 */
class Map : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Map(StreetList streets, QObject *parent = nullptr);
    ~Map();

public slots:
    /**
     * @brief Změnit provoz na aktuálně vybrané ulici
     * @param traffic Nová hodnota provozu (zpoždení v sec)
     */
    void changeStreetTraffic(int traffic);

    /**
     * @brief Aktualizovat polohu spoje na mapě
     * @param id ID spoje v simulaci
     * @param pos Nová pozice spoje
     */
    void updateBus(int id, QPoint pos);

    /**
     * @brief Přidat spoj k zobrazení na mapě
     * @param id ID spoje v simulaci
     * @param line Zobrazované číslo linky
     */
    void addBus(int id, QString line);

    /**
     * @brief Odstranit spoj z mapy
     * @param id ID spoje v simulaci
     */
    void removeBus(int id);

    /**
     * @brief Zvýraznit ulici na mapě
     * @param streetId ID zvýrazněné ulice
     */
    void highlightStreet(QString streetId);

signals:
    /**
     * @brief Změnila se vybraná ulice
     * @param selected Ukazatel na instanci vybrané ulice.
     *        nullptr, pokud již není vybraná žádná ulice
     */
    void streetSelected(Street *selected);

    /**
     * @brief Změnil se vybraný spoj
     * @param id Nové ID vybrného spoje.
     *        < 0 pokud jíž není vybrán žádný spoj
     */
    void busSelected(int id);

private:
    /**
     * @brief Vybraná ulice
     */
    MapStreet *selectedMapStreet;

    /**
     * @brief Vybraný spoj
     */
    MapBus *selectedMapBus;

protected:
    /**
     * @brief Odchytávat kliknutí do scény pro výběr spoje/ulice
     * @param mouseEvent Data kliknutí myši
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
};

#endif // MAP_HPP
