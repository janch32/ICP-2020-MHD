#ifndef MAPVIEW_HPP
#define MAPVIEW_HPP

#include <QGraphicsView>
#include <QWheelEvent>
#include "map.hpp"

class MapView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent = nullptr);
    ~MapView();

protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // MAPVIEW_HPP
