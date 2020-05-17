/**
 * @file map.cpp
 *
 * @author Jan Chaloupka (xchalo16)
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
    multiStreetSelectMode = false;

    this->setBackgroundBrush(QBrush(QColor(210, 210, 210)));
    for(const auto s: streets){
        addItem(new MapStreet(s));
    }
}

void Map::changeStreetTraffic(int traffic)
{
    if(selectedMapStreet == nullptr) return;
    selectedMapStreet->getStreet()->setTraffic(traffic);
    invalidate();
}

void Map::closeSelectedStreet()
{
    if(selectedMapStreet == nullptr) return;

    selectedMapStreet->setClosed(true);
    invalidate(selectedMapStreet->boundingRect());
    selectedMapStreet = nullptr;
    emit streetSelected(nullptr);
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

QList<MapStreet *> Map::getSelectedStreets() const
{
    return selectedStreets;
}

Street *Map::getSelectedStreet() const
{
    if(selectedMapStreet == nullptr) return nullptr;
    return selectedMapStreet->getStreet();
}

bool Map::getMultiStreetSelectMode() const
{
    return multiStreetSelectMode;
}

void Map::setMultiStreetSelectMode(bool value)
{
    for(auto ss: selectedStreets){
        ss->setHighlighted(false);
        invalidate(ss->boundingRect());
    }
    selectedStreets.clear();

    multiStreetSelectMode = value;
}

void Map::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    auto item = itemAt(mouseEvent->scenePos(), QTransform());

    for(auto i : items()){
        if(MapBus *b = dynamic_cast<MapBus *>(i)){
            b->setSelected(false);
        }else if(MapStreet *s = dynamic_cast<MapStreet *>(i)){
            if(multiStreetSelectMode) continue;
            s->setHighlighted(false);
            s->setSelected(false);
        }
    }

    auto preselectedMapStreet = dynamic_cast<MapStreet *>(item);

    if(multiStreetSelectMode){
        if(preselectedMapStreet != nullptr && !selectedStreets.contains(preselectedMapStreet)){
            preselectedMapStreet->setHighlighted(true);
            selectedStreets.append(preselectedMapStreet);
            invalidate(preselectedMapStreet->boundingRect());
        }
        return;
    }

    // Zamezit vybrání zavřené ulice
    if(preselectedMapStreet != nullptr && preselectedMapStreet->getClosed()){
        preselectedMapStreet = nullptr;
    }

    selectedMapBus = dynamic_cast<MapBus *>(item);
    selectedMapStreet = preselectedMapStreet;

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
