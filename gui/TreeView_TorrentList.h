#ifndef TREEVIEW_TORRENTLIST_H
#define TREEVIEW_TORRENTLIST_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class TreeView_TorrentList : public Gtk::TreeView
{
    public:
        TreeView_TorrentList();
        virtual ~TreeView_TorrentList();

        Glib::RefPtr<Gtk::ListStore> refTreeModel;
    protected:
    private:
        void treeviewcolumn_progress(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentsize(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentdownspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentupspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrenteta(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentseeds(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentpeers(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentdownloaded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentuploaded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentratio(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentavailability(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentremaining(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentadded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_torrentcompleted(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);

        class TorrentColumnsClass : public Gtk::TreeModel::ColumnRecord
        {
            public:
                TorrentColumnsClass()
                {
                    add(Hash); add(Name); add(Size); add(Progress); add(DownSpeed); add(UpSpeed); add(ETA);
                    add(SeedsConnected); add(SeedsSwarm); add(PeersConnected); add(PeersSwarm); add(Downloaded);
                    add(Uploaded); add(Ratio); add(Availability); add(Remaining); add(Added); add(Completed);
                }
                Gtk::TreeModelColumn<string> Hash;
                Gtk::TreeModelColumn<string> Name;
                Gtk::TreeModelColumn<int> Size;
                Gtk::TreeModelColumn<int> Progress;
                Gtk::TreeModelColumn<int> DownSpeed;
                Gtk::TreeModelColumn<int> UpSpeed;
                Gtk::TreeModelColumn<int> ETA;
                Gtk::TreeModelColumn<int> SeedsConnected;
                Gtk::TreeModelColumn<int> SeedsSwarm;
                Gtk::TreeModelColumn<int> PeersConnected;
                Gtk::TreeModelColumn<int> PeersSwarm;
                Gtk::TreeModelColumn<int> Downloaded;
                Gtk::TreeModelColumn<int> Uploaded;
                Gtk::TreeModelColumn<int> Ratio;
                Gtk::TreeModelColumn<int> Availability;
                Gtk::TreeModelColumn<int> Remaining;
                Gtk::TreeModelColumn<int> Added;
                Gtk::TreeModelColumn<int> Completed;
        };
        TorrentColumnsClass TorrentColumns;
};

#endif // TREEVIEW_TORRENTLIST_H
