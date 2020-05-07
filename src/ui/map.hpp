#ifndef MAP_HPP
#define MAP_HPP

#include <QGraphicsView>
#include "../model/street.hpp"
#include "mapstreet.hpp"
#include <QWheelEvent>

namespace Ui {
class Map;
}

class Map : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

public slots:
    void setStreets(StreetList streets);
    void changeStreetTraffic(int flow);
    void changeSelectedStreet(MapStreet *ms);
    //void changeBusPos();
    //void addBus();
    //void removeBus();

signals:
    void streetSelected(Street *selected);
    //void busSelected();

private:
    MapStreet *selectedMapStreet;
    QList<MapStreet> mapStreets;
    QGraphicsScene *scene;

protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // MAP_HPP
