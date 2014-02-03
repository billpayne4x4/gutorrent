#include <iostream>
#include <fstream>
#include "dialog_localsettings.h"

dialog_localsettings::dialog_localsettings()
{
    this->set_size_request(350, -1);
    this->set_title("Local Settings");

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
    grid->set_margin_top(15);
    grid->set_margin_left(15);
    grid->set_margin_right(15);
    grid->set_margin_bottom(15);
    grid->set_hexpand(true);
    grid->set_vexpand(true);
    grid->set_row_spacing(15);
    frame->add(*grid);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Host: "));
    label->set_halign(Gtk::ALIGN_END);
    grid->attach(*label, 0, 0, 1, 1);

    eHost = Gtk::manage(new Gtk::Entry);
    eHost->set_hexpand(true);
    grid->attach(*eHost, 1, 0, 1, 1);

    label = Gtk::manage(new Gtk::Label("Username: "));
    label->set_halign(Gtk::ALIGN_END);
    grid->attach(*label, 0, 1, 1, 1);

    eUserName = Gtk::manage(new Gtk::Entry);
    eUserName->set_hexpand(true);
    grid->attach(*eUserName, 1, 1, 1, 1);

    label = Gtk::manage(new Gtk::Label("Password: "));
    label->set_halign(Gtk::ALIGN_END);
    grid->attach(*label, 0, 2, 1, 1);

    ePassword = Gtk::manage(new Gtk::Entry);
    ePassword->set_hexpand(true);
    grid->attach(*ePassword, 1, 2, 1, 1);

    label = Gtk::manage(new Gtk::Label("Update Interval: "));
    label->set_halign(Gtk::ALIGN_END);
    grid->attach(*label, 0, 3, 1, 1);

    Gtk::Box *box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    grid->attach(*box, 1, 3, 1, 1);

    sUpdateInterval = Gtk::manage(new Gtk::SpinButton(Gtk::Adjustment::create(5.0, 1.0, 60.0, 1.0, 10.0, 0.0), 0.0, 0));
    sUpdateInterval->set_hexpand(false);
    box->pack_start(*sUpdateInterval, Gtk::PACK_EXPAND_WIDGET, 2);

    label = Gtk::manage(new Gtk::Label("(seconds)"));
    label->set_halign(Gtk::ALIGN_END);
    box->pack_start(*label, Gtk::PACK_EXPAND_WIDGET, 2);

    frame->show_all();

    this->get_content_area()->add(*frame);
}

dialog_localsettings::~dialog_localsettings()
{
    //dtor
}

string dialog_localsettings::get_host(){}
string dialog_localsettings::get_username(){}
string dialog_localsettings::get_password(){}
int dialog_localsettings::get_updateinterval(){}
void dialog_localsettings::set_host(string host){}
void dialog_localsettings::set_username(string username){}
void dialog_localsettings::set_password(string password){}
void dialog_localsettings::set_updateinterval(int updateinterval){}

bool dialog_localsettings::save()
{
    string settingsfile = Glib::get_home_dir() + "/.gutorrent";

    Glib::KeyFile kf;
    kf.set_string("gutorrent", "host", eHost->get_text());
    kf.set_string("gutorrent", "username", eUserName->get_text());
    kf.set_string("gutorrent", "password", ePassword->get_text());
    kf.set_integer("gutorrent", "update_interval", sUpdateInterval->get_value_as_int());


    ofstream file;
    file.open(settingsfile.c_str(), ios::out | ios::trunc);
    file << kf.to_data();
    file.close();

    return true;
}

bool dialog_localsettings::load()
{
    string settingsfile = Glib::get_home_dir() + "/.gutorrent";

    Glib::KeyFile kf;

    if(kf.load_from_file(settingsfile, Glib::KEY_FILE_KEEP_COMMENTS | Glib::KEY_FILE_KEEP_TRANSLATIONS) == false) return false;
    eHost->set_text(kf.get_string("gutorrent", "host"));
    eUserName->set_text(kf.get_string("gutorrent", "username"));
    ePassword->set_text(kf.get_string("gutorrent", "password"));
    sUpdateInterval->set_value(kf.get_integer("gutorrent", "update_interval"));
}
