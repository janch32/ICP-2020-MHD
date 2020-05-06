#ifndef VEHICLE
#define VEHICLE

#include <QString>
#include <QPoint>
#include <QList>
#include <QTime>

#include "line.hpp"
#include "street.hpp"

using namespace std;

class Vehicle {
    private:
        int number;
        QString line_no;
        QPoint map_position;
        //QString curr_stop;
        QString next_stop;
        QString on_street;
        int steps;
        float step;
        QPoint direction;

        //QString GetNextStop(QString curr_stop);

    public:
        Vehicle();
        Vehicle(QString l, int n, QPoint position, LineRoute route, TimetableEntry timetable);
        ~Vehicle();
        int GetIdNumber();
        void SetPosition(QPoint position);
        QPoint GetPosition();
        QString GetLine();
        void CommenceRide(QTime time);
        void TurnOnStreet();
        void ArriveOnStop(QTime time);
        QString TellStop();
        QString TellNextStop();
        //void CalculateStep();
        void SetStep(float step);
        float GetStep();
        void Step();
        QPoint GetDirection();

        LineRoute journey;
        TimetableEntry timetable;
        int journey_no;
};

#endif

