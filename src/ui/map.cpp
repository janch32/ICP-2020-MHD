/**
 * @file map.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * Implemenetace metod grafické scény (mapy) pro zobrazení ulic a spojů
 */

#include "map.hpp"

#include "mapstreet.hpp"

#include <QtDebug>

Map::Map(StreetList streets, QObject *parent) : QGraphicsScene(parent)
{
    selectedMapStreet = nullptr;
    selectedMapBus = nullptr;

    this->setBackgroundBrush(QBrush(QColor(210, 210, 210)));
    for(const auto s: streets){
        addItem(new MapStreet(s));
    }
}

Map::~Map()
{

}

void Map::changeStreetTraffic(int traffic)
{
    if(selectedMapStreet == nullptr) return;
    selectedMapStreet->getStreet()->setTraffic(traffic);
    invalidate();
}

void Map::updateBus(int id, QPoint pos)
{
    for(auto i : items()){
        if(MapBus *b = dynamic_cast<MapBus *>(i)){
            if(b->getId() != id) continue;
            b->setPos(pos);
            invalidate();
            return;
        }
    }
}

void Map::addBus(int id, QString line)
{
    addItem(new MapBus(id, line));
    invalidate();
}

void Map::removeBus(int id)
{
    if(selectedMapBus != nullptr && selectedMapBus->getId() == id){
        selectedMapBus = nullptr;
        emit busSelected(-1);
    }

    for(auto i : items()){
        if(MapBus *b = dynamic_cast<MapBus *>(i)){
            if(b->getId() != id) continue;
            removeItem(b);
        }else if(MapStreet *s = dynamic_cast<MapStreet *>(i)){
            if(selectedMapBus == nullptr) s->setHighlighted(false);
        }
    }
}

void Map::highlightStreet(QString streetId)
{
    for(auto i : items()){
        if(MapStreet *s = dynamic_cast<MapStreet *>(i)){
            if(s->getStreet()->getID() == streetId){
                s->setHighlighted(true);
                return;
            }
        }
    }
}

void Map::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    auto item = itemAt(mouseEvent->scenePos(), QTransform());

    for(auto i : items()){
        if(MapBus *b = dynamic_cast<MapBus *>(i)){
            b->setSelected(false);
        }else if(MapStreet *s = dynamic_cast<MapStreet *>(i)){
            s->setHighlighted(false);
            s->setSelected(false);
        }
    }

    selectedMapBus = dynamic_cast<MapBus *>(item);
    selectedMapStreet = dynamic_cast<MapStreet *>(item);

    if(selectedMapStreet != nullptr){
        selectedMapStreet->setSelected(true);
        emit streetSelected(selectedMapStreet->getStreet());
    }else{
        emit streetSelected(nullptr);
    }

    if(selectedMapBus != nullptr){
        selectedMapBus->setSelected(true);
        emit busSelected(selectedMapBus->getId());
    }else{
        emit busSelected(-1);
    }

    invalidate();
    QGraphicsScene::mousePressEvent(mouseEvent);
}
