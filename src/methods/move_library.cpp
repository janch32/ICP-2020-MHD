#include "move_library.hpp"

bool GetDestination(QPoint *dest, QPoint vd, QPoint vp, float percentualy) {
    bool overflow = false;
    if(vd.x() > vp.x()) {
        //pricitame k souradnici x
        dest->setX( vp.x() + ( (vd.x() - vp.x()) * (percentualy/100) ) );
        if(dest->x() > vd.x()) {overflow = true;}
        else {
            if (vd.y() > vp.y()) {
                //pricitame k souradnici y
                dest->setY( vp.y() + ( (vd.y() - vp.y()) * (percentualy/100)) );
                if(dest->y() > vd.y()) {overflow = true;}
            }
            else{//odcitame od souradnice y
                dest->setY( vp.y() - ( (vp.y() - vd.y()) * (percentualy/100)) );
                if(dest->y() < vd.y()) {overflow = true;}
            }
        }
    }
    else {
        //odcitame od souradice x
        dest->setX(vp.x() - ( (vp.x() - vd.x()) * (percentualy/100) ));
        if(dest->x() < vd.x()) {overflow = true;}
        else {
            if (vd.y() > vp.y()) {
                //pricitame k souradnici y
                dest->setY( vp.y() + ( (vd.y() - vp.y()) * (percentualy/100)) );
                if(dest->y() > vd.y()) {overflow = true;}
            }
            else{//odcitame od souradnice y
                dest->setY( vp.y() - ( (vp.y() - vd.y()) * (percentualy/100)) );
                if(dest->y() < vd.y()) {overflow = true;}
            }
        }
    }
    return overflow;

}

void Step(Vehicle *vehicle) {

    float step = vehicle->GetStep();
    float lenght = GetLenght(vehicle->GetDirection(), vehicle->GetPosition());

    float percentualy = step / (lenght/100);
    QPoint dest;
    QPoint vd = vehicle->GetDirection();
    QPoint vp = vehicle->GetPosition();

    bool overflow;

    overflow = GetDestination(&dest, vd, vp, percentualy);

    if(overflow) {
        //TODO: move za roh
        float part_step = step - GetLenght(vd, vp);
        vehicle->TurnOnStreet();
        vp = vd;
        vd = vehicle->GetDirection();
        Street street = *(vehicle->journey[vehicle->journey_no]);

        lenght = GetLenght(vehicle->GetDirection(), vehicle->GetPosition());

        percentualy = part_step / (lenght/100);

        GetDestination(&dest, vd, vp, percentualy);

        MoveVehicle(vehicle,dest);
    }
    else {
        MoveVehicle(vehicle, dest);      
    }
    vehicle->DecrementSteps();
}

float ComputeStep(Vehicle *vehicle, Streets streets, QTime time, int steptime) {
    float step;
    int no = vehicle->journey_no;
    QPoint position = vehicle->GetPosition();
    Street next_stop = streets.GetStreet(vehicle->TellNextStop());
    QTime dest_time = vehicle->timetable.getNextStopTime(time.addSecs(1));
    if (dest_time > time) {
        dest_time = vehicle->timetable.getNextStopTime(time.addSecs(60));
    }

    float length;
    length = GetLenght(position, vehicle->GetDirection());

    no++;
    Street s = *(vehicle->journey[no]);
    //cyklus se provadi pokud ma projet ulici bez zastaveni
    while (s.getID() != next_stop.getID()) {
        length += GetLenght(s.getEnd(), s.getBegin());
        no++;
        s = *(vehicle->journey[no]);
    }

    Street last_street = *(vehicle->journey[no - 1]);
    if ((
                (last_street.getEnd().x() == s.getBegin().x()) &&
                (last_street.getEnd().y() == s.getBegin().y())
         )
            ||
        (
                (last_street.getBegin().x() == s.getBegin().x()) &&
                (last_street.getBegin().y() == s.getBegin().y())
        )) {
        length += GetLenght(GetAbsolutePosition(s.getEnd(), s.getBegin(), s.getStopPos()), s.getBegin());
    }
    else { //pokud nesouhlasi -> souhlasi s koncem
        length += GetLenght(GetAbsolutePosition(s.getEnd(), s.getBegin(), s.getStopPos()), s.getEnd());
    }

    step = length / (time.secsTo(dest_time) / steptime);

    vehicle->curr_journey_lenght = length;

    vehicle->SetSteps(round(length/step));

    return step;
}

float RecomputeStep(Vehicle *vehicle, Streets streets, QTime time, int steptime) {
    float step;
    int no = vehicle->journey_no;
    QPoint position = vehicle->GetPosition();
    Street next_stop = streets.GetStreet(vehicle->TellNextStop());
    QTime dest_time = vehicle->timetable.getNextStopTime(time.addSecs(1));
    Street last_street;

    float length = 0;

    Street s = *(vehicle->journey[no]);
    if (s.getID() == next_stop.getID()) {

            length = GetLenght(GetAbsolutePosition(s.getEnd(), s.getBegin(), s.getStopPos()), position);

    }
    else {
        //cyklus se provadi pokud ma projet ulici bez zastaveni
        while (s.getID() != next_stop.getID()) {
            length += GetLenght(s.getEnd(), s.getBegin());
            no++;
            s = *(vehicle->journey[no]);
        }

        last_street = *(vehicle->journey[no - 1]);
        if ((
                    (last_street.getEnd().x() == s.getBegin().x()) &&
                    (last_street.getEnd().y() == s.getBegin().y())
             )
                ||
            (
                    (last_street.getBegin().x() == s.getBegin().x()) &&
                    (last_street.getBegin().y() == s.getBegin().y())
            )) {
            length += GetLenght(GetAbsolutePosition(s.getEnd(), s.getBegin(), s.getStopPos()), s.getBegin());
        }
        else { //pokud nesouhlasi -> souhlasi s koncem
            length += GetLenght(GetAbsolutePosition(s.getEnd(), s.getBegin(), s.getStopPos()), s.getEnd());
        }
    }

    step = length / (time.secsTo(dest_time) / steptime);

    vehicle->curr_journey_lenght = length;

        vehicle->SetSteps(round(length/step + 0.5));

    return step;
}

void MakeDelay(Vehicle *vehicle) {
    int delay = vehicle->journey[vehicle->journey_no]->getTraffic();
    QList<TimetableCell>* cell_list = vehicle->timetable.GetCells();
    QString curr = vehicle->TellStop();
    int passed = 0;

    for(QList<TimetableCell>::iterator i = cell_list->begin(); i != cell_list->end(); ++i){
        if(!passed && i->street->getID() == curr) {
            passed = !passed;
        }
        if(passed) {
            i->time = i->time.addSecs(delay);
        }
    }
}

/**
 * @brief Posune vozidlo na danou pozici
 *
 * @param vehicle
 * @param position
 */
void MoveVehicle(Vehicle *vehicle, QPoint position) {
    vehicle->SetPosition(position);
}

/**
 * @brief GetAbsolutePosition
 * @param A - end
 * @param B - begin
 * @param percent from begin
 */
QPoint GetAbsolutePosition(QPoint A, QPoint B, float percent) {
    QPoint ret;

    ret.setX(( ( A.x() - B.x() ) * (percent) ) + B.x());
    ret.setY(( ( A.y() - B.y() ) * (percent) ) + B.y());

    return ret;
}
/**
 * @brief GetLenght
 * @param A - end
 * @param B - begin
 * @return
 */
float GetLenght(QPoint A, QPoint B) {
    return sqrt(pow(A.x() - B.x(), 2) + pow(A.y() - B.y(), 2));
}
