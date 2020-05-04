/**
 * @file streetparser.cpp
 *
 * @author Jan Chaloupka (xchalo16)
 * @author Michal Krůl (xkrulm00)
 *
 *
 */

#include "streetparser.hpp"

using namespace std;

StreetParser::StreetParser(string filePath){
    OpenFile(filePath);
}

void StreetParser::GetStreets(vector<Street> *streets){
    Street *s;

    while((s = GetStreet()) != nullptr){
        streets->push_back(*s);
    }
}

Street *StreetParser::GetStreet(){
    vector<string> vals;
    int count = ReadLine(&vals);

    if(count == 0) return nullptr;

    if(count != 7){
        throw new invalid_argument("Streets definition contains invalid number of values on line");
    }

    stringstream ssBeginX(vals[1]);
    int beginX = 0;
    ssBeginX >> beginX;

    stringstream ssBeginY(vals[2]);
    int beginY = 0;
    ssBeginY >> beginY;

    stringstream ssEndX(vals[3]);
    int endX = 0;
    ssEndX >> endX;

    stringstream ssEndY(vals[4]);
    int endY = 0;
    ssEndY >> endY;

    stringstream ssStop(vals[5]);
    float stop = 0.5;
    ssStop >> stop;


    // TODO napojit na pozici na zastávce až to bude

    Position begin(beginX, beginY);
    Position end(endX, endY);

    return new Street(vals[0], vals[6], 1.0, begin, end);
}
