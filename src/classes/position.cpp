#include "position.hpp"

Position::Position() {
    x = 0;
    y = 0;
}

Position::Position(int x, int y){
    this->x = x;
    this->y = y;
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

void Position::SetXPosition(int n){
    x = n;
}

void Position::SetYPosition(int n){
    y = n;
}
