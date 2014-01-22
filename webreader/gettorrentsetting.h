#ifndef GETTORRENTSETTING_H
#define GETTORRENTSETTING_H

#include "webreader.h"
#include <iostream>

class gettorrentsetting
{
    public:
        gettorrentsetting();
        virtual ~gettorrentsetting();

        void get(webreader::torrent_setting &torrent_settings, string json);
    protected:
    private:
};

#endif // GETTORRENTSETTING_H
