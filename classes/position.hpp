#ifndef POSITION
#define POSITION

class Position {
    private:
        int x;
        int y;
    public:
        Position();
        Position(int a, int b);
        ~Position();
        int GetXPosition();
        int GetYPosition();
        void SetXPosition(int a);
        void SetYPosition(int b);
};

#endif


