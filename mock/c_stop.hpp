#ifndef STOP
#define STOP

#include <string>
#include <list>

#include "c_position.hpp"
#include "c_street.hpp"

using namespace std;

class Stop
{
private:
    string st_name;
    Position st_position;

public:
    Stop(string name);
    ~Stop();
};

#endif