#include "simulate.hpp"

/**
 * @brief Simulate
 * @param seconds
 */
void Simulate(int seconds) {
    VehicleEventTable ve_table = simulation_data.event_table;
    Lines lines = simulation_data.lines;
    Streets streets = simulation_data.streets;
    QTime time = simulation_data.time;
    QTime final_time = simulation_data.time.addSecs(seconds);
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

                    simulation_data.vehicles.AddVehicle(SpawnVehicle(lines.GetLine(i->line), vehicle_count, position, lines.GetLine(i->line).getRoute(), entry));
                    vehicle_count++;
                    break;

                case Move:

                    break;

                case End:
                    break;

                default:
                    break;
            }

            vehicles = simulation_data.vehicles.GetAllVehicles();
            for( v = vehicles.begin(); v != vehicles.end(); ++v) {
                if (v->TellStop() == "ghost_street") {
                    v->CommenceRide(time);
                    v->SetStep(ComputeStep(simulation_data.vehicles.GetVehicle(v->GetIdNumber()), simulation_data.streets, time));
                }
                else{
                    if(simulation_data.vehicles.GetVehicle(v->GetIdNumber()).GetSteps() == 1) {
                        //posledni krok pred zastavkou
                        position = GetAbsolutePosition(
                                    streets.GetStreet(simulation_data.vehicles.GetVehicle(v->GetIdNumber()).TellStop()).getEnd(),
                                    streets.GetStreet(simulation_data.vehicles.GetVehicle(v->GetIdNumber()).TellStop()).getBegin(),
                                    streets.GetStreet(simulation_data.vehicles.GetVehicle(v->GetIdNumber()).TellStop()).getStopPos()
                                    );
                        MoveVehicle(simulation_data.vehicles.GetVehicle(v->GetIdNumber()), position);
                    }
                    else {
                        Step(simulation_data.vehicles.GetVehicle(v->GetIdNumber()));
                    }
                }
            }
        }

        sleep(simulation_data.sleeptime);
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
void InitializeSimulation(StreetList parsed_streets, QHash<QString, Line> parsed_lines, int start_hours, int start_minutes) {

    InitializeStreets(&(simulation_data.streets), parsed_streets);

    InitializeLines(&(simulation_data.lines), parsed_lines);

    InitializeVehicleEventTable(simulation_data.lines, simulation_data.event_table);

    InitializeTime(&(simulation_data.time), start_hours, start_minutes);
}
