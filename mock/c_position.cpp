#include "c_position.hpp"

Position::Position() {
    p_x=0;
    p_y=0;
}

Position::Position(int x, int y){
    p_x = x;
    p_y = y;
}

Position::~Position()
{
}

int Position::GetXPosition(){
    return p_x;
}

int Position::GetYPosition(){
    return p_y;
}

void Position::SetXPosition(int x){
    p_x = x;
}

void Position::SetYPosition(int y){
    p_y = y;
}