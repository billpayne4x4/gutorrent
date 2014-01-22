#include <sstream>
#include "webreader.h"
#include "gettoken.h"
#include "gettorrent.h"
#include "getfile.h"
#include "gettorrentsetting.h"
#include "getpeer.h"

static std::string html;

webreader::webreader()
{
    //ctor
}

webreader::~webreader()
{
    //curl_slist_free_all(cookies);
    curl_easy_cleanup(conn);
}

static int writer(char *data, size_t size, size_t nmemb, string *writerData)
{
    if (writerData == NULL) return 0;

    writerData->append(data, size*nmemb);

    html = html + data;

    return size * nmemb;
}

bool webreader::InitConnection(string _host, string uname, string pword)
{
    host = _host;

    string url;
    CURLcode code;

    conn = curl_easy_init();
    if (conn == NULL)
    {
        cout << "Failed to create CURL" << endl;
        return false;
    } else cout << "OK: CURL created" << endl;

    code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
    if (code != CURLE_OK)
    {
        fprintf(stderr, "Failed to set error buffer [%d]\n", code);
        return false;
    } else cout << "OK: CURL error buffer option set" << endl;

    code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
    if (code != CURLE_OK)
    {
        cout << "Failed to set redirect option " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL redirection option set" << endl;

    code = curl_easy_setopt(conn, CURLOPT_USERPWD, "admin:");
    if (code != CURLE_OK)
    {
        cout << "Failed to set authentication option " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL authentication option set" << endl;

    code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
    if (code != CURLE_OK)
    {
        cout << "Failed to set writer " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL writer option set" << endl;

    code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);
    if (code != CURLE_OK)
    {
        cout << "Failed to set write data " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL buffer option set" << endl;

    code = curl_easy_setopt(conn, CURLOPT_COOKIEFILE, ""); /* just to start the cookie engine */
    if (code != CURLE_OK)
    {
        cout << "Failed to set the CURL cookie option " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL cookie option set" << endl;

    //url = host + "/gui/web/index.html";
    url = host + "/gui/token.html";
    code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK)
    {
        cout << "Failed to set URL host" << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL URL host option set" << endl;

    code = curl_easy_perform(conn);
    if(code != CURLE_OK)
    {
        cout << "Failed to perform CURL action (read token)" << errorBuffer << endl;
    } else cout << "OK: CURL action (read token)" << endl;

    gettoken gt;
    token = gt.get(html);




 /*
    code = curl_easy_getinfo(conn, CURLINFO_COOKIELIST, &cookies);
    if (code != CURLE_OK)
    {
        cout << "Failed to get CURL cookie info " << errorBuffer << endl;
        return false;
    } else cout << "OK: Got CURL cookie list" << endl;


    url = host + "/gui/?token=" + ;
    code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK)
    {
        cout << "Failed to set URL " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL URL option set" << endl;

    code = curl_easy_perform(conn);
    if(code != CURLE_OK)
    {
        cout << "Failed to perform curl action " << errorBuffer << endl;
    }

    /*
    struct curl_slist *nc;
    int i;

    printf("Cookies, curl knows:\n");
    code = curl_easy_getinfo(conn, CURLINFO_COOKIELIST, &cookies);
    if (code != CURLE_OK)
    {
        cout << "Curl curl_easy_getinfo failed: " << errorBuffer << endl;
    } else cout << "OK: Got CURL cookie info" << endl;

    nc = cookies, i = 1;
    while (nc)
    {
        printf("[%d]: %s\n", i, nc->data);
        nc = nc->next;
        i++;
    }
    if (i == 1) cout << "(none)" << endl;

    cout << "------------------------------------------------------------" << endl << endl << html << endl << "token: " << token << endl << "All OK." << endl;
    */

    return true;
}

bool webreader::GetList()
{
    CURLcode code;
    string url = host + "/gui/?token=" + token + "&list=1";
    code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK)
    {
        cout << "Failed to set URL for torrent list " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL URL for torrent list option set" << endl;

    html = "";
    code = curl_easy_perform(conn);
    if(code != CURLE_OK)
    {
        cout << "Failed to perform CURL action (read list1) " << errorBuffer << endl;
    } else cout << "OK: CURL action (read list1)" << endl;

    gettorrent gt;
    gt.get(torrents, html);

    return true;
}

bool webreader::GetPeers(string shash)
{
    CURLcode code;
    string url = host + "/gui/?token=" + token + "&action=getpeers&hash=" + shash;
    code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK)
    {
        cout << "Failed to set URL for peer list " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL URL for file peer option set" << endl;

    html = "";
    code = curl_easy_perform(conn);
    if(code != CURLE_OK)
    {
        cout << "Failed to perform CURL action (read peers) " << errorBuffer << endl;
    } else cout << "OK: CURL action (read peers)" << endl;

    getpeer gp;
    gp.get(peers, html);

    return true;
}

bool webreader::GetFiles(string shash)
{
    CURLcode code;
    string url = host + "/gui/?token=" + token + "&action=getfiles&hash=" + shash;
    code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK)
    {
        cout << "Failed to set URL for file list " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL URL for file list option set" << endl;

    html = "";
    code = curl_easy_perform(conn);
    if(code != CURLE_OK)
    {
        cout << "Failed to perform CURL action (read files) " << errorBuffer << endl;
    } else cout << "OK: CURL action (read files)" << endl;

    getfile gf;
    gf.get(files, html);

    return true;
}

bool webreader::GetTorrentSettings(string shash)
{
    CURLcode code;
    string url = host + "/gui/?token=" + token + "&action=getprops&hash=" + shash;
    code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK)
    {
        cout << "Failed to set URL for job properties " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL URL for job properties option set" << endl;

    html = "";
    code = curl_easy_perform(conn);
    if(code != CURLE_OK)
    {
        cout << "Failed to perform CURL action (read job properties) " << errorBuffer << endl;
    } else cout << "OK: CURL action (read job properties)" << endl;

    gettorrentsetting jp;
    jp.get(torrent_settings, html);
    return true;
}

bool webreader::TorrentAction(string shash, int TORRENT_ACTION)
{
    CURLcode code;
    string url = host + "/gui/?token=" + token + "&hash=" + shash;

    switch(TORRENT_ACTION)
    {
        case TORRENT_ACTION_START:
            url = url + "&action=start";
            break;
        case TORRENT_ACTION_STOP:
            url = url + "&action=stop";
            break;
        case TORRENT_ACTION_PAUSE:
            url = url + "&action=pause";
            break;
        case TORRENT_ACTION_FORCESTART:
            url = url + "&action=forcestart";
            break;
        case TORRENT_ACTION_UNPAUSE:
            url = url + "&action=unpause";
            break;
        case TORRENT_ACTION_RECHECK:
            url = url + "&action=recheck";
            break;
        case TORRENT_ACTION_REMOVE:
            url = url + "&action=remove";
            break;
        case TORRENT_ACTION_REMOVEDATA:
            url = url + "&action=removedata";
            break;
    }

    code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK)
    {
        cout << "Failed to set URL for torrent action " << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL URL for torrent action option set" << endl;

    html = "";
    code = curl_easy_perform(conn);
    if(code != CURLE_OK)
    {
        cout << "Failed to perform CURL action (torrent action) " << errorBuffer << endl;
    } else cout << "OK: CURL action (torrent action)" << endl;

    return true;
}

bool webreader::SetTorrentfilePriority(string shash, int fileindex, int priority)
{
    ostringstream ss;
    ss << fileindex;
    string sfileindex = ss.str();

    ss.clear();
    ss << priority;
    string spriority = ss.str();

    CURLcode code;
    string url = host + "/gui/?token=" + token + "&action=setprio&hash=" + shash + "&f=" + sfileindex + "&p=" + spriority;
    code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
    if (code != CURLE_OK)
    {
        cout << "Failed to set URL for torrent file priority" << errorBuffer << endl;
        return false;
    } else cout << "OK: CURL URL for torrent file priority option set" << endl;

    html = "";
    code = curl_easy_perform(conn);
    if(code != CURLE_OK)
    {
        cout << "Failed to perform CURL action (torrent file priority) " << errorBuffer << endl;
    } else cout << "OK: CURL action (torrent file priority)" << endl;

    return true;
}
