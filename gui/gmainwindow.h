#ifndef GMAINWINDOW_H
#define GMAINWINDOW_H

#include <gtkmm.h>
#include <iostream>
#include "Button_Labels.h"
#include "Frame_GeneralTab.h"
#include "Frame_PeersTab.h"
#include "Frame_FilesTab.h"
#include "Frame_SpeedTab.h"
#include "StatusBar_MainWindow.h"

using namespace std;

class gmainwindow
{
    public:
        gmainwindow();
        virtual ~gmainwindow();

        void init_window(Gtk::Window &window);

        Gtk::Paned *pContentH;
        Gtk::Paned *pContentV;
        Gtk::Entry *eAdd;

        Gtk::MenuItem *menuitem_add;

Gtk::Toolbar *toolbar;

        Gtk::ToolButton *tbAdd;

        Button_Labels *bAll_Torrents;
        Button_Labels *bDownloading_Torrents;
        Button_Labels *bCompleted_Torrents;
        Button_Labels *bActive_Torrents;
        Button_Labels *bInactive_Torrents;

        //Tabs
        Frame_GeneralTab *GeneralTab;
        Frame_PeersTab *PeersTab;
        Frame_FilesTab *FilesTab;
        Frame_SpeedTab *SpeedTab;
        StatusBar_MainWindow *StatusBar;
    protected:
    private:
        Gtk::SeparatorToolItem *tbSep;  // For eAdd resize
        void on_toolbar_resize(Gtk::Allocation &allocation);



};

#endif // GMAINWINDOW_H
