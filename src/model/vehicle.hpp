#ifndef VEHICLE
#define VEHICLE

#include <QString>
#include <QPoint>
#include <QList>

#include "line.hpp"
#include "street.hpp"

using namespace std;

class Vehicle {
    private:
        int number;
        int line_no;
        QPoint map_position;
        QString curr_stop;
        QString next_stop;
        QString on_street;

    public:
        Vehicle();
        Vehicle(int l, int n, QPoint position);
        ~Vehicle();
        int GetIdNumber();
        void SetPosition(QPoint position);
        QPoint GetPosition();
        int GetLine();
        void ArriveOnStop(Street next);
        QString TellStop();
        LineRoute journey;
};

#endif

