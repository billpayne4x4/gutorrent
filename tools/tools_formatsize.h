#ifndef TOOLS_FORMATSIZE_H
#define TOOLS_FORMATSIZE_H

#include <iostream>

using namespace std;

class tools_formatsize
{
    public:
        tools_formatsize();
        virtual ~tools_formatsize();

        string format(int bytes);
    protected:
    private:
};

#endif // TOOLS_FORMATSIZE_H
