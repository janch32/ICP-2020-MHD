#include <unistd.h>
#include <QList>
#include <QString>
#include <QHash>
#include <QTime>
#include <QPoint>

#include "../model/street.hpp"
#include "../model/streets.hpp"
#include "../model/lines.hpp"
#include "../model/eventtable.hpp"
#include "../model/vehicle.hpp"

#include "../parser/parsestreets.hpp"
#include "../parser/parselines.hpp"

void InitializeStreets(Streets *streets, StreetList parsed_streets);

void InitializeLines(Lines *lines,  QHash<QString, Line> parsed_lines);

void InitializeVehicleEventTable(Lines lines, VehicleEventTable table);

void InitializeTime(QTime *time, int hours, int minutes);

Vehicle SpawnVehicle(Line line, int number, QPoint position, LineRoute route, TimetableEntry entry);
