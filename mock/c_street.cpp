#include <string>

#include "c_street.hpp"

using namespace std;

Street::Street(){}

Street::Street(string id, string name, float traffic_speed, Position far_end, Position close_end)
{
}

Street::~Street()
{
}

string Street::GetID(){
    return str_id;
}