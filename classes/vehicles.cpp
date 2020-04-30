#include <map>
#include <list>
#include <string>

#include "vehicle.hpp"
#include "vehicles.hpp"

Vehicles::Vehicles() {
    lenght = 0;
}

Vehicles::~Vehicles(){}

void Vehicles::AddVehicle(Vehicle vehicle) {
    vehicles[vehicle.GetIdNumber()] = vehicle;
    lenght++;
}

int Vehicles::RemoveVehicle(int id) {
    return vehicles.erase(id);
}

Vehicle Vehicles::GetVehicle(int id) {
    return vehicles[id];
}

list<Vehicle> Vehicles::GetAllVehicles() {
    list<Vehicle> vehicle_list;
    for(auto& v : vehicles) {
        vehicle_list.push_back(v.second);
    }
    return vehicle_list;
}

int Vehicles::GetLenght() {
    return lenght;
}




