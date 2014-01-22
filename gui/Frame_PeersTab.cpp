#include "Frame_PeersTab.h"
#include "../tools/tools_formatsize.h"
#include "../tools/tools_formattime.h"

Frame_PeersTab::Frame_PeersTab()
{
    this->set_shadow_type(Gtk::SHADOW_IN);
    this->set_margin_top(5);
    this->set_margin_left(5);
    this->set_margin_right(5);
    this->set_margin_bottom(5);

    Gtk::ScrolledWindow *ScrolledWindow = Gtk::manage(new Gtk::ScrolledWindow);
    ScrolledWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    this->add(*ScrolledWindow);

    Gtk::TreeView *tvPeers = Gtk::manage(new Gtk::TreeView);
    tvPeers->set_grid_lines(Gtk::TREE_VIEW_GRID_LINES_BOTH);
    ScrolledWindow->add(*tvPeers);

    refTreeModel = Gtk::ListStore::create(PeersColumns);
    tvPeers->set_model(refTreeModel);

    //tvPeers->append_column("Country", PeersColumns.Country);
    tvPeers->append_column("IP", PeersColumns.IP);
    tvPeers->append_column("Port", PeersColumns.Port);
    tvPeers->append_column("Client", PeersColumns.Client);
    tvPeers->append_column("Flags", PeersColumns.Flags);


    Gtk::CellRendererProgress *cellrenderer_PeerCompleted = Gtk::manage(new Gtk::CellRendererProgress);
    Gtk::TreeView::Column *tvPeers_Completed = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_Completed->set_title("Completed");
    //tvPeers_Completed->set_resizable(true);
    tvPeers_Completed->pack_start(*cellrenderer_PeerCompleted);
    tvPeers_Completed->set_cell_data_func(*cellrenderer_PeerCompleted, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_peercompleted));
    tvPeers->append_column(*tvPeers_Completed);

    Gtk::CellRendererText *cellrenderer_PeersRelevance = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_Relevance = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_Relevance->set_title("Relevance");
    //tvPeers_Relevance->set_resizable(true);
    tvPeers_Relevance->pack_start(*cellrenderer_PeersRelevance);
    tvPeers_Relevance->set_cell_data_func(*cellrenderer_PeersRelevance, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_relevance));
    tvPeers->append_column(*tvPeers_Relevance);

    Gtk::CellRendererText *cellrenderer_PeersDownSpeed = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_DownSpeed = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_DownSpeed->set_title("Down Speed");
    //tvPeers_DownSpeed->set_resizable(true);
    tvPeers_DownSpeed->pack_start(*cellrenderer_PeersDownSpeed);
    tvPeers_DownSpeed->set_cell_data_func(*cellrenderer_PeersDownSpeed, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_downspeed));
    tvPeers->append_column(*tvPeers_DownSpeed);

    Gtk::CellRendererText *cellrenderer_PeersUpSpeed = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_UpSpeed = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_UpSpeed->set_title("Up Speed");
    //tvPeers_UpSpeed->set_resizable(true);
    tvPeers_UpSpeed->pack_start(*cellrenderer_PeersUpSpeed);
    tvPeers_UpSpeed->set_cell_data_func(*cellrenderer_PeersUpSpeed, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_upspeed));
    tvPeers->append_column(*tvPeers_UpSpeed);

    Gtk::CellRendererText *cellrenderer_PeersReqs = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_Reqs = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_Reqs->set_title("Reqs");
    //tvPeers_Reqs->set_resizable(true);
    tvPeers_Reqs->pack_start(*cellrenderer_PeersReqs);
    tvPeers_Reqs->set_cell_data_func(*cellrenderer_PeersReqs, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_reqs));
    tvPeers->append_column(*tvPeers_Reqs);

    Gtk::CellRendererText *cellrenderer_PeersWaited = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_Waited = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_Waited->set_title("Waited");
    //tvPeers_Waited->set_resizable(true);
    tvPeers_Waited->pack_start(*cellrenderer_PeersWaited);
    tvPeers_Waited->set_cell_data_func(*cellrenderer_PeersWaited, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_waited));
    tvPeers->append_column(*tvPeers_Waited);

    Gtk::CellRendererText *cellrenderer_PeersDownloaded = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_Downloaded = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_Downloaded->set_title("Downloaded");
    //tvPeers_Downloaded->set_resizable(true);
    tvPeers_Downloaded->pack_start(*cellrenderer_PeersDownloaded);
    tvPeers_Downloaded->set_cell_data_func(*cellrenderer_PeersDownloaded, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_downloaded));
    tvPeers->append_column(*tvPeers_Downloaded);

    Gtk::CellRendererText *cellrenderer_PeersUploaded = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_Uploaded = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_Uploaded->set_title("Uploaded");
    //tvPeers_Uploaded->set_resizable(true);
    tvPeers_Uploaded->pack_start(*cellrenderer_PeersUploaded);
    tvPeers_Uploaded->set_cell_data_func(*cellrenderer_PeersUploaded, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_uploaded));
    tvPeers->append_column(*tvPeers_Uploaded);

    Gtk::CellRendererText *cellrenderer_PeersHashErr = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_HashErr = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_HashErr->set_title("Hash Errors");
    //tvPeers_HashErr->set_resizable(true);
    tvPeers_HashErr->pack_start(*cellrenderer_PeersHashErr);
    tvPeers_HashErr->set_cell_data_func(*cellrenderer_PeersHashErr, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_hasherr));
    tvPeers->append_column(*tvPeers_HashErr);

    Gtk::CellRendererText *cellrenderer_PeersDownloadSpeed = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_DownloadSpeed = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_DownloadSpeed->set_title("Peer Dl");
    //tvPeers_DownloadSpeed->set_resizable(true);
    tvPeers_DownloadSpeed->pack_start(*cellrenderer_PeersDownloadSpeed);
    tvPeers_DownloadSpeed->set_cell_data_func(*cellrenderer_PeersDownloadSpeed, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_downspeed));
    tvPeers->append_column(*tvPeers_DownloadSpeed);

    Gtk::CellRendererText *cellrenderer_PeersMaxDown = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_MaxDown = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_MaxDown->set_title("Max Down");
    //tvPeers_MaxDown->set_resizable(true);
    tvPeers_MaxDown->pack_start(*cellrenderer_PeersMaxDown);
    tvPeers_MaxDown->set_cell_data_func(*cellrenderer_PeersMaxDown, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_maxdown));
    tvPeers->append_column(*tvPeers_MaxDown);

    Gtk::CellRendererText *cellrenderer_PeersMaxUp = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_MaxUp = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_MaxUp->set_title("Max Up");
    //tvPeers_Completed->set_resizable(true);
    tvPeers_MaxUp->pack_start(*cellrenderer_PeersMaxUp);
    tvPeers_MaxUp->set_cell_data_func(*cellrenderer_PeersMaxUp, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_maxup));
    tvPeers->append_column(*tvPeers_MaxUp);

    Gtk::CellRendererText *cellrenderer_PeersQueued = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_Queued = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_Queued->set_title("Queued");
    //tvPeers_Queued->set_resizable(true);
    tvPeers_Queued->pack_start(*cellrenderer_PeersQueued);
    tvPeers_Queued->set_cell_data_func(*cellrenderer_PeersQueued, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_queued));
    tvPeers->append_column(*tvPeers_Queued);

    Gtk::CellRendererText *cellrenderer_PeersInactive = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvPeers_Inactive = Gtk::manage(new Gtk::TreeView::Column);
    tvPeers_Inactive->set_title("Inactive");
    //tvPeers_Inactive->set_resizable(true);
    tvPeers_Inactive->pack_start(*cellrenderer_PeersInactive);
    tvPeers_Inactive->set_cell_data_func(*cellrenderer_PeersInactive, sigc::mem_fun(*this, &Frame_PeersTab::treeviewcolumn_inactive));
    tvPeers->append_column(*tvPeers_Inactive);



    // TODO: REMOVE TEST DATA BELOW
    Gtk::TreeModel::Row row = *(refTreeModel->append());
    row[PeersColumns.Country] = "";
    row[PeersColumns.IP] = "203.45.252.17";
    row[PeersColumns.Port] = 6899;
    row[PeersColumns.Client] = "µTorrent 3.3.2";
    row[PeersColumns.Flags] = "u XEP";
    row[PeersColumns.Completed] = 75;
    row[PeersColumns.Relevance] = 1.0;
    row[PeersColumns.DownSpeed] = (1024 *122) + 473;
    row[PeersColumns.UpSpeed] = (1024 * 17) + 765;
    row[PeersColumns.Requests] = 7;
    row[PeersColumns.Queued] = 0;
    row[PeersColumns.Waited] = 567236727;
    row[PeersColumns.Downloaded] = (1024 * 1024) *1023 + 5504;
    row[PeersColumns.Uploaded] = (1024 * 1024) * 32 + 7453;
    row[PeersColumns.HashErrors] = 1;
    row[PeersColumns.PeerDownloadSpeed] = (1024 *122) + 473;
    row[PeersColumns.MaxDown] = (1024 *145) + 751;
    row[PeersColumns.MaxUp] = (1024 * 19) + 482;
    row[PeersColumns.Queued] = (1024 * 7) + 395;
    row[PeersColumns.Inactive] = 82579852;
}

