#ifndef GETTORRENT_H
#define GETTORRENT_H

#include "webreader.h"
#include <iostream>
#include <vector>

using namespace std;

class gettorrent
{
    public:
        gettorrent();
        virtual ~gettorrent();

        void get(vector<webreader::torrent> &torrents, string json);
    protected:
    private:
        bool getbit(int number, int position);

};

#endif // GETTORRENT_H
