#include "clock.hpp"

using namespace std;

Clock::Clock() {
    timestamp = 0;
    speed = 1;
    day = 0;
}

Clock::~Clock(){}

int Clock::GetTimestamp() {
    return timestamp;
}

void Clock::SetTimestamp(int t) {
    timestamp = t;
}

void Clock::GetTimeFromTimestamp(int *hours, int *minutes) {
    int time = timestamp / 1440;
    *hours = time / 60;
    *minutes = time % 60;
}

int Clock::GetTimestampFromTime(int hours, int minutes) {
    int m_hours = hours*60;
    return m_hours + minutes + day * 1440;
}

float Clock::GetSpeed() {
    return speed;
}

void Clock::SetSpeed(float s) {
    speed = s;
}

void Clock::Tick() {
    timestamp += 1;
    if (!(timestamp % 1440)) {
        day += 1;
    }
}

void Clock::Accelerate() {
    speed += 0.1;
}

void Clock::Decelerate() {
    speed += 0.2;
}


