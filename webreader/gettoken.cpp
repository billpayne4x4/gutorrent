#include "gettoken.h"

gettoken::gettoken()
{
    //ctor
}

gettoken::~gettoken()
{
    //dtor
}

string gettoken::get(string html)
{
    int i = 0;
    int starttoken = 2;
    string token = "";

    while(true)
    {
        if(starttoken == 0 && html[i] == '<') break;
        if(starttoken == 0) token = token + html[i];
        if(html[i] == '>') starttoken --;
        i++;
    }

    return token;
}
