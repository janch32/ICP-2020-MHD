#ifndef SIMULATION
#define SIMULATION

#include <QThread>
#include <QList>

#include "../model/streets.hpp"
#include "../model/lines.hpp"
#include "../model/eventtable.hpp"
#include "../model/vehicles.hpp"

#include "../methods/initialize_library.hpp"
#include "../methods/move_library.hpp"

class Simulation{
private:
    Streets streets;
    Lines lines;
    EventTable move_event_table;
    QTime time;
    int sleeptime;
    int steptime;
    Vehicles vehicles;
public:
    QHash<int, QPoint> move_log;
    VehicleEventTable event_table;
    void Simulate(int seconds);
    void InitializeSimulation(StreetList parsed_streets, QHash<QString, Line> parsed_lines);
    void SetTime(int start_hours, int start_minutes);
    Vehicle GetVehicleById(int vehicleId);
    int GetStepTime();
    void SetStepTime(int steptime);
};

#endif
