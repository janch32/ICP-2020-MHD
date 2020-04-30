#ifndef LINE
#define LINE

#include <string>
#include <list>

using namespace std;

class Line {
    private:
        int number;
        list<Stop> stops;

    public:
        Line();
        Line(int n, list<Stop> s);
        ~Line();
        int GetLineNumber();
        list<Stop> GetLineStops();
};

#endif
