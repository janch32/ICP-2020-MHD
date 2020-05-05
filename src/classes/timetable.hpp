#ifndef TIMETABLE
#define TIMETABLE

#include <map>
#include <string>

using namespace std;

class Timetable {
    private:
        //vozidlo, cas
        map<int, int> time_event;
        //cas, zastavka
        map<int, string> timetable;
        void Sort();
    public:
        Timetable();
        ~Timetable();
        void SetEntry(int time, string name);
};

#endif
