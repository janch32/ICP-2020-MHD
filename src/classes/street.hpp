#ifndef STREET
#define STREET

#include <string>
#include <list>

#include "position.hpp"
#include "stop.hpp"

using namespace std;

class Street {
    private:
        string id;
        string name;
        int traffic_speed;
        Position far_corner;
        Position close_corner;
        float length;
    public:
        Street();
        Street(string ID, string n, float speed, Position far_e, Position close_e);
        ~Street();
        string GetID();
        float GetLength();
        float GetRemainingLength(int percentualy);
};

#endif
