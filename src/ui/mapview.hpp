/**
 * @file mapview.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Definice UI prvku pro zobrazení scény s ulicemi a spoji
 */

#ifndef MAPVIEW_HPP
#define MAPVIEW_HPP

#include <QGraphicsView>
#include <QWheelEvent>
#include "map.hpp"

/**
 * @brief UI prvek pro vykreslení scény (mapy)
 *
 * Tento prvek umožňuje přiblížení/oddálení scény kolečkem myši
 */
class MapView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent = nullptr);
    ~MapView();

protected:
    /**
     * @brief Naslouchání na změnu polohy kolečka myši
     *
     * Obsluhuje oddálení/přiblížení scény
     *
     * @param event Informace o eventu
     */
    void wheelEvent(QWheelEvent *event) override;
};

#endif // MAPVIEW_HPP
