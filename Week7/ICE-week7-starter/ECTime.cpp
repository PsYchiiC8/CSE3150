#include "ECTime.h"

ECTime :: ECTime(int h, int m, int s) : hour(h), min(m), sec(s)
{

}
ECTime :: ~ECTime()
{

}

void ECTime :: GetTime(int &h, int &m, int &s) const
{
    h = hour;
    m = min;
    s = sec;
}

ECTime ECTime :: operator+(const ECTime &tmToAdd) const
{
    ECTime res( hour+tmToAdd.hour, min+tmToAdd.min, sec+tmToAdd.sec );
    if ( res.sec >= 60 )
    {
        res.sec -= 60;
        ++res.min;
    }
    if( res.min >= 60)
    {
        res.min -= 60;
        ++res.hour;
    }
    return res;
}