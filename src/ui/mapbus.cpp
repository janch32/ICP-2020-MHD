#include "mapbus.hpp"

const QBrush MapBus::defaultBrush = QBrush(QColor(0, 0, 0));
const QBrush MapBus::selectedBrush = QBrush(QColor(0, 0, 255));

MapBus::MapBus(int id, QString line, QGraphicsItem *parent)
{
    this->id = id;
    selected = false;

    QFont font;
    font.setPixelSize(10);

    QFontMetrics fontMetrics(font);
    auto fontWidth = fontMetrics.width(line);

    paintPath.setFillRule(Qt::FillRule::WindingFill);
    paintPath.addRect(-8, -8, 16, 16);

    paintPath.addText(-fontWidth/2, -10, font, line);
}

void MapBus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
