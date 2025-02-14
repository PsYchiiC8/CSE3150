#ifndef EC_TIME
#define EC_TIME

// time class
class ECTime
{
public:
    ECTime(int h, int m, int s);	// (hour, minute, second)
    ~ECTime();
    void GetTime(int &h, int &m, int &s) const;
    ECTime operator+(const ECTime &tmToAdd) const;

private:
    int hour;		// hours
    int min;		// minutes
    int sec;		// seconds
};

#endif