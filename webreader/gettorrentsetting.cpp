#include <json/reader.h>
#include "gettorrentsetting.h"

gettorrentsetting::gettorrentsetting()
{
    //ctor
}

gettorrentsetting::~gettorrentsetting()
{
    //dtor
}

void gettorrentsetting::get(webreader::torrent_setting &torrent_settings, string json)
{
    Json::Value jsonroot;
    Json::Value jsonarray;
    Json::Reader jsonreader;

    bool parsingSuccessful = jsonreader.parse(json, jsonroot );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        cout  << "Failed JSON reader job propery data parse" << endl << jsonreader.getFormattedErrorMessages() << endl;
        return;
    } else cout << "OK: JSON reader job propery data parse" << endl;

    jsonarray = jsonroot["props"][0];

    torrent_settings.shash = jsonarray["hash"].asString();
    torrent_settings.strackers = jsonarray["trackers"].asString();
    torrent_settings.iupload_rate = jsonarray["ulrate"].asInt();
    torrent_settings.idownload_rate = jsonarray["dlrate"].asInt();
    torrent_settings.isuperseed = jsonarray["superseed"].asInt();
    torrent_settings.idht = jsonarray["dht"].asInt();
    torrent_settings.ipex = jsonarray["pex"].asInt();
    torrent_settings.iseed_override = jsonarray["seed_override"].asInt();
    torrent_settings.iseed_ratio = jsonarray["seed_ratio"].asInt();
    torrent_settings.iseed_time = jsonarray["seed_time"].asInt();
    torrent_settings.iupload_slots = jsonarray["ulslots"].asInt();
    torrent_settings.iseed_num = jsonarray["seed_num"].asInt();
}
