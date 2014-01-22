#include "dialog_addtorrent.h"

dialog_addtorrent::dialog_addtorrent()
{
    this->set_size_request(500, -1);
    this->set_title("Add Torrent");
    this->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    this->add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);

    Gtk::Frame *frame = Gtk::manage(new Gtk::Frame);
    frame->set_margin_top(5);
    frame->set_margin_left(5);
    frame->set_margin_right(5);
    frame->set_margin_bottom(5);
    frame->set_hexpand(true);
    frame->set_vexpand(true);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_margin_top(5);
    grid->set_margin_left(5);
    grid->set_margin_right(5);
    grid->set_margin_bottom(5);
    grid->set_hexpand(true);
    grid->set_vexpand(true);
    frame->add(*grid);


    rbFile = Gtk::manage(new Gtk::RadioButton("Torrent File"));
    rbFile->set_hexpand(true);
    Gtk::RadioButton::Group group = rbFile->get_group();
    rbFile->signal_clicked().connect(sigc::mem_fun(*this, &dialog_addtorrent::on_rbFile));

    grid->attach(*rbFile, 0, 0, 1, 1);

    rbMagnet = Gtk::manage(new Gtk::RadioButton("Magnet Link"));
    rbMagnet->set_group(group);
    rbMagnet->set_hexpand(true);
    grid->attach(*rbMagnet, 1, 0, 1, 1);

    rbRSS = Gtk::manage(new Gtk::RadioButton("RSS Feed"));
    rbRSS->set_group(group);
    rbRSS->set_hexpand(true);
    grid->attach(*rbRSS, 2, 0, 1, 1);

    Gtk::Box *box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    box->set_margin_top(25);
    grid->attach(*box, 0, 1, 3, 1);

    entry = Gtk::manage(new Gtk::Entry);
    entry->set_hexpand(true);
    box->pack_start(*entry, Gtk::PACK_EXPAND_WIDGET, 0);

    button = Gtk::manage(new Gtk::Button("..."));
    button->signal_clicked().connect(sigc::mem_fun(*this, &dialog_addtorrent::on_button));
    box->pack_start(*button, Gtk::PACK_SHRINK, 0);



    frame->show_all();

    this->get_content_area()->add(*frame);
}

dialog_addtorrent::~dialog_addtorrent()
{
    //dtor
}

void dialog_addtorrent::on_rbFile()
{
    if(rbFile->get_active() == true)
        button->show();
    else
    {
        button->hide();
        entry->set_text("");
    }
}

void dialog_addtorrent::on_button()
{
    Gtk::FileChooserDialog fcd("Select a Torrent File", Gtk::FILE_CHOOSER_ACTION_OPEN);
    fcd.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    fcd.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

    Glib::RefPtr<Gtk::FileFilter> filter_torrent = Gtk::FileFilter::create();
    filter_torrent->set_name("Torrent Files");
    filter_torrent->add_mime_type("application/x-bittorrent");
    fcd.add_filter(filter_torrent);

    Glib::RefPtr<Gtk::FileFilter> filter_all = Gtk::FileFilter::create();
    filter_all->set_name("All Files");
    filter_all->add_pattern("*");
    fcd.add_filter(filter_all);

    if(fcd.run() == Gtk::RESPONSE_OK)
    {
        entry->set_text(fcd.get_filename());
    }
}

string dialog_addtorrent::get_entry()
{
    return entry->get_text();
}

int dialog_addtorrent::get_radio()
{
    int rval = ADDTORRENT_RADIO_FILE;
    if(rbMagnet->get_active() == true) rval = ADDTORRENT_RADIO_MAGNET;
    if(rbRSS->get_active() == true) rval = ADDTORRENT_RADIO_RSS;
    return rval;
}

