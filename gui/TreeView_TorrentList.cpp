#include "TreeView_TorrentList.h"
#include "../tools/tools_formatsize.h"
#include "../tools/tools_formattime.h"

TreeView_TorrentList::TreeView_TorrentList()
{
    this->set_grid_lines(Gtk::TREE_VIEW_GRID_LINES_BOTH);

    refTreeModel = Gtk::ListStore::create(TorrentColumns);
    this->set_model(refTreeModel);

    this->append_column("Name", TorrentColumns.Name);

    Gtk::CellRendererText *cellrenderer_TorrentSize = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_size = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_size->set_title("Size");
    tvTorrents_size->pack_start(*cellrenderer_TorrentSize);
    tvTorrents_size->set_cell_data_func(*cellrenderer_TorrentSize, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentsize));
    this->append_column(*tvTorrents_size);

    Gtk::CellRendererProgress *cellrenderer_TorrentProgress = Gtk::manage(new Gtk::CellRendererProgress);
    Gtk::TreeView::Column *tvTorrents_Progress = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Progress->set_title("Progress");
    tvTorrents_Progress->pack_start(*cellrenderer_TorrentProgress);
    tvTorrents_Progress->set_cell_data_func(*cellrenderer_TorrentProgress, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_progress));
    this->append_column(*tvTorrents_Progress);

    Gtk::CellRendererText *cellrenderer_TorrentDownSpeed = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_DownSpeed = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_DownSpeed->set_title("Down Speed");
    tvTorrents_DownSpeed->pack_start(*cellrenderer_TorrentDownSpeed);
    tvTorrents_DownSpeed->set_cell_data_func(*cellrenderer_TorrentDownSpeed, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentdownspeed));
    this->append_column(*tvTorrents_DownSpeed);

    Gtk::CellRendererText *cellrenderer_TorrentUpSpeed = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_UpSpeed = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_UpSpeed->set_title("Up Speed");
    tvTorrents_UpSpeed->pack_start(*cellrenderer_TorrentUpSpeed);
    tvTorrents_UpSpeed->set_cell_data_func(*cellrenderer_TorrentUpSpeed, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentupspeed));
    this->append_column(*tvTorrents_UpSpeed);

    Gtk::CellRendererText *cellrenderer_TorrentETA = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_ETA = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_ETA->set_title("ETA");
    tvTorrents_ETA->pack_start(*cellrenderer_TorrentETA);
    tvTorrents_ETA->set_cell_data_func(*cellrenderer_TorrentETA, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrenteta));
    this->append_column(*tvTorrents_ETA);

    Gtk::CellRendererText *cellrenderer_TorrentSeeds = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Seeds = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Seeds->set_title("Seeds");
    tvTorrents_Seeds->pack_start(*cellrenderer_TorrentSeeds);
    tvTorrents_Seeds->set_cell_data_func(*cellrenderer_TorrentSeeds, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentseeds));
    this->append_column(*tvTorrents_Seeds);

    Gtk::CellRendererText *cellrenderer_TorrentPeers = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Peers = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Peers->set_title("Peers");
    tvTorrents_Peers->pack_start(*cellrenderer_TorrentPeers);
    tvTorrents_Peers->set_cell_data_func(*cellrenderer_TorrentPeers, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentpeers));
    this->append_column(*tvTorrents_Peers);

    Gtk::CellRendererText *cellrenderer_TorrentDownloaded = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Downloaded = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Downloaded->set_title("Downloaded");
    tvTorrents_Downloaded->pack_start(*cellrenderer_TorrentDownloaded);
    tvTorrents_Downloaded->set_cell_data_func(*cellrenderer_TorrentDownloaded, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentdownloaded));
    this->append_column(*tvTorrents_Downloaded);

    Gtk::CellRendererText *cellrenderer_TorrentUploaded = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Uploaded = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Uploaded->set_title("Uploaded");
    tvTorrents_Uploaded->pack_start(*cellrenderer_TorrentUploaded);
    tvTorrents_Uploaded->set_cell_data_func(*cellrenderer_TorrentUploaded, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentuploaded));
    this->append_column(*tvTorrents_Uploaded);

    Gtk::CellRendererText *cellrenderer_TorrentRatio = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Ratio = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Ratio->set_title("Ratio");
    tvTorrents_Ratio->pack_start(*cellrenderer_TorrentRatio);
    tvTorrents_Ratio->set_cell_data_func(*cellrenderer_TorrentRatio, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentratio));
    this->append_column(*tvTorrents_Ratio);

    Gtk::CellRendererText *cellrenderer_TorrentAvailabillity = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Availabillity = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Availabillity->set_title("Availabillity");
    tvTorrents_Availabillity->pack_start(*cellrenderer_TorrentAvailabillity);
    tvTorrents_Availabillity->set_cell_data_func(*cellrenderer_TorrentAvailabillity, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentavailability));
    this->append_column(*tvTorrents_Availabillity);

    Gtk::CellRendererText *cellrenderer_TorrentRemaining = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Remaining = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Remaining->set_title("Remaining");
    tvTorrents_Remaining->pack_start(*cellrenderer_TorrentRemaining);
    tvTorrents_Remaining->set_cell_data_func(*cellrenderer_TorrentRemaining, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentremaining));
    this->append_column(*tvTorrents_Remaining);

    Gtk::CellRendererText *cellrenderer_TorrentAdded = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Added = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Added->set_title("Added");
    tvTorrents_Added->pack_start(*cellrenderer_TorrentAdded);
    tvTorrents_Added->set_cell_data_func(*cellrenderer_TorrentAdded, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentadded));
    this->append_column(*tvTorrents_Added);

    Gtk::CellRendererText *cellrenderer_TorrentCompleted = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvTorrents_Completed = Gtk::manage(new Gtk::TreeView::Column);
    tvTorrents_Completed->set_title("Completed");
    tvTorrents_Completed->pack_start(*cellrenderer_TorrentCompleted);
    tvTorrents_Completed->set_cell_data_func(*cellrenderer_TorrentCompleted, sigc::mem_fun(*this, &TreeView_TorrentList::treeviewcolumn_torrentcompleted));
    this->append_column(*tvTorrents_Completed);

    // TODO: REMOVE TEST DATA BELOW
    Gtk::TreeModel::Row row = *(refTreeModel->append());
    row[TorrentColumns.Name] = "Torrent Name";
    row[TorrentColumns.Size] = (1024 * 1024 * 1024) + 17114504;
    row[TorrentColumns.Progress] = 47;
    row[TorrentColumns.DownSpeed] = (1024 * 312) + 450;
    row[TorrentColumns.UpSpeed] = (1024 * 19) + 327;
    row[TorrentColumns.ETA] = (((60 * 60) * 24) * 356) + 93;
    row[TorrentColumns.SeedsConnected] = 56;
    row[TorrentColumns.SeedsSwarm] = 67532;
    row[TorrentColumns.PeersConnected] = 37;
    row[TorrentColumns.PeersSwarm] = 23583;
    row[TorrentColumns.Downloaded] = (1024 * 1024) *1023 + 5504;
    row[TorrentColumns.Uploaded] = (1024 * 1024) * 32 + 7453;

}

