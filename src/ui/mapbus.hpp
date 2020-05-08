#ifndef MAPBUS_HPP
#define MAPBUS_HPP

#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class MapBus : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit MapBus(int id, QString line, QGraphicsItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    bool getSelected() const;
    void setSelected(bool value);

    int getId() const;

private:
    QPainterPath paintPath;
    int id;
    bool selected;

    static const QBrush defaultBrush;
    static const QBrush selectedBrush;
};

#endif // MAPBUS_HPP
