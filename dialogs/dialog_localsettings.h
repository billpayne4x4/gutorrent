#ifndef DIALOG_LOCALSETTINGS_H
#define DIALOG_LOCALSETTINGS_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class dialog_localsettings : public Gtk::Dialog
{
    public:
        dialog_localsettings();
        virtual ~dialog_localsettings();

        string get_host();
        string get_username();
        string get_password();
        int get_updateinterval();
        void set_host(string host);
        void set_username(string username);
        void set_password(string password);
        void set_updateinterval(int updateinterval);

        bool save();
        bool load();
    protected:
    private:
        Gtk::Entry *eHost;
        Gtk::Entry *eUserName;
        Gtk::Entry *ePassword;
        Gtk::SpinButton *sUpdateInterval;
};

#endif // DIALOG_LOCALSETTINGS_H
