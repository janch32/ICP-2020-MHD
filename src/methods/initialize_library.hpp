#include <unistd.h>
#include <QList>
#include <QString>
#include <QHash>

#include "../model/street.hpp"
#include "../model/streets.hpp"
#include "../model/lines.hpp"
#include "../model/eventtable.hpp"

#include "../parser/parsestreets.hpp"
#include "../parser/parselines.hpp"

void InitializeStreets(Streets *streets, StreetList parsed_streets);

void InitializeLines(Lines *lines,  QHash<QString, Line> parsed_lines);

void InitializeVehicleEventTable(Lines lines, VehicleEventTable table);

//Vehicle StartVehicle(Vehicles vehicles, Line line, int number, Position position);
