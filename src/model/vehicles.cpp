/**
 * @file vehicles.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 * TODO
 */

#include <map>
#include <list>
#include <string>

#include "vehicle.hpp"
#include "vehicles.hpp"

Vehicles::Vehicles() {}

Vehicles::~Vehicles(){}

void Vehicles::AddVehicle(Vehicle vehicle) {
    vehicles.insert(vehicle.GetIdNumber(), vehicle);
}

int Vehicles::RemoveVehicle(int id) {
    return vehicles.remove(id);
}

Vehicle Vehicles::GetVehicle(int id) {
    return vehicles.value(id);
}

bool Vehicles::HasVehicle(int number)
{
    return vehicles.contains(number);
}

QList<Vehicle> Vehicles::GetAllVehicles() {
    QList<Vehicle> vehicle_list = vehicles.values();

    return vehicle_list;
}

int Vehicles::GetLenght() {
    return vehicles.size();;
}

void Vehicles::Restart() {
    vehicles.clear();
}




