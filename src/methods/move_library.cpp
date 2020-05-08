#include "move_library.hpp"

void Step(Vehicle *vehicle) {

    float step = vehicle->GetStep();
    Street street = *(vehicle->journey[vehicle->journey_no]);
    float lenght = GetLenght(vehicle->GetDirection(), vehicle->GetPosition());

    float percentualy = step / (lenght/100);
    QPoint dest;
    QPoint vd = vehicle->GetDirection();
    QPoint vp = vehicle->GetPosition();

    bool overflow = false;

    if(vd.x() > vp.x()) {
        //pricitame k souradnici x
        dest.setX( vp.x() + ( (vd.x() - vp.x()) * (percentualy/100) ) );
        if(dest.x() > vd.x()) {overflow = true;}
        else {
            if (vd.y() > vp.y()) {
                //pricitame k souradnici y
                dest.setY( vp.y() + ( (vd.y() - vp.y()) * (percentualy/100)) );
            }
            else{//odcitame od souradnice y
                dest.setY( vp.y() - ( (vp.y() - vd.y()) * (percentualy/100)) );
            }
        }
    }
    else {
        //odcitame od souradice x
        dest.setX(vp.x() - ( (vp.x() - vd.x()) * (percentualy/100) ));
        if(dest.x() < vd.x()) {overflow = true;}
        else {
            if (vd.y() > vp.y()) {
                //pricitame k souradnici y
                dest.setY( vp.y() + ( (vd.y() - vp.y()) * (percentualy/100)) );
            }
            else{//odcitame od souradnice y
                dest.setY( vp.y() - ( (vp.y() - vd.y()) * (percentualy/100)) );
            }
        }
    }

    if(overflow) {
        //TODO: move za roh
    }
    else {
        MoveVehicle(vehicle, dest);
        vehicle->DecrementSteps();
    }
}

/**
 * @brief ComputeStep
 * @param vehicle
 * @param streets
 * @param time
 * @return float
 */
float ComputeStep(Vehicle *vehicle, Streets streets, QTime time) {
    float step;
    int no = vehicle->journey_no;
    QPoint position = vehicle->GetPosition();
    Street next_stop = streets.GetStreet(vehicle->TellNextStop());
    QTime dest_time = vehicle->timetable.getNextStopTime(time.addSecs(1));

    float length;
    length = GetLenght(position, vehicle->GetDirection());

    no++;
    Street s = *(vehicle->journey[no]);
    //cyklus se provadi pokud ma projet ulici bez zastaveni
    while (s.getID() != next_stop.getID()) {
        length += GetLenght(s.getEnd(), s.getBegin());
        no++;
    }

    Street last_street = *(vehicle->journey[no - 1]);
    if (last_street.getEnd() == s.getBegin() ||
        last_street.getBegin() == s.getBegin()) {
        length += GetLenght(GetAbsolutePosition(s.getEnd(), s.getBegin(), s.getStopPos()), s.getBegin());
    }
    else { //pokud nesouhlasi -> souhlasi s koncem
        length += GetLenght(position, s.getEnd());
    }

    step = length / (time.secsTo(dest_time) / 60);

    vehicle->SetSteps(length/step);

    return step;
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

    ret.setX(( ( A.x() - B.x() ) * (percent/100) ) + B.x());
    ret.setY(( ( A.y() - B.y() ) * (percent/100) ) + B.y());

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
