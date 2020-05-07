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
    VehicleEventTable event_table;
    QTime time;
    int sleeptime;
    Vehicles vehicles;
public:
    void Simulate(int seconds);
    void InitializeSimulation(StreetList parsed_streets, QHash<QString, Line> parsed_lines, int start_hours, int start_minutes);
};

#endif
