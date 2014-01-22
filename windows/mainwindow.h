#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>
#include <iostream>
#include "../gui/gmainwindow.h";

using namespace std;

class mainwindow : public Gtk::Window
{
    public:
        mainwindow();
        virtual ~mainwindow();

    protected:
        bool on_addtorrent(GdkEventButton* event);
    private:
        gmainwindow gui;
};

#endif // MAINWINDOW_H
