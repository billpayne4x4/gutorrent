#ifndef FRAME_GENERALTAB_H
#define FRAME_GENERALTAB_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class Frame_GeneralTab : public Gtk::Frame
{
    public:
        Frame_GeneralTab();
        virtual ~Frame_GeneralTab();

        void set_progress(int progress);
        void set_size(int bytes);
        void set_downloaded(int bytes);
        void set_uploaded(int bytes);
        void set_downspeed(int bytes);
        void set_upspeed(int bytes);
        void set_availability(int seconds);
        void set_eta(int seconds);
        void set_hash(string shash);
        void set_added(int seconds);
        void set_completed(int seconds);
        void set_name(string shash);
    protected:
    private:
        Gtk::ProgressBar *pbprogressbar;
        Gtk::Label *lsize;
        Gtk::Label *ldownloaded;
        Gtk::Label *luploaded;
        Gtk::Label *lstatus;
        Gtk::Label *ldownspeed;
        Gtk::Label *lupspeed;
        Gtk::Label *lavailability;
        Gtk::Label *leta;
        Gtk::Label *lhash;
        Gtk::Label *ladded;
        Gtk::Label *lcompleted;
        Gtk::Label *lname;
};

#endif // FRAME_GENERALTAB_H
