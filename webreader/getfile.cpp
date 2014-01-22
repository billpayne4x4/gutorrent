#include <json/reader.h>
#include "getfile.h"

getfile::getfile()
{
    //ctor
}

getfile::~getfile()
{
    //dtor
}

void getfile::get(vector<webreader::file> &files, string json)
{
    Json::Value jsonroot;
    Json::Value jsonarray;
    Json::Value jsonfile;
    Json::Reader jsonreader;

    bool parsingSuccessful = jsonreader.parse(json, jsonroot );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        cout  << "Failed JSON reader file data parse" << endl << jsonreader.getFormattedErrorMessages() << endl;
        return;
    } else cout << "OK: JSON reader file data parse" << endl;

    jsonarray = jsonroot["files"];
    for(int i = 0; i < jsonarray[1].size(); i++)
    {
        webreader::file file;
        jsonfile = jsonarray[1][i];

        file.sfilename = jsonfile[0].asString();
        file.ifilesize = jsonfile[1].asInt();
        file.idownloaded = jsonfile[2].asInt();
        file.ipriority = jsonfile[3].asInt();
        file.first_piece = jsonfile[4].asInt();
        file.num_pieces= jsonfile[5].asInt();
        file.streamable = jsonfile[6].asBool();
        file.encoded_rate = jsonfile[7].asInt();
        file.duration = jsonfile[8].asInt();
        file.width = jsonfile[9].asInt();
        file.height = jsonfile[10].asInt();
        file.stream_eta = jsonfile[11].asInt();
        file.streamability = jsonfile[12].asInt();
    }
}
