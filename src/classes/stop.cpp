#include <string>

#include "position.hpp"
#include "street.hpp"
#include "stop.hpp"

using namespace std;

Stop::Stop(){}

Stop::Stop(string n, Position p){
    name = n;
    position= p;
}

Stop::~Stop(){}

string Stop::GetName(){
    return name;
}

Position Stop::GetPosition(){
    return position;
}

