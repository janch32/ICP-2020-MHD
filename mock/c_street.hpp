#ifndef STREET
#define STREET

#include <string>
#include <list>

#include "c_position.hpp"
#include "c_stop.hpp"

using namespace std;

class Street
{
private:
    string str_id;
    string str_name;
    int str_traffic_speed;
    Position str_far_corner;
    Position str_close_corner;
public:
    Street();
    Street(string id, string name, float traffic_speed, Position far_end, Position close_end);
    ~Street();
    string GetID();
};

#endif 