Frame_PeersTab::~Frame_PeersTab()
{
    //dtor
}

void Frame_PeersTab::treeviewcolumn_peercompleted(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.Completed];

        Gtk::CellRendererProgress *crp = dynamic_cast<Gtk::CellRendererProgress*>(renderer);
        crp->set_property("value", model_value);
    }
}

void Frame_PeersTab::treeviewcolumn_relevance(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.Relevance];

        ostringstream Convert;
        Convert << model_value << " [TODO]";

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void Frame_PeersTab::treeviewcolumn_downspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.DownSpeed];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value) + "/s";
    }
}

void Frame_PeersTab::treeviewcolumn_upspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.UpSpeed];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value) + "/s";
    }
}

void Frame_PeersTab::treeviewcolumn_reqs(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value_reqs = row[PeersColumns.Requests];
        int model_value_queued = row[PeersColumns.Queued];

        ostringstream Convert;
        Convert << model_value_reqs << " | " << model_value_queued;

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void Frame_PeersTab::treeviewcolumn_waited(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.Waited];

        ostringstream Convert;
        Convert << "0." << model_value << " [TODO]";

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}

void Frame_PeersTab::treeviewcolumn_downloaded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.Downloaded];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value);
    }
}

void Frame_PeersTab::treeviewcolumn_uploaded(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.Uploaded];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value);
    }
}

void Frame_PeersTab::treeviewcolumn_hasherr(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.HashErrors];

        ostringstream Convert;
        Convert << model_value;

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);

        if(model_value == 0)
            crt->property_text() = "";
        else
            crt->property_text() = Convert.str();
    }
}

void Frame_PeersTab::treeviewcolumn_peerdownloadspeed(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.PeerDownloadSpeed];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value) + "/s";
    }
}

void Frame_PeersTab::treeviewcolumn_maxdown(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.MaxDown];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value) + "/s";
    }
}

void Frame_PeersTab::treeviewcolumn_maxup(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.Queued];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value) + "/s";
    }
}

void Frame_PeersTab::treeviewcolumn_queued(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.MaxUp];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value);
    }
}

void Frame_PeersTab::treeviewcolumn_inactive(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[PeersColumns.Inactive];

        ostringstream Convert;
        Convert << model_value << " [TODO]";

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Convert.str();
    }
}
