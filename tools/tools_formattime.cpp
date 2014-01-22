#include <time.h>
#include <sstream>
#include <string>
#include "tools_formattime.h"

tools_formattime::tools_formattime()
{
    //ctor
}

tools_formattime::~tools_formattime()
{
    //dtor
}

string tools_formattime::format(int seconds)
{
    if(seconds > 30758400)
    {
        return "ꝏ";
    }

    string stime = "";

    time_t secs(seconds);
    tm *time = localtime(&secs);

    if(time->tm_yday > 0)
    {
        ostringstream Convert;
        Convert << time->tm_yday;
        stime = stime + Convert.str() + "d ";
    }

    if(time->tm_hour > 0)
    {
        ostringstream Convert;
        Convert << time->tm_hour;
        stime = stime + Convert.str() + "h ";
    }

    if(time->tm_min > 0)
    {
        ostringstream Convert;
        Convert << time->tm_min;
        stime = stime + Convert.str() + "m ";
    }

    ostringstream Convert;
    Convert << time->tm_sec;
    stime = stime + Convert.str() + "s";

    return stime;
}
