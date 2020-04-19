#ifndef POSITION
#define POSITION


class Position
{
private:
    int p_x;
    int p_y;
public:
    Position();
    Position(int x, int y);
    ~Position();
    int GetXPosition();
    int GetYPosition();
    void SetXPosition(int x);
    void SetYPosition(int y);
};

#endif


