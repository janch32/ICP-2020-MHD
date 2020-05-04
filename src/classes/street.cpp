#include <string>

#include "street.hpp"

using namespace std;

Street::Street(){}

Street::Street(string ID, string n, float speed, Position far_e, Position close_e) {
    id = ID;
    name = n;
    traffic_speed = speed;
    far_corner = far_e;
    close_corner = close_e;
}

Street::~Street(){}

string Street::GetID(){
    return id;
}
