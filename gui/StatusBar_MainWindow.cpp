#include "StatusBar_MainWindow.h"
#include "../tools/tools_formatsize.h"

StatusBar_MainWindow::StatusBar_MainWindow()
{
    this->set_size_request(-1, 25);
    this->set_margin_left(5);
    this->set_margin_right(5);

    UploadSpeed = Gtk::manage(new Gtk::Label);
    this->pack_end(*UploadSpeed, Gtk::PACK_SHRINK, 0);

    DownloadSpeed = Gtk::manage(new Gtk::Label);
    this->pack_end(*DownloadSpeed, Gtk::PACK_SHRINK, 25);

    set_downloadspeed(0);
    set_uploadspeed(0);
    set_message("Ready.");
}

StatusBar_MainWindow::~StatusBar_MainWindow()
{
    //dtor
}

void StatusBar_MainWindow::set_message(string text)
{
    this->remove_all_messages(0);
    this->push(text, 0);
}

void StatusBar_MainWindow::set_downloadspeed(int bytes)
{
    tools_formatsize fs;
    DownloadSpeed->set_text("D: " + fs.format(bytes) + "/s");
}

void StatusBar_MainWindow::set_uploadspeed(int bytes)
{
    tools_formatsize fs;
    UploadSpeed->set_text("U: " + fs.format(bytes) + "/s");
}
