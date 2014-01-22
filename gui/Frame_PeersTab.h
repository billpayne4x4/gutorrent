#ifndef FRAME_PEERSTAB_H
#define FRAME_PEERSTAB_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class Frame_PeersTab : public Gtk::Frame
{
    public:
        Frame_PeersTab();
        virtual ~Frame_PeersTab();

        Glib::RefPtr<Gtk::ListStore> refTreeModel;
    protected:
    private:
        void treeviewcolumn_peercompleted(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_relevance(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_downspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_upspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_reqs(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_waited(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_downloaded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_uploaded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_hasherr(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_peerdownloadspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_maxdown(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_maxup(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_queued(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_inactive(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);

        class PeersColumnsClass : public Gtk::TreeModel::ColumnRecord
        {
            public:
                PeersColumnsClass()
                {
                    add(Country); add(IP); add(Port); add(Client); add(Flags); add(Completed); add(Relevance); add(DownSpeed);
                    add(UpSpeed); add(Pending); add(Requests); add(Waited); add(Downloaded); add(Uploaded); add(HashErrors);
                    add(PeerDownloadSpeed); add(MaxDown); add(MaxUp); add(Queued); add(Inactive);
                }
                Gtk::TreeModelColumn<string> Country;
                Gtk::TreeModelColumn<string> IP;
                Gtk::TreeModelColumn<int> Port;
                Gtk::TreeModelColumn<string> Client;
                Gtk::TreeModelColumn<string> Flags;
                Gtk::TreeModelColumn<int> Completed;
                Gtk::TreeModelColumn<int> Relevance;
                Gtk::TreeModelColumn<int> DownSpeed;
                Gtk::TreeModelColumn<int> UpSpeed;
                Gtk::TreeModelColumn<int> Pending;
                Gtk::TreeModelColumn<int> Requests;
                Gtk::TreeModelColumn<int> Waited;
                Gtk::TreeModelColumn<int> Downloaded;
                Gtk::TreeModelColumn<int> Uploaded;
                Gtk::TreeModelColumn<int> HashErrors;
                Gtk::TreeModelColumn<int> PeerDownloadSpeed;
                Gtk::TreeModelColumn<int> MaxDown;
                Gtk::TreeModelColumn<int> MaxUp;
                Gtk::TreeModelColumn<int> Queued;
                Gtk::TreeModelColumn<int> Inactive;
        };
        PeersColumnsClass PeersColumns;
};

#endif // FRAME_PEERSTAB_H
