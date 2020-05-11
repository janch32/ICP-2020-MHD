/**
 * @file mapstreet.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice prvku scény reprezentující ulici na mapě
 */

#ifndef MAPSTREET_HPP
#define MAPSTREET_HPP

#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "../model/street.hpp"

/**
 * @brief Reprezentace ulice na mapě
 */
class MapStreet : public QGraphicsObject
{
    Q_OBJECT
public:
    /**
     * @brief Inicializace ulice
     * @param street Data ulice
     */
    explicit MapStreet(Street *street, QGraphicsItem *parent = 0);

    /**
     * @brief Překreslit ulici
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

    /**
     * @brief Získat obdélník ohraničující vykreslovanou plochu
     * @return Obdélník ohraničující vykreslovanou plochu
     */
    QRectF boundingRect() const override;

    /**
     * @brief Získat vykreslovaný tvar ulice
     * @return Vykreslovaný tvar ulice
     */
    QPainterPath shape() const override;

    /**
     * @brief Získat zda je ulice vykreslována jako vybraná
     * @return Je ulice vybraná
     */
    bool getSelected() const;

    /**
     * @brief Nastavit, zda se má ulice vykreslovat jako vybraná
     * @param value Má být ulice vybraná
     */
    void setSelected(bool value);

    /**
     * @brief Získat data reprezentující tuto ulici
     * @return Data ulice
     */
    Street *getStreet();

    /**
     * @brief Získat zda je ulice na mapě zvýrazněna
     * @return Je ulice zvýrazněna
     */
    bool getHighlighted() const;

    /**
     * @brief Nastavit, zda se má ulice vykreslovat zvýrazněně
     * @param value Má být zvýrazněna
     */
    void setHighlighted(bool value);

private:
    /**
     * @brief cesta pro kreslení tvaru ulice
     */
    QPainterPath paintPath;

    /**
     * @brief Cesta pro kreslení názvu ulice
     */
    QPainterPath namePath;

    /**
     * @brief Data reprezentující ulici
     */
    Street *street;

    /**
     * @brief Je ulice vybrána
     */
    bool selected;

    /**
     * @brief Je ulice zvýrazněna
     */
    bool highlighted;

    /**
     * @brief Štětec použit pro vykreslení zvýrazněné ulice
     */
    static const QBrush highlightBrush;

    /**
     * @brief Štětec použit pro vykreslení vybrané ulice
     */
    static const QBrush selectBrush;

    /**
     * @brief Tmavý štětec
     */
    static const QBrush blackBrush;

    /**
     * @brief Světlý štětec
     */
    static const QBrush whiteBrush;
};

#endif // MAPSTREET_HPP
