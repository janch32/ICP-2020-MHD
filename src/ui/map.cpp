#include "map.hpp"
#include "ui_map.h"
#include "mapstreet.hpp"

#include <QtDebug>

Map::Map(QWidget *parent) : QGraphicsView(parent)
{
    selectedMapStreet = nullptr;

    scene = new QGraphicsScene(this);
    this->setScene(scene);
    this->setBackgroundBrush(QBrush(QColor(210, 210, 210)));
}

Map::~Map()
{
    delete scene;
}

void Map::setStreets(StreetList streets)
{
    //selectedMapStreet(nullptr);
    mapStreets.clear();

    for(const auto s: streets){
        auto ms = new MapStreet(s);
        //mapStreets.append((MapStreet(s)));
        //auto ms = &mapStreets.last();
        connect(ms, &MapStreet::selectionChanged, this, &Map::changeSelectedStreet);
        scene->addItem(ms);
    }

    resetTransform();
}

void Map::changeStreetTraffic(int flow)
{
    if(selectedMapStreet == nullptr) return;
    selectedMapStreet->getStreet()->setTrafficFlow(flow / 100.0);
    scene->invalidate();
}

void Map::changeSelectedStreet(MapStreet *ms)
{
    if(ms == nullptr){
        selectedMapStreet = nullptr;
    }else if(selectedMapStreet != ms){
        if(!ms->getSelected()) return;
        if(selectedMapStreet != nullptr){
            selectedMapStreet->setSelected(false);
        }
        selectedMapStreet = ms;
    }else{
        return;
    }

    scene->invalidate();
    if(selectedMapStreet == nullptr){
        emit streetSelected(nullptr);
    }else{
        emit streetSelected(ms->getStreet());
    }
}

void Map::wheelEvent(QWheelEvent *event)
{
    event->accept();

    if(event->delta() > 0){
        scale(1.2, 1.2);
    }else{
        scale(0.8, 0.8);
    }
}
