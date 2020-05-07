#ifndef SIMULATE
#define SIMULATE

#include <QThread>
#include <QList>

#include "../model/streets.hpp"
#include "../model/lines.hpp"
#include "../model/eventtable.hpp"
#include "../model/vehicles.hpp"

#include "../methods/initialize_library.hpp"
#include "../methods/move_library.hpp"

typedef struct SimulationData {
    Streets streets;
    Lines lines;
    VehicleEventTable event_table;
    QTime time;
    int sleeptime;
    Vehicles vehicles;
} SData;

extern SData simulation_data;

void Simulate(int seconds);

void InitializeSimulation(Streets *streets, Lines *lines, StreetList parsed_streets, QHash<QString, Line> parsed_lines, VehicleEventTable table);

#endif
