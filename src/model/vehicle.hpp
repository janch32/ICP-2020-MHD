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
        QPoint GiveDirection(Street last, Street curr);
        //float slow_step;
        //int slow_step_count;
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
        void SetSteps(int steps);
        int GetSteps();
        void DecrementSteps();
        void Step();
        QPoint GetDirection();
        int slowed;
        void FlipSlow(int i);

        /*
        void SetSlowStep(float step);
        float GetSlowStep();
        void SetSlowSteps(int steps);
        int GetSlowSteps();
        void DecrementSlowSteps();
        */
        LineRoute journey;
        TimetableEntry timetable;
        int journey_no = 0;
        float curr_journey_lenght;

};

#endif

