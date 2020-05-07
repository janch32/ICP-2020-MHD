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
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    bool getSelected() const;
    void setSelected(bool value);

    Street *getStreet();

signals:
    void selectionChanged(MapStreet *mapStreet);

private:
    QPainterPath paintPath;
    QPainterPath namePath;
    Street *street;
    bool selected;

    static const QBrush highlightBrush;
    static const QBrush blackBrush;
    static const QBrush whiteBrush;
};

#endif // MAPSTREET_HPP
