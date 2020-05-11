#ifndef MAP_HPP
#define MAP_HPP

#include <QWheelEvent>
#include <QGraphicsScene>
#include "../model/street.hpp"
#include "mapstreet.hpp"
#include "mapbus.hpp"

class Map : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Map(StreetList streets, QObject *parent = nullptr);
    ~Map();

public slots:
    void changeStreetTraffic(int traffic);
    void updateBus(int id, QPoint pos);
    void addBus(int id, QString line);
    void removeBus(int id);
    void highlightStreet(QString streetId);

signals:
    void streetSelected(Street *selected);
    void busSelected(int id);

private:
    MapStreet *selectedMapStreet;
    MapBus *selectedMapBus;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
};

#endif // MAP_HPP
