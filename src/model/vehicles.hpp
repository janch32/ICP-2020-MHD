#ifndef VEHICLES
#define VEHICLES

#include <QMap>
#include <QString>
#include <QList>

#include "vehicle.hpp"

using namespace std;

class Vehicles {
    private:
        QMap<int, Vehicle> vehicles;

    public:
        Vehicles();
        ~Vehicles();
        void AddVehicle(Vehicle vehicle);
        int RemoveVehicle(int number);
        Vehicle GetVehicle(int number);
        QList<Vehicle> GetAllVehicles();
        int GetLenght();

};

#endif
