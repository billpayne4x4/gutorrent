#include "mainwindow.h"
#include "../dialogs/dialog_addtorrent.h"

mainwindow::mainwindow()
{
    //gui.init_window(*this, *this);
    gui.init_window(*this);
    gui.menuitem_add->signal_button_press_event().connect(sigc::mem_fun(*this, &mainwindow::on_addtorrent));
    gui.tbAdd->signal_button_press_event().connect(sigc::mem_fun(*this, &mainwindow::on_addtorrent));


}

mainwindow::~mainwindow()
{
    //dtor
}

bool mainwindow::on_addtorrent(GdkEventButton* event)
{
    dialog_addtorrent dat;
    dat.set_modal(true);
    dat.run();
    return true;
}
