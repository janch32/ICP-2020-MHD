#ifndef MAPSTREET_HPP
#define MAPSTREET_HPP

#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "../model/street.hpp"

class MapStreet : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit MapStreet(Street *street, QGraphicsItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    bool getSelected() const;
    void setSelected(bool value);

    Street *getStreet();

    bool getHighlighted() const;
    void setHighlighted(bool value);

private:
    QPainterPath paintPath;
    QPainterPath namePath;
    Street *street;
    bool selected;
    bool highlighted;

    static const QBrush highlightBrush;
    static const QBrush selectBrush;
    static const QBrush blackBrush;
    static const QBrush whiteBrush;
};

#endif // MAPSTREET_HPP
