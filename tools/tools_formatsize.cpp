#include "tools_formatsize.h"
#include <sstream>
#include <string>
#include <iomanip>
#include <locale>

tools_formatsize::tools_formatsize()
{
    //ctor
}

tools_formatsize::~tools_formatsize()
{
    //dtor
}

string tools_formatsize::format(int bytes)
{
    ostringstream Convert;

    if(bytes < 1024)
    {
        Convert << bytes;
        return Convert.str() + " B";
    }

    if(bytes < 1048576)
    {
        double kb = double(bytes) / double(1024);
        Convert << fixed << setprecision(2) << kb;
        return Convert.str() + " KB";
    }

    if(bytes < 1073741824)
    {
        double mb = (double(bytes) / double(1024)) / double(1024);
        Convert << fixed << setprecision(2) << mb;
        return Convert.str() + " MB";
    }

    double gb = ((double(bytes) / double(1024)) / double(1024)) / double(1024);
    Convert << fixed << setprecision(2) << gb;
    return Convert.str() + " GB";
}
