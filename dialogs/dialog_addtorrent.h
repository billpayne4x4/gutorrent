#ifndef DIALOG_ADDTORRENT_H
#define DIALOG_ADDTORRENT_H

#include <gtkmm.h>
#include <iostream>

#define ADDTORRENT_RADIO_FILE       0
#define ADDTORRENT_RADIO_MAGNET     1
#define ADDTORRENT_RADIO_RSS        2

using namespace std;

class dialog_addtorrent : public Gtk::Dialog
{
    public:
        dialog_addtorrent();
        virtual ~dialog_addtorrent();

        string get_entry();
        int get_radio();
    protected:
    private:
        Gtk::RadioButton *rbFile;
        Gtk::RadioButton *rbMagnet;
        Gtk::RadioButton *rbRSS;
        Gtk::Entry *entry;
        Gtk::Button *button;

        void on_rbFile();
        void on_button();
};

#endif // DIALOG_ADDTORRENT_H
