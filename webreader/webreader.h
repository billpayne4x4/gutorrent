#ifndef WEBREADER_H
#define WEBREADER_H

#include <curl/curl.h>
#include <iostream>
#include <vector>

#define TORRENT_ACTION_START        0
#define TORRENT_ACTION_STOP         1
#define TORRENT_ACTION_PAUSE        2
#define TORRENT_ACTION_FORCESTART   3
#define TORRENT_ACTION_UNPAUSE      4
#define TORRENT_ACTION_RECHECK      5
#define TORRENT_ACTION_REMOVE       6
#define TORRENT_ACTION_REMOVEDATA   7

using namespace std;

class webreader
{
    public:
        webreader();
        virtual ~webreader();

        bool InitConnection(string _host, string uname, string pword);
        bool GetList();
        bool GetPeers(string shash);
        bool GetFiles(string shash);
        bool GetTorrentSettings(string shash);
        bool TorrentAction(string shash, int TORRENT_ACTION);
        bool SetTorrentfilePriority(string shash, int fileindex, int priority);


        CURL *conn;
        struct curl_slist *cookies; // TODO: May not be needed.

        struct torrent
        {
            string shash;
            int istatus;
            string sname;
            int isize;
            int ipercent_progress;
            int idownloaded;
            int iuploaded;
            int iratio;
            int iupload_speed;
            int idownload_speed;
            int ieta;
            string slabel;
            int ipeers_connected;
            int ipeers_in_swarm;
            int iseeds_connected;
            int iseeds_in_swarm;
            int iavailability;
            int itorrent_queue_order;
            int iremaining;
            string sdownload_url;
            string srssfeed_url;
            string smessage;
            string sstream_id;
            int iadded_on;
            int icompleted_on;
            string sapp_update_url;
            string sdirectory;
            string swebseed_enabled;

            bool bstatus_started;
            bool bstatus_checking;
            bool bstatus_start_after_check;
            bool bstatus_checked;
            bool bstatus_error;
            bool bstatus_paused;
            bool bstatus_queued;
            bool bstatus_loaded;
        };
        vector<torrent> torrents;

        struct file
        {
            string sfilename;
            int ifilesize;
            int idownloaded;
            int ipriority;
            int first_piece;
            int num_pieces;
            bool streamable;
            int encoded_rate;
            int duration;
            int width;
            int height;
            int stream_eta;
            int streamability;
        };
        vector<file> files;

        struct peer
        {
            string scountry;
            string sip;
            string shost;
            int iprotocol;
            int iport;
            string sclient;
            string sflags;
            int iprogress;
            int idownload_rate;
            int iupload_rate;
            int ipending;
            int irequests;
            int iwaited;
            int iuploaded;
            int idownloaded;
            int ihash_errors;
            int ipeer_download_rate;
            int imaxup;
            int imaxdown;
            int iqueued;
            int iinactive;
            int irelevance;
        };
        vector<peer> peers;

        struct torrent_setting
        {
            string shash;
            string strackers;
            int iupload_rate;
            int idownload_rate;
            int isuperseed;
            int idht;
            int ipex;
            int iseed_override;
            int iseed_ratio;
            int iseed_time;
            int iupload_slots;
            int iseed_num;
        };
        torrent_setting torrent_settings;

    protected:
    private:
        char errorBuffer[CURL_ERROR_SIZE];
        string buffer;
        string host;
        string token;
};


#endif // WEBREADER_H
