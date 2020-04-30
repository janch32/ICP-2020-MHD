#ifndef STOP
#define STOP

#include <string>
#include <list>

#include "position.hpp"

using namespace std;

class Stop {
    private:
        string name;
        Position position;

    public:
        Stop();
        Stop(string n, Position p);
        ~Stop();
};

#endif
