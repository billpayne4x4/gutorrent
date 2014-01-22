#ifndef GETTOKEN_H
#define GETTOKEN_H

#include <iostream>

using namespace std;

class gettoken
{
    public:
        gettoken();
        virtual ~gettoken();

        string get(string html);

    protected:
    private:
};

#endif // GETTOKEN_H
