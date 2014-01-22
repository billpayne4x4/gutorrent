#ifndef STATUSBAR_MAINWINDOW_H
#define STATUSBAR_MAINWINDOW_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class StatusBar_MainWindow : public Gtk::Statusbar
{
    public:
        StatusBar_MainWindow();
        virtual ~StatusBar_MainWindow();

        void set_message(string text);
        void set_downloadspeed(int bytes);
        void set_uploadspeed(int bytes);
    protected:
    private:
        Gtk::Label *Text;
        Gtk::Label *DownloadSpeed;
        Gtk::Label *UploadSpeed;
};

#endif // STATUSBAR_MAINWINDOW_H
