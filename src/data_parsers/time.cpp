/**
 * @file time.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#include "time.hpp"

Time::Time(){
    Hours = 0;
    Minutes = 0;
    Seconds = 0;
}

Time::Time(int hours, int mins, int sec){
    Hours = hours;
    Minutes = mins;
    Seconds = sec;
}

void Time::SetHours(int hours){
    Hours = hours;
}

void Time::SetMinutes(int mins){
    Minutes = mins;
}

void Time::SetSeconds(int sec){
    Seconds = sec;
}

int Time::GetHours(){
    return Hours;
}

int Time::GetMinutes(){
    return Minutes;
}

int Time::GetSeconds(){
    return Seconds;
}
