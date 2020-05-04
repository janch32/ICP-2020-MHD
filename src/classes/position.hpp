#ifndef POSITION
#define POSITION

class Position {
    private:
        int x;
        int y;
    public:
        Position();
        Position(int x, int y);
        ~Position();
        int GetXPosition();
        int GetYPosition();
        void SetXPosition(int n);
        void SetYPosition(int n);
};

#endif


