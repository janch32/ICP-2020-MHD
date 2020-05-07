#include "simulation.hpp"

/**
 * @brief Simulate
 * @param seconds
 */
void Simulation::Simulate(int seconds) {
    VehicleEventTable ve_table = event_table;
    QTime final_time = time.addSecs(seconds);
    int vehicle_count = 0;

    QList<Event> curr_events;
    QList<Event>::iterator i;

    QList<TimetableEntry> entries;
    TimetableEntry entry;

    QPoint position;
    QList<Vehicle> vehicles;
    QList<Vehicle>::iterator v;




    while(time < final_time) {

        curr_events = ve_table.GetEventsFromTime(time);

        for( i = curr_events.begin(); i != curr_events.end(); ++i) {

            switch (i->action.GetType()) {
                case Spawn:
                    position = GetAbsolutePosition(
                                lines.GetLine(i->line).getRoute().first()->getEnd(),
                                lines.GetLine(i->line).getRoute().first()->getBegin(),
                                lines.GetLine(i->line).getRoute().first()->getStopPos());

                    entries = lines.GetLine(i->line).getTimetable().getEntries();
                    foreach (TimetableEntry e, entries) {
                        if (e.getStartTime() == time) {
                            entry = e;
                            break;
                        }
                    }

                    this->vehicles.AddVehicle(SpawnVehicle(lines.GetLine(i->line), vehicle_count, position, lines.GetLine(i->line).getRoute(), entry));
                    vehicle_count++;
                    break;

                case Move:

                    break;

                case End:
                    break;

                default:
                    break;
            }

            vehicles = this->vehicles.GetAllVehicles();
            for( v = vehicles.begin(); v != vehicles.end(); ++v) {
                if (v->TellStop() == "ghost_street") {
                    v->CommenceRide(time);
                    v->SetStep(ComputeStep(this->vehicles.GetVehicle(v->GetIdNumber()), streets, time));
                }
                else{
                    if(this->vehicles.GetVehicle(v->GetIdNumber()).GetSteps() == 1) {
                        //posledni krok pred zastavkou
                        position = GetAbsolutePosition(
                                    streets.GetStreet(this->vehicles.GetVehicle(v->GetIdNumber()).TellStop()).getEnd(),
                                    streets.GetStreet(this->vehicles.GetVehicle(v->GetIdNumber()).TellStop()).getBegin(),
                                    streets.GetStreet(this->vehicles.GetVehicle(v->GetIdNumber()).TellStop()).getStopPos()
                                    );
                        MoveVehicle(this->vehicles.GetVehicle(v->GetIdNumber()), position);
                    }
                    else {
                        Step(this->vehicles.GetVehicle(v->GetIdNumber()));
                    }
                }
            }
        }

        sleep(sleeptime);
        time = time.addSecs(60);
    }



}

/**
 * @brief InitializeSimulation
 * @param parsed_streets
 * @param parsed_lines
 * @param start_hours
 * @param start_minutes
 */
void Simulation::InitializeSimulation(StreetList parsed_streets, QHash<QString, Line> parsed_lines, int start_hours, int start_minutes) {

    InitializeStreets(&(streets), parsed_streets);

    InitializeLines(&(lines), parsed_lines);

    InitializeVehicleEventTable(lines, event_table);

    InitializeTime(&(time), start_hours, start_minutes);
}
