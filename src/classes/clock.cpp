#include "clock.hpp"

using namespace std;

Clock::Clock() {
    time = 0;
    speed = 1;
}

Clock::~Clock(){}

int Clock::GetTime() {
    return time;
}

void Clock::SetTime(int t) {
    time = t;
}

float Clock::GetSpeed() {
    return speed;
}

void Clock::SetSpeed(float s) {
    speed = s;
}

void Clock::Tick() {
    time += 1;
}

void Clock::Accelerate() {
    speed += 0.1;
}

void Clock::Decelerate() {
    speed += 0.2;
}


