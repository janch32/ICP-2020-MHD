/**
 * @file time.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#ifndef TIME
#define TIME

class Time{
private:
    int Hours;
    int Minutes;
    int Seconds;
public:
    Time();
    Time(int hours, int mins, int sec);
    void SetHours(int hours);
    void SetMinutes(int mins);
    void SetSeconds(int sec);
    int GetHours();
    int GetMinutes();
    int GetSeconds();
};

#endif
