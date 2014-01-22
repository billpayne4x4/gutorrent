#include <json/reader.h>
#include "gettorrent.h"

gettorrent::gettorrent()
{
    //ctor
}

gettorrent::~gettorrent()
{
    //dtor
}

void gettorrent::get(vector<webreader::torrent> &torrents, string json)
{
    Json::Value jsonroot;
    Json::Value jsonarray;
    Json::Reader jsonreader;

    bool parsingSuccessful = jsonreader.parse(json, jsonroot );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        cout  << "Failed JSON reader torrent data parse" << endl << jsonreader.getFormattedErrorMessages() << endl;
        return;
    } else cout << "OK: JSON reader torrent data parse" << endl;

    jsonarray = jsonroot["torrents"];
    for(int i = 0; i < jsonarray.size(); i++)
    {
        webreader::torrent torrent;
        Json::Value jsontorrent = jsonarray[i];

        torrent.shash = jsontorrent[0].asString();
        torrent.istatus = jsontorrent[1].asInt();
        torrent.sname = jsontorrent[2].asString();
        torrent.isize = jsontorrent[3].asInt();
        torrent.ipercent_progress = jsontorrent[4].asInt();
        torrent.idownloaded = jsontorrent[5].asInt();
        torrent.iuploaded = jsontorrent[6].asInt();
        torrent.iratio = jsontorrent[7].asInt();
        torrent.iupload_speed = jsontorrent[8].asInt();
        torrent.idownload_speed = jsontorrent[9].asInt();
        torrent.ieta = jsontorrent[10].asInt();
        torrent.slabel = jsontorrent[11].asString();
        torrent.ipeers_connected = jsontorrent[12].asInt();
        torrent.ipeers_in_swarm = jsontorrent[13].asInt();
        torrent.iseeds_connected = jsontorrent[14].asInt();
        torrent.iseeds_in_swarm = jsontorrent[15].asInt();
        torrent.iavailability = jsontorrent[16].asInt();
        torrent.itorrent_queue_order = jsontorrent[17].asInt();
        torrent.iremaining = jsontorrent[18].asInt();
        torrent.sdownload_url = jsontorrent[19].asString();
        torrent.srssfeed_url = jsontorrent[20].asString();
        torrent.smessage = jsontorrent[21].asString();
        torrent.sstream_id = jsontorrent[22].asString();
        torrent.iadded_on = jsontorrent[23].asInt();
        torrent.icompleted_on = jsontorrent[24].asInt();
        torrent.sapp_update_url = jsontorrent[25].asString();
        torrent.sdirectory = jsontorrent[26].asString();
        torrent.swebseed_enabled = jsontorrent[27].asInt();

        torrent.bstatus_started = getbit(torrent.istatus, 0);
        torrent.bstatus_checking = getbit(torrent.istatus, 1);
        torrent.bstatus_start_after_check = getbit(torrent.istatus, 2);
        torrent.bstatus_checked = getbit(torrent.istatus, 3);
        torrent.bstatus_error = getbit(torrent.istatus, 4);
        torrent.bstatus_paused = getbit(torrent.istatus, 5);
        torrent.bstatus_queued = getbit(torrent.istatus, 6);
        torrent.bstatus_loaded = getbit(torrent.istatus, 7);

        torrents.push_back(torrent);
    }
}

bool gettorrent::getbit(int number, int position)
{
    unsigned int bitmask = 1 << position;
    return (number & bitmask) ? true : false;
}
