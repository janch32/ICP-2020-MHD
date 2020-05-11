#ifndef VEHICLES
#define VEHICLES

#include <QMap>
#include <QString>
#include <QList>

#include "vehicle.hpp"

using namespace std;

class Vehicles {
    public:
        QMap<int, Vehicle> vehicles;
        Vehicles();
        ~Vehicles();
        void AddVehicle(Vehicle vehicle);
        int RemoveVehicle(int number);
        Vehicle GetVehicle(int number);
        bool HasVehicle(int number);
        QList<Vehicle> GetAllVehicles();
        int GetLenght();
        void Restart();

};

#endif
