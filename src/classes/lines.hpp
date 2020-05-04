#ifndef LINES
#define LINES

#include <map>
#include <string>
#include <list>

#include "line.hpp"

using namespace std;

class Lines {
    private:
        map<int, Line> lines;
        int lenght;
    public:
        Lines();
        ~Lines();
        void AddLine(Line line);
        int RemoveLine(int number);
        Line GetLine(int number);
        list<Line> GetAllLines();
        int GetLenght();

};

#endif
