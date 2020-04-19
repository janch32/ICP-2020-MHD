/**
 * @file streetparser.hpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#include <string>

#define DEFAULT_STREET_FILE "data/streets.txt"

using namespace std;

class StreetParser{
    void Parse(string file);
};
