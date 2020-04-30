#ifndef VEHICLES
#define VEHICLES

#include <map>
#include <string>
#include <list>

#include "vehicle.hpp"

using namespace std;

class Vehicles {
    private:
        map<int, Vehicle> vehicles;
        int lenght;
    public:
        Vehicles();
        ~Vehicles();
        void AddVehicle(Vehicle vehicle);
        int RemoveVehicle(int number);
        Vehicle GetVehicle(int number);
        list<Vehicle> GetAllVehicles();
        int GetLenght();

};

#endif
