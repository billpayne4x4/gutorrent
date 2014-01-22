#include <json/reader.h>
#include "getpeer.h"

getpeer::getpeer()
{
    //ctor
}

getpeer::~getpeer()
{
    //dtor
}

void getpeer::get(vector<webreader::peer> &peers, string json)
{
    Json::Value jsonroot;
    Json::Value jsonarray;
    Json::Value jsonpeer;
    Json::Reader jsonreader;

    bool parsingSuccessful = jsonreader.parse(json, jsonroot );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        cout  << "Failed JSON reader torrent data parse" << endl << jsonreader.getFormattedErrorMessages() << endl;
        return;
    } else cout << "OK: JSON reader torrent data parse" << endl;

    jsonarray = jsonroot["peers"];
    //for(int i = 0; i < jsonarray[1].size(); i++)
    for(int i = 0; i < 35; i++)
    {
        webreader::peer peer;
        jsonpeer = jsonarray[1][i];

        peer.scountry = jsonpeer[0].asString();
        peer.sip = jsonpeer[1].asString();
        peer.shost = jsonpeer[2].asString();
        peer.iprotocol = jsonpeer[3].asInt();
        peer.iport = jsonpeer[4].asInt();
        peer.sclient = jsonpeer[5].asString();
        peer.sflags = jsonpeer[6].asString();
        peer.iprogress = jsonpeer[7].asInt();
        peer.idownload_rate = jsonpeer[8].asInt();
        peer.iupload_rate = jsonpeer[9].asInt();
        peer.ipending = jsonpeer[10].asInt();
        peer.irequests = jsonpeer[11].asInt();
        peer.iwaited = jsonpeer[12].asInt();
        peer.iuploaded = jsonpeer[13].asInt();
        peer.idownloaded = jsonpeer[14].asInt();
        peer.ihash_errors = jsonpeer[15].asInt();
        peer.ipeer_download_rate = jsonpeer[16].asInt();
        peer.imaxup = jsonpeer[17].asInt();
        peer.imaxdown = jsonpeer[18].asInt();
        peer.iqueued = jsonpeer[19].asInt();
        peer.iinactive = jsonpeer[20].asInt();
        peer.irelevance = jsonpeer[21].asInt();

        peers.push_back(peer);
    }
}
