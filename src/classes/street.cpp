#include <string>

#include "street.hpp"
#include <cmath>

using namespace std;

Street::Street(){}

Street::Street(string ID, string n, float speed, Position far_e, Position close_e) {
    id = ID;
    name = n;
    traffic_speed = speed;
    far_corner = far_e;
    close_corner = close_e;
    length = ComputeLength(far_corner, close_corner);
}

Street::~Street(){}

string Street::GetID(){
    return id;
}

float Street::GetLength() {
    return length;
}

float Street::GetRemainingLength(int percentualy) {
    return length * (percentualy / 100);
}


float ComputeLength(Position p1, Position p2) {
    float A = p1.GetXPosition() - p2.GetXPosition();
    float B = p1.GetYPosition() - p2.GetYPosition();

    float Apow = pow(A, 2);
    float Bpow = pow(B, 2);

    return sqrt(Apow + Bpow);
}
