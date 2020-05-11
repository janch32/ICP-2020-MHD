/**
 * @file mapbus.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Implementace metod prvku scény reprezentující pohyb spoje na mapě
 */

#include "mapbus.hpp"

const QBrush MapBus::defaultBrush = QBrush(QColor(0, 0, 0));
const QBrush MapBus::selectedBrush = QBrush(QColor(255, 0, 0));

MapBus::MapBus(int id, QString line, QGraphicsItem *parent) : QGraphicsObject(parent)
{
    this->id = id;
    selected = false;

    QFont font;
    font.setPixelSize(15);
    font.setWeight(QFont::Bold);

    QFontMetrics fontMetrics(font);
    auto fontWidth = fontMetrics.width(line);

    paintPath.setFillRule(Qt::FillRule::WindingFill);
    paintPath.addRect(-8, -8, 16, 16);

    paintPath.addText(-fontWidth/2, -10, font, line);
}

void MapBus::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(selected ? selectedBrush : defaultBrush);
    painter->setRenderHints(QPainter::Antialiasing);

    painter->fillPath(paintPath, painter->brush());
}

QRectF MapBus::boundingRect() const
{
    return paintPath.boundingRect();
}

QPainterPath MapBus::shape() const
{
    return paintPath;
}

bool MapBus::getSelected() const
{
    return selected;
}

void MapBus::setSelected(bool value)
{
    selected = value;
}

int MapBus::getId() const
{
    return id;
}