TreeView_TorrentList::~TreeView_TorrentList()
{
    //dtor
}

void TreeView_TorrentList::treeviewcolumn_progress(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    Gtk::TreeModel::Row row = *iter;
    int model_value = row[TorrentColumns.Progress];

    Gtk::CellRendererProgress *crp = dynamic_cast<Gtk::CellRendererProgress*>(renderer);
    crp->set_property("value", model_value);
}

void TreeView_TorrentList::treeviewcolumn_torrentsize(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.Size];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value);
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentdownspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.DownSpeed];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value) + "/s";
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentupspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.UpSpeed];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value) + "/s";
    }
}

void TreeView_TorrentList::treeviewcolumn_torrenteta(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formattime ft;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.ETA];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = ft.format(model_value);
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentseeds(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value_seeds_connected = row[TorrentColumns.SeedsConnected];
        int model_value_seeds_swarm = row[TorrentColumns.SeedsSwarm];

        ostringstream Convert;
        Convert << model_value_seeds_connected << " of " << model_value_seeds_swarm;

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentpeers(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value_peers_connected = row[TorrentColumns.PeersConnected];
        int model_value_peers_swarm = row[TorrentColumns.PeersSwarm];

        ostringstream Convert;
        Convert << model_value_peers_connected << " of " << model_value_peers_swarm;

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentdownloaded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.Downloaded];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value);
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentuploaded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.Uploaded];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value);
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentratio(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.Ratio];

        ostringstream Convert;
        Convert << model_value << " [TODO]";

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentavailability(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.Availability];

        ostringstream Convert;
        Convert << model_value << " [TODO]";

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentremaining(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.Remaining];

        ostringstream Convert;
        Convert << model_value << " [TODO]";

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentadded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.Added];

        ostringstream Convert;
        Convert << model_value << " [TODO]";

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void TreeView_TorrentList::treeviewcolumn_torrentcompleted(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[TorrentColumns.Completed];

        ostringstream Convert;
        Convert << model_value << " [TODO]";

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}
