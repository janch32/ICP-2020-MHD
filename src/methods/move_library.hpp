#include <QPoint>
#include <QtMath>

#include "../model/vehicle.hpp"

#include "../model/streets.hpp"


bool GetDestination(QPoint *dest, QPoint vd, QPoint vp, float percentualy);

void Step(Vehicle *vehicle);

void MoveVehicle(Vehicle *vehicle, QPoint position);

float ComputeStep(Vehicle *vehicle, Streets streets, QTime time, int steptime);

void MakeDelay(Vehicle *vehicle,Streets streets, QTime time, int steptime);

QPoint GetAbsolutePosition(QPoint A, QPoint B, float percent);

float GetLenght(QPoint A, QPoint B);

