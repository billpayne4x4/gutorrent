// Depends : sudo apt-get install libgtkmm-3.0-dev libcurl4-gnutls-dev libjsoncpp-dev
#include <gtkmm.h>
#include "webreader/webreader.h"
#include "windows/mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.gutorrent.base");
    mainwindow window;

    return app->run(window);


    // TODO: REMOVE WEB READER TESTS:
    // ------------------------------
    //webreader wr;
    //wr.InitConnection("http://192.168.69.69:8080", "admin", "");
    //wr.GetList();
    //wr.GetPeers("739FD9498279AC19426C73CFA6B54A537E9E6D3F");
    //wr.GetFiles("029A429C78DB2EBB91B930980184DD0B5A8671A2");
    //wr.GetJobProperties("029A429C78DB2EBB91B930980184DD0B5A8671A2");
    //wr.TorrentAction("029A429C78DB2EBB91B930980184DD0B5A8671A2", TORRENT_ACTION_STOP);
    //wr.SetTorrentfilePriority("029A429C78DB2EBB91B930980184DD0B5A8671A2", 0, 2);
}
