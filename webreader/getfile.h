#ifndef GETFILE_H
#define GETFILE_H

#include "webreader.h"
#include <iostream>
#include <vector>

class getfile
{
    public:
        getfile();
        virtual ~getfile();

        void get(vector<webreader::file> &files, string json);
    protected:
    private:
};

#endif // GETFILE_H
