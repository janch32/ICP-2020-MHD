#include <QPoint>
#include <QtMath>

#include "../model/vehicle.hpp"

#include "../model/streets.hpp"


void Step(Vehicle *vehicle);

void MoveVehicle(Vehicle *vehicle, QPoint position);

float ComputeStep(Vehicle *vehicle, Streets streets, QTime time);

QPoint GetAbsolutePosition(QPoint A, QPoint B, float percent);

float GetLenght(QPoint A, QPoint B);

