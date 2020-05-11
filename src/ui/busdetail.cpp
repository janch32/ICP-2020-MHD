/**
 * @file busdetail.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Implementace metod UI prvku pro zobrazení informace o vybraném spoji
 */

#include "busdetail.hpp"
#include "ui_busdetail.h"
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>

BusDetail::BusDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusDetail)
{
    ui->setupUi(this);
    scene = nullptr;

    ui->route->setStyleSheet("background: transparent");
}

BusDetail::~BusDetail()
{
    delete ui;
    delete scene;
}

void BusDetail::displayBusData(QTime time, Vehicle vehicle)
{
    removeBusData();
    ui->line->setEnabled(true);
    ui->line->setText(vehicle.getRawLine().getDisplayNumber());
    ui->endStop->setText("Směr " + vehicle.getRawLine().getDestination());

    QPen blackPen(QColor(0, 0, 0));
    QBrush passedBrush(QColor(0, 0, 255));
    QBrush stopBrush(QColor(0, 0, 0, 0));
    QBrush busBrush(QColor(255, 0, 0));

    QRectF busIcon(0, 0, 10, 10);

    auto cells = vehicle.timetable.GetCells();

    bool passed = true;
    for(int i=0; i < cells->count(); i++){
        if(cells->value(i).street->getID() == vehicle.TellNextStop()){
            passed = false;
            if(i > 0){
                int diff = cells->value(i-1).time.secsTo(cells->value(i).time);
                int busDiff = cells->value(i-1).time.secsTo(time);

                busIcon.setTop(30*i - 30 + 30*(static_cast<float>(busDiff)/diff));
                busIcon.setHeight(10);
            }
        }

        if(i != 0){
            scene->addLine(5, 30*i - 20, 5, 30*i, blackPen);
        }

        scene->addEllipse(0, 30*i, 10, 10, blackPen, passed ? passedBrush : stopBrush);

        auto text = scene->addText(cells->value(i).time.toString("HH:mm") + " " + cells->value(i).street->getName());
        text->setPos(20, 30*i - 5);
    }

    scene->addRect(busIcon, blackPen, busBrush);
}

void BusDetail::removeBusData()
{
    delete scene;
    scene = new QGraphicsScene();
    ui->route->setScene(scene);
    ui->line->setText("");
    ui->endStop->setText("");
}
