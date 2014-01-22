#include "gmainwindow.h"
#include "../windows/mainwindow.h"
#include "TreeView_TorrentList.h"
#include "Box_TabImageLabel.h"

gmainwindow::gmainwindow()
{
    //ctor
}

gmainwindow::~gmainwindow()
{
    //dtor
}

//void gmainwindow::init_window(mainwindow &mwindow, Gtk::Window &window)
void gmainwindow::init_window(Gtk::Window &window)
{
    window.set_default_size(1280, 1024);
    window.set_title("gutorrent");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window.add(*vbox);

    // Menubar File
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);

    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    menuitem_add = Gtk::manage(new Gtk::MenuItem("_Add", true));
    filemenu->append(*menuitem_add);

    Gtk::MenuItem *menuitem_remove = Gtk::manage(new Gtk::MenuItem("_Remove", true));
    filemenu->append(*menuitem_remove);

    filemenu->append(*Gtk::manage(new Gtk::SeparatorMenuItem()));

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    filemenu->append(*menuitem_quit);

    // Menubar Options
    Gtk::MenuItem *menuitem_options = Gtk::manage(new Gtk::MenuItem("_Options", true));
    menubar->append(*menuitem_options);

    Gtk::Menu *optionsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_options->set_submenu(*optionsmenu);

    Gtk::MenuItem *menuitem_start = Gtk::manage(new Gtk::MenuItem("_Start", true));
    optionsmenu->append(*menuitem_start);

    Gtk::MenuItem *menuitem_forcestart = Gtk::manage(new Gtk::MenuItem("_Force Start", true));
    optionsmenu->append(*menuitem_forcestart);

    Gtk::MenuItem *menuitem_pause = Gtk::manage(new Gtk::MenuItem("_Pause", true));
    optionsmenu->append(*menuitem_pause);

    Gtk::MenuItem *menuitem_unpause = Gtk::manage(new Gtk::MenuItem("_Unpause", true));
    optionsmenu->append(*menuitem_unpause);

    Gtk::MenuItem *menuitem_stop = Gtk::manage(new Gtk::MenuItem("_Stop", true));
    optionsmenu->append(*menuitem_stop);

    Gtk::MenuItem *menuitem_recheck = Gtk::manage(new Gtk::MenuItem("_Recheck", true));
    optionsmenu->append(*menuitem_recheck);

    optionsmenu->append(*Gtk::manage(new Gtk::SeparatorMenuItem()));

    Gtk::MenuItem *menuitem_up = Gtk::manage(new Gtk::MenuItem("_Move Up", true));
    optionsmenu->append(*menuitem_up);

    Gtk::MenuItem *menuitem_down = Gtk::manage(new Gtk::MenuItem("_Move Down", true));
    optionsmenu->append(*menuitem_down);

    optionsmenu->append(*Gtk::manage(new Gtk::SeparatorMenuItem()));

    Gtk::MenuItem *menuitem_settings = Gtk::manage(new Gtk::MenuItem("S_ettings", true));
    optionsmenu->append(*menuitem_settings);

    // Menubar Help
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);

    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    helpmenu->append(*menuitem_about);



    // Toolbar
    toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->signal_size_allocate().connect(sigc::mem_fun(*this, &gmainwindow::on_toolbar_resize));
    toolbar->set_icon_size(Gtk::ICON_SIZE_LARGE_TOOLBAR);
    toolbar->set_toolbar_style(Gtk::TOOLBAR_ICONS);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    //Gtk::ToolButton *tbAdd = Gtk::manage(new Gtk::ToolButton("Add"));
    tbAdd = Gtk::manage(new Gtk::ToolButton("Add"));
    tbAdd->set_stock_id(Gtk::Stock::NEW);
    toolbar->append(*tbAdd);

    Gtk::ToolButton *tbRemove = Gtk::manage(new Gtk::ToolButton("Remove"));
    tbRemove->set_stock_id(Gtk::Stock::REMOVE);
    toolbar->append(*tbRemove);

    //toolbar->append(*Gtk::manage(new Gtk::SeparatorToolItem()));
    tbSep = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*tbSep);

    Gtk::ToolButton *tbStart = Gtk::manage(new Gtk::ToolButton("Start"));
    tbStart->set_stock_id(Gtk::Stock::MEDIA_PLAY);
    toolbar->append(*tbStart);

    Gtk::ToolButton *tbPause = Gtk::manage(new Gtk::ToolButton("Pause"));
    tbPause->set_stock_id(Gtk::Stock::MEDIA_PAUSE);
    toolbar->append(*tbPause);

    Gtk::ToolButton *tbStop = Gtk::manage(new Gtk::ToolButton("Stop"));
    tbStop->set_stock_id(Gtk::Stock::MEDIA_STOP);
    toolbar->append(*tbStop);

    toolbar->append(*Gtk::manage(new Gtk::SeparatorToolItem()));

    Gtk::ToolButton *tbUp = Gtk::manage(new Gtk::ToolButton("Up"));
    tbUp->set_stock_id(Gtk::Stock::GO_UP);
    toolbar->append(*tbUp);

    Gtk::ToolButton *tbDown = Gtk::manage(new Gtk::ToolButton("Down"));
    tbDown->set_stock_id(Gtk::Stock::GO_DOWN);
    toolbar->append(*tbDown);

    toolbar->append(*Gtk::manage(new Gtk::SeparatorToolItem()));

    Gtk::ToolButton *tbSettings = Gtk::manage(new Gtk::ToolButton("Settings"));
    tbSettings->set_stock_id(Gtk::Stock::PREFERENCES);
    toolbar->append(*tbSettings);

    toolbar->append(*Gtk::manage(new Gtk::SeparatorToolItem()));

    eAdd = Gtk::manage(new Gtk::Entry);
    eAdd->set_size_request(1000,-1);
    eAdd->set_hexpand(true); // Dosn't Work. Using on_toolbar_resize
    Gtk::ToolItem *toolitem = Gtk::manage(new Gtk::ToolItem);
    toolitem->set_hexpand(true); // Dosn't Work. Using on_toolbar_resize
    toolitem->add(*eAdd);
    toolbar->append(*toolitem);

    Gtk::ToolButton *tbAddURL = Gtk::manage(new Gtk::ToolButton("Add URL"));
    tbAddURL->set_stock_id(Gtk::Stock::ADD);
    toolbar->append(*tbAddURL);

    pContentH = Gtk::manage(new Gtk::Paned(Gtk::ORIENTATION_HORIZONTAL));
    vbox->pack_start(*pContentH, Gtk::PACK_EXPAND_WIDGET, 0);

    // Frame Left
    Gtk::Frame *fLeft = Gtk::manage(new Gtk::Frame);
    fLeft->set_shadow_type(Gtk::SHADOW_IN);
    fLeft->set_margin_top(5);
    fLeft->set_margin_left(5);
    fLeft->set_margin_right(0);
    fLeft->set_margin_bottom(5);
    fLeft->set_hexpand(true);
    fLeft->set_vexpand(true);
    pContentH->add1(*fLeft);

    Gtk::Box *fleft_vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 5));
    fLeft->add(*fleft_vbox);


    bAll_Torrents = Gtk::manage(new Button_Labels("All (0)", 5, 5, 5, 2));
    fleft_vbox->pack_start(*bAll_Torrents, Gtk::PACK_SHRINK, 0);

    bDownloading_Torrents = Gtk::manage(new Button_Labels("Downloading (0)", 0, 5, 5, 2));
    fleft_vbox->pack_start(*bDownloading_Torrents, Gtk::PACK_SHRINK, 0);

    bCompleted_Torrents = Gtk::manage(new Button_Labels("Completed (0)", 0, 5, 5, 2));
    fleft_vbox->pack_start(*bCompleted_Torrents, Gtk::PACK_SHRINK, 0);

    bActive_Torrents = Gtk::manage(new Button_Labels("Active (0)", 0, 5, 5, 2));
    fleft_vbox->pack_start(*bActive_Torrents, Gtk::PACK_SHRINK, 0);

    bInactive_Torrents = Gtk::manage(new Button_Labels("Inactive (0)", 0, 5, 5, 2));
    fleft_vbox->pack_start(*bInactive_Torrents, Gtk::PACK_SHRINK, 0);

    // Frame Right
    Gtk::Frame *fRight = Gtk::manage(new Gtk::Frame);
    fRight->set_shadow_type(Gtk::SHADOW_IN);
    fRight->set_margin_top(5);
    fRight->set_margin_left(0);
    fRight->set_margin_right(5);
    fRight->set_margin_bottom(5);
    fRight->set_hexpand(true);
    fRight->set_vexpand(true);
    pContentH->add2(*fRight);

    pContentV = Gtk::manage(new Gtk::Paned(Gtk::ORIENTATION_VERTICAL));
    fRight->add(*pContentV);

    Gtk::Box *fright_vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 5));
    pContentV->add1(*fright_vbox);

    Gtk::ScrolledWindow *TreeviewTorrentsScrolledWindow = Gtk::manage(new Gtk::ScrolledWindow);
    TreeviewTorrentsScrolledWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    fright_vbox->pack_start(*TreeviewTorrentsScrolledWindow, Gtk::PACK_EXPAND_WIDGET, 0);

    TreeView_TorrentList *tvTorrents = Gtk::manage(new TreeView_TorrentList);
    TreeviewTorrentsScrolledWindow->add(*tvTorrents);

    // Tabs
    GeneralTab = Gtk::manage(new Frame_GeneralTab);
    PeersTab = Gtk::manage(new Frame_PeersTab);
    FilesTab = Gtk::manage(new Frame_FilesTab);
    SpeedTab = Gtk::manage(new Frame_SpeedTab);

    // Notebook
    Gtk::Notebook *notebook = Gtk::manage(new Gtk::Notebook);
    pContentV->add2(*notebook);

    notebook->append_page(*GeneralTab, *Gtk::manage(new Box_TabImageLabel(Gtk::Stock::ABOUT, "General")));
    notebook->append_page(*PeersTab, *Gtk::manage(new Box_TabImageLabel(Gtk::Stock::ORIENTATION_PORTRAIT, "Peers")));
    notebook->append_page(*FilesTab, *Gtk::manage(new Box_TabImageLabel(Gtk::Stock::OPEN, "Files")));
    notebook->append_page(*SpeedTab, *Gtk::manage(new Box_TabImageLabel(Gtk::Stock::MEDIA_FORWARD, "Speed")));

    // Statusbar
    StatusBar = Gtk::manage(new StatusBar_MainWindow);
    vbox->pack_start(*StatusBar, Gtk::PACK_SHRINK, 0);

    StatusBar->set_downloadspeed((1024 * 312) + 450);
    StatusBar->set_uploadspeed((1024 * 19) + 327);
    StatusBar->set_message("Ready");


    // TODO: REMOVE TEST DATA
    GeneralTab->set_progress(47);
    GeneralTab->set_size((1024 * 1024 * 1024) + 17114504);
    GeneralTab->set_uploaded((1024 * 1024) * 32 + 7453);
    GeneralTab->set_downloaded((1024 * 1024) *1023 + 5504);
    GeneralTab->set_downspeed((1024 * 312) + 450);
    GeneralTab->set_upspeed((1024 * 19) + 327);
    GeneralTab->set_availability(0);
    GeneralTab->set_eta((((60 * 60) * 24) * 356) + 93);
    GeneralTab->set_hash("YUgghjGyuig78GiY*yBgb&*Jjkl");
    GeneralTab->set_added(0);
    GeneralTab->set_completed(0);
    GeneralTab->set_name("Torrent Name");


    vbox->show_all();
}

// set_hexpand did not work... there must be a better way to size eAdd
void gmainwindow::on_toolbar_resize(Gtk::Allocation &allocation)
{
    int x = allocation.get_width();
    x = x - (tbAdd->get_allocated_width() * 9) + (tbSep->get_allocated_width() * 4) - 100;
    eAdd->set_size_request(x, -1);
}

