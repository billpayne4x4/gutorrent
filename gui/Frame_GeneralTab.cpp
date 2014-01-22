#include <sstream>
#include <string>
#include "Frame_GeneralTab.h"
#include "../tools/tools_formatsize.h"
#include "../tools/tools_formattime.h"

Frame_GeneralTab::Frame_GeneralTab()
{
    this->set_shadow_type(Gtk::SHADOW_IN);
    this->set_margin_top(5);
    this->set_margin_left(5);
    this->set_margin_right(5);
    this->set_margin_bottom(5);

    Gtk::Box *box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    box->set_margin_top(5);
    box->set_margin_left(5);
    box->set_margin_right(5);
    box->set_margin_bottom(5);
    this->add(*box);

    pbprogressbar = Gtk::manage(new Gtk::ProgressBar);
    pbprogressbar->set_size_request(-1, 32);
    pbprogressbar->set_text("Torrent Progress 0%");
    pbprogressbar->set_show_text(true);
    pbprogressbar->set_fraction(0.75);
    box->pack_start(*pbprogressbar, Gtk::PACK_SHRINK, 0);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_margin_top(10);
    grid->set_row_spacing(10);
    grid->set_column_spacing(25);
    grid->set_hexpand(true);
    box->pack_start(*grid, Gtk::PACK_SHRINK, 0);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Size:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 0, 0, 1, 1);

    lsize = Gtk::manage(new Gtk::Label("0 B"));
    lsize->set_hexpand(true);
    lsize->set_halign(Gtk::ALIGN_END);
    grid->attach(*lsize, 1, 0, 1, 1);

    label = Gtk::manage(new Gtk::Label("Downloaded:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 2, 0, 1, 1);

    ldownloaded = Gtk::manage(new Gtk::Label("0 B"));
    ldownloaded->set_hexpand(true);
    ldownloaded->set_halign(Gtk::ALIGN_END);
    grid->attach(*ldownloaded, 3, 0, 1, 1);

    label = Gtk::manage(new Gtk::Label("Uploaded:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 4, 0, 1, 1);

    luploaded = Gtk::manage(new Gtk::Label("0 B"));
    luploaded->set_hexpand(true);
    luploaded->set_halign(Gtk::ALIGN_END);
    grid->attach(*luploaded, 5, 0, 1, 1);

    label = Gtk::manage(new Gtk::Label("Status:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 0, 1, 1, 1);

    lstatus = Gtk::manage(new Gtk::Label("0%"));
    lstatus->set_hexpand(true);
    lstatus->set_halign(Gtk::ALIGN_END);
    grid->attach(*lstatus, 1, 1, 1, 1);

    label = Gtk::manage(new Gtk::Label("Down Speed:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 2, 1, 1, 1);

    ldownspeed = Gtk::manage(new Gtk::Label("0%"));
    ldownspeed->set_hexpand(true);
    ldownspeed->set_halign(Gtk::ALIGN_END);
    grid->attach(*ldownspeed, 3, 1, 1, 1);

    label = Gtk::manage(new Gtk::Label("Up Speed:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 4, 1, 1, 1);

    lupspeed = Gtk::manage(new Gtk::Label("0%"));
    lupspeed->set_hexpand(true);
    lupspeed->set_halign(Gtk::ALIGN_END);
    grid->attach(*lupspeed, 5, 1, 1, 1);

    label = Gtk::manage(new Gtk::Label("Availability:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 0, 2, 1, 1);

    lavailability = Gtk::manage(new Gtk::Label("1.0 [TODO]"));
    lavailability->set_hexpand(true);
    lavailability->set_halign(Gtk::ALIGN_END);
    grid->attach(*lavailability, 1, 2, 1, 1);

    label = Gtk::manage(new Gtk::Label("ETA:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 2, 2, 1, 1);

    leta = Gtk::manage(new Gtk::Label("ꝏ"));
    leta->set_hexpand(true);
    leta->set_halign(Gtk::ALIGN_END);
    grid->attach(*leta, 3, 2, 1, 1);

    label = Gtk::manage(new Gtk::Label("Hash:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 4, 2, 1, 1);

    lhash = Gtk::manage(new Gtk::Label("-"));
    lhash->set_hexpand(true);
    lhash->set_halign(Gtk::ALIGN_END);
    grid->attach(*lhash, 5, 2, 1, 1);

    label = Gtk::manage(new Gtk::Label("Added:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 0, 3, 1, 1);

    ladded = Gtk::manage(new Gtk::Label("-"));
    ladded->set_hexpand(true);
    ladded->set_halign(Gtk::ALIGN_END);
    grid->attach(*ladded, 1, 3, 1, 1);

    label = Gtk::manage(new Gtk::Label("Completed:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 2, 3, 1, 1);

    lcompleted = Gtk::manage(new Gtk::Label("-"));
    lcompleted->set_hexpand(true);
    lcompleted->set_halign(Gtk::ALIGN_END);
    grid->attach(*lcompleted, 3, 3, 1, 1);

    label = Gtk::manage(new Gtk::Label("Name:"));
    label->set_halign(Gtk::ALIGN_START);
    grid->attach(*label, 0, 4, 1, 1);

    lname = Gtk::manage(new Gtk::Label("-"));
    lname->set_hexpand(true);
    lname->set_halign(Gtk::ALIGN_START);
    grid->attach(*lname, 1, 4, 5, 1);
}

Frame_GeneralTab::~Frame_GeneralTab()
{
    //dtor
}

void Frame_GeneralTab::set_progress(int progress)
{
    ostringstream Convert1;
    Convert1 << "Torrent Progress " << progress << "%";
    pbprogressbar->set_text(Convert1.str());
    pbprogressbar->set_fraction(double(progress) / double(100));
    ostringstream Convert2;
    Convert2 << progress << "%";
    lstatus->set_text(Convert2.str());
}

void Frame_GeneralTab::set_size(int bytes)
{
    tools_formatsize fs;
    lsize->set_text(fs.format(bytes));
}

void Frame_GeneralTab::set_downloaded(int bytes)
{
    tools_formatsize fs;
    ldownloaded->set_text(fs.format(bytes));
}

void Frame_GeneralTab::set_uploaded(int bytes)
{
    tools_formatsize fs;
    luploaded->set_text(fs.format(bytes));
}

void Frame_GeneralTab::set_downspeed(int bytes)
{
    tools_formatsize fs;
    ldownspeed->set_text(fs.format(bytes) + "/s");
}

void Frame_GeneralTab::set_upspeed(int bytes)
{
    tools_formatsize fs;
    lupspeed->set_text(fs.format(bytes) + "/s");
}

void Frame_GeneralTab::set_availability(int seconds)
{
    lavailability->set_text("1.0 [TODO]");
}

void Frame_GeneralTab::set_eta(int seconds)
{
    tools_formattime ft;
    leta->set_text(ft.format(seconds));
}

void Frame_GeneralTab::set_hash(string shash)
{
    lhash->set_text(shash);
}

void Frame_GeneralTab::set_added(int seconds)
{
    ladded->set_text("0 secs [TODO]");
}

void Frame_GeneralTab::set_completed(int seconds)
{
    lcompleted->set_text("0 secs [TODO]");
}

void Frame_GeneralTab::set_name(string shash)
{
    lname->set_text(shash);
}
