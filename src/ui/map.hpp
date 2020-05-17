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

    /**
     * @brief Je nastaven mód výběru ulic
     * @return Je aktivovaný mód výběru ulic
     */
    bool getMultiStreetSelectMode() const;

    /**
     * @brief Nastavit mód výběru ulic
     * @param value Má se přejít do módu výběru ulic
     */
    void setMultiStreetSelectMode(bool value);

    /**
     * @brief Získat seznam vybranch ulic
     * @return Seznam vybraných ulic
     */
    QList<Street *> getSelectedStreets() const;

    /**
     * @brief Záská právě vybranou ulici
     * @return Vybraná ulice nebo nullptr, pokud není vybraná žádná
     */
    Street *getSelectedStreet() const;

public slots:
    /**
     * @brief Změnit provoz na aktuálně vybrané ulici
     * @param traffic Nová hodnota provozu (zpoždení v sec)
     */
    void changeStreetTraffic(int traffic);

    /**
     * @brief Signalizovat, že má být ulice uzavřena
     */
    void closeSelectedStreet();

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

    /**
     * @brief Nastala změna v seznamu vybraných ulic
     */
    void streetListChanged();

private:
    /**
     * @brief Je zapnutý mód výběru více ulic
     */
    bool multiStreetSelectMode;

    /**
     * @brief Vybraná ulice
     */
    MapStreet *selectedMapStreet;

    /**
     * @brief Pole vybraných ulic (v případě režimu výběru více ulic)
     */
    QList<MapStreet *> selectedStreets;

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
