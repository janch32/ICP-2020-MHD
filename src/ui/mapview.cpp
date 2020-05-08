#include "mapview.hpp"

MapView::MapView(QWidget *parent) : QGraphicsView(parent)
{

}

MapView::~MapView()
{

}

void MapView::wheelEvent(QWheelEvent *event)
{
    event->accept();

    if(event->delta() > 0){
        scale(1.2, 1.2);
    }else{
        scale(0.8, 0.8);
    }

    //invalidateScene();
}
