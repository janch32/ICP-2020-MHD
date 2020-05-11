#ifndef BUSDETAIL_HPP
#define BUSDETAIL_HPP

#include <QWidget>
#include <QTime>
#include <QGraphicsScene>
#include "../model/vehicle.hpp"

namespace Ui {
class BusDetail;
}

class BusDetail : public QWidget
{
    Q_OBJECT

public:
    explicit BusDetail(QWidget *parent = nullptr);
    ~BusDetail();
public slots:
    void displayBusData(QTime time, Vehicle vehicle);
    void removeBusData();

private:
    Ui::BusDetail *ui;
    QGraphicsScene *scene;
};

#endif // BUSDETAIL_HPP
