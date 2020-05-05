#ifndef CLOCK
#define CLOCK

class Clock {
    private:
        int timestamp;
        float speed;
        int day;
    public:
        Clock();
        ~Clock();
        int GetTimestamp();
        void SetTimestamp(int t);
        void GetTimeFromTimestamp(int *hours, int *minutes);
        int GetTimestampFromTime(int hours, int minutes);
        float GetSpeed();
        void SetSpeed(float s);
        void Tick();
        void Accelerate();
        void Decelerate();
};

#endif
