/**
 * @file busdetail.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 *
 * Definice UI prvku pro zobrazení informace o vybraném spoji (itinerář)
 */

#ifndef BUSDETAIL_HPP
#define BUSDETAIL_HPP

#include <QWidget>
#include <QTime>
#include <QGraphicsScene>
#include "../model/vehicle.hpp"

namespace Ui {
class BusDetail;
}

/**
 * @brief UI třída pro zobrazení informací o vybraném spoji
 */
class BusDetail : public QWidget
{
    Q_OBJECT

public:
    explicit BusDetail(QWidget *parent = nullptr);
    ~BusDetail();
public slots:
    /**
     * @brief Zobrazit nebo aktualizovat informaci o spoji
     * @param time Aktuální čas
     * @param vehicle Vybraný spoj, o kterém se mají data zobrazit
     */
    void displayBusData(QTime time, Vehicle vehicle);

    /**
     * @brief Odstranit informace o spoji
     */
    void removeBusData();

private:
    /**
     * @brief UI prvky vygenrované QTCreator designerem
     */
    Ui::BusDetail *ui;

    /**
     * @brief Scéna pro vykreslení dráhy a pozice spoje
     */
    QGraphicsScene *scene;
};

#endif // BUSDETAIL_HPP
