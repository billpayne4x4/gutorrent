#ifndef GETPEER_H
#define GETPEER_H

#include "webreader.h"
#include <iostream>
#include <vector>

class getpeer
{
    public:
        getpeer();
        virtual ~getpeer();

        void get(vector<webreader::peer> &peers, string json);
    protected:
    private:
};

#endif // GETPEER_H
