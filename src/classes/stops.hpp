#ifndef STOPS
#define STOPS

#include <map>
#include <string>
#include <list>

#include "stop.hpp"

using namespace std;

class Stops {
    private:
        map<string, Stop> stops;
        int lenght;
    public:
        Stops();
        ~Stops();
        void AddStop(Stop stop);
        int RemoveStop(string name);
        Stop GetStop(string name);
        list<Stop> GetAllStops();
        int GetLenght();

};

#endif
