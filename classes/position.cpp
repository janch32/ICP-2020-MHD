#include "position.hpp"

Position::Position() {
    x=0;
    y=0;
}

Position::Position(int a, int b){
    x = a;
    y = b;
}

Position::~Position()
{
}

int Position::GetXPosition(){
    return x;
}

int Position::GetYPosition(){
    return y;
}

void Position::SetXPosition(int a){
    x = a;
}

void Position::SetYPosition(int b){
    y = b;
}
