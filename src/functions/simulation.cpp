#include <QtDebug>

#include "simulation.hpp"

/**
 * @brief Simulate
 * @param seconds
 */
void Simulation::Simulate(int seconds) {
    VehicleEventTable ve_table = event_table;
    QTime final_time = time.addSecs(seconds);

    QList<Event> curr_events;
    QList<Event>::iterator i;

    QList<TimetableEntry> entries;
    TimetableEntry entry;

    QPoint position;
    Vehicle vehicle;
    QList<Vehicle> vehicles;
    QList<Vehicle>::iterator v;


    qDebug() << time.toString() << " " << final_time.toString();

    while(this->time < final_time) {
        curr_events = this->event_table.GetEventsFromTime(time);
        vehicles = this->vehicles.GetAllVehicles();
        //Search for End Events
        for( i = curr_events.begin(); i != curr_events.end(); ++i) {
            if (i->action.GetType() == End) {
                for( v = vehicles.begin(); v != vehicles.end(); ++v) {
                    if(v->GetIdNumber() == i->number) {
                        this->vehicles.vehicles.remove(v->GetIdNumber());
                        this->move_log.remove(v->GetIdNumber());
                    }
                }
            }
        }

        vehicles = this->vehicles.GetAllVehicles();
        for( v = vehicles.begin(); v != vehicles.end(); ++v) {
            if(streets.GetStreet(this->vehicles.GetVehicle(v->GetIdNumber()).TellStop()).getTrafficFlow() != 0) {
                MakeDelay(&(*this->vehicles.vehicles.find(vehicle.GetIdNumber())), streets, time, steptime);
            }

            if(this->vehicles.GetVehicle(v->GetIdNumber()).GetSteps() == 1) {
                    //posledni krok pred zastavkou
                    position = GetAbsolutePosition(
                                streets.GetStreet(this->vehicles.GetVehicle(v->GetIdNumber()).TellNextStop()).getEnd(),
                                streets.GetStreet(this->vehicles.GetVehicle(v->GetIdNumber()).TellNextStop()).getBegin(),
                                streets.GetStreet(this->vehicles.GetVehicle(v->GetIdNumber()).TellNextStop()).getStopPos()
                                );
                    MoveVehicle(&(*this->vehicles.vehicles.find(v->GetIdNumber())), position);
                    //MOVELOG
                    move_log.insert(v->GetIdNumber(),position);
                    this->vehicles.vehicles.find(v->GetIdNumber())->ArriveOnStop(time);
                    qDebug() << "Stop: " << this->vehicles.vehicles.find(v->GetIdNumber())->TellStop();
                    if(this->vehicles.vehicles.find(v->GetIdNumber())->journey_no == this->vehicles.vehicles.find(v->GetIdNumber())->journey.count() - 1) {
                        QTime ti = time.addSecs(60);
                        event_table.InsertEvent(ti,Event(v->GetIdNumber(), End));
                    }
                    else{
                        this->vehicles.vehicles.find(v->GetIdNumber())->SetStep(ComputeStep(&(*this->vehicles.vehicles.find(v->GetIdNumber())), streets, time, steptime));
                    }
                }
                else {
                    Step(&(*this->vehicles.vehicles.find(v->GetIdNumber())));
                    //MOVELOG
                    move_log.insert(v->GetIdNumber(),this->vehicles.vehicles.find(v->GetIdNumber())->GetPosition());
                }
        }

        curr_events = ve_table.GetEventsFromTime(time);

        //Search for spawn Events
        for( i = curr_events.begin(); i != curr_events.end(); ++i) {

            if (i->action.GetType() == Spawn) {

                    position = GetAbsolutePosition(
                                lines.GetLine(i->line).getRoute().first()->getEnd(),
                                lines.GetLine(i->line).getRoute().first()->getBegin(),
                                lines.GetLine(i->line).getRoute().first()->getStopPos());

                    entries = *lines.GetLine(i->line).getTimetable().getEntries();
                    foreach (TimetableEntry e, entries) {
                        if (e.getStartTime() == time) {
                            entry = e;
                            break;
                        }
                    }

                    vehicle = SpawnVehicle(lines.GetLine(i->line), vehicle_count, position, lines.GetLine(i->line).getRoute(), entry);
                    this->vehicles.AddVehicle(vehicle);
                    vehicle_count++;
                    if (this->vehicles.vehicles.find(vehicle.GetIdNumber())->TellStop() == "ghost_street") {
                        this->vehicles.vehicles.find(vehicle.GetIdNumber())->CommenceRide(time);
                        this->vehicles.vehicles.find(vehicle.GetIdNumber())->SetStep(ComputeStep(&(*this->vehicles.vehicles.find(vehicle.GetIdNumber())), streets, time, steptime));
                    }
                    //MOVELOG
                    move_log.insert(vehicle.GetIdNumber(),position);
            }
         }
        //DEBUG
        vehicles = this->vehicles.GetAllVehicles();
        for (v = vehicles.begin(); v != vehicles.end(); ++v){
            qDebug() << "Vehicle: " << v->GetIdNumber() << " Position: X=" << v->GetPosition().x() << " Y=" << v->GetPosition().y();
        }
        /*Toto je odlozeno na neurcito
        curr_events = this->move_event_table.GetEventsFromTime(time);

        for( i = curr_events.begin(); i != curr_events.end(); ++i) {

            switch (i->action.GetType()) {
                case Move:
                    vehicle = this->vehicles.GetVehicle(i->number);
                    if(vehicle.GetSteps() == 1) {
                        //posledni krok pred zastavkou
                        position = GetAbsolutePosition(
                                    streets.GetStreet(vehicle.TellStop()).getEnd(),
                                    streets.GetStreet(vehicle.TellStop()).getBegin(),
                                    streets.GetStreet(vehicle.TellStop()).getStopPos()
                                    );
                        MoveVehicle(this->vehicles.GetVehicle(i->number), position);
                    }
                    else {
                        Step(this->vehicles.GetVehicle(i-));
                    }

                break;

                case End:
                break;

                default:
                break;
            }
          */

         //sleep(sleeptime);
         this->time = this->time.addSecs(steptime);
        }


}

void Simulation::SetTime(int start_hours, int start_minutes)
{
    InitializeTime(&(time), start_hours, start_minutes);
}

Vehicle Simulation::GetVehicleById(int vehicleId)
{
    return vehicles.GetVehicle(vehicleId);
}

int Simulation::GetStepTime(){
    return this->steptime;
}

void Simulation::SetStepTime(int steptime) {
    this->steptime = steptime;
}

/**
 * @brief InitializeSimulation
 * @param parsed_streets
 * @param parsed_lines
 */
void Simulation::InitializeSimulation(StreetList parsed_streets, QHash<QString, Line> parsed_lines) {

    InitializeStreets(&(streets), parsed_streets);
/*DEBUG
    foreach (Street s, streets.GetAllStreets()) {
        qDebug() << s.getID();
    }
*/
    InitializeLines(&(lines), parsed_lines);
/*DEBUG
    QList<Line> list = lines.GetAllLines();
    foreach (Line l, list) {
        qDebug() << l.getID();
    }
*/
    InitializeVehicleEventTable(lines, &(event_table));

    InitializeTime(&(time), 0, 0);

    SetStepTime(60);
}
