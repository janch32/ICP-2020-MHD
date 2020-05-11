/**
 * @file mapbus.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Definice prvku scény reprezentující pohyb spoje na mapě
 */

#ifndef MAPBUS_HPP
#define MAPBUS_HPP

#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

/**
 * @brief Reprezentace spoje na mapě
 */
class MapBus : public QGraphicsObject
{
    Q_OBJECT
public:
    /**
     * @brief Inicializace spoje na mapě
     * @param id ID spoje v simulaci
     * @param line Zobrazované číslo linky
     */
    explicit MapBus(int id, QString line, QGraphicsItem *parent = 0);

    /**
     * @brief Překreslit spoj
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

    /**
     * @brief Získat obdélník ohraničující vykreslovanou plochu
     * @return Obdélník ohraničující vykreslovanou plochu
     */
    QRectF boundingRect() const override;

    /**
     * @brief Získat vykreslovaný tvar spoje
     * @return Vykreslovaný tvar spoje
     */
    QPainterPath shape() const override;

    /**
     * @brief Získat zda je spoj vykreslován jako vybraný
     * @return Je spoj vybraný
     */
    bool getSelected() const;

    /**
     * @brief Nastavit, zda se má spoj vykreslovat jako vybraný
     * @param value Má být spoj vybraný
     */
    void setSelected(bool value);

    /**
     * @brief Získat ID poje v simulaci
     * @return ID spoje v simulaci
     */
    int getId() const;

private:
    /**
     * @brief Tvar pro vykreslení ve scéně
     */
    QPainterPath paintPath;

    /**
     * @brief ID spoje v simulaci
     */
    int id;

    /**
     * @brief Je spoj vybrán
     */
    bool selected;

    /**
     * @brief Štětec pro vykreslení spoje v normálním stavu
     */
    static const QBrush defaultBrush;

    /**
     * @brief Štětec pro vykreslení spoje ve vybraném stavu
     */
    static const QBrush selectedBrush;
};

#endif // MAPBUS_HPP
