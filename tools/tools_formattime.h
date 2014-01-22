#ifndef TOOLS_FORMATTIME_H
#define TOOLS_FORMATTIME_H

#include <iostream>

using namespace std;

class tools_formattime
{
    public:
        tools_formattime();
        virtual ~tools_formattime();

        string format(int seconds);
    protected:
    private:
};

#endif // TOOLS_FORMATTIME_H
