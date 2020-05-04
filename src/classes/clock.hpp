#ifndef CLOCK
#define CLOCK

class Clock {
    private:
        int time;
        float speed;
    public:
        Clock();
        ~Clock();
        int GetTime();
        void SetTime(int t);
        float GetSpeed();
        void SetSpeed(float s);
        void Tick();
        void Accelerate();
        void Decelerate();
};

#endif
