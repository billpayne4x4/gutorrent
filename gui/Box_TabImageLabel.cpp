#include "Box_TabImageLabel.h"

Box_TabImageLabel::Box_TabImageLabel(Gtk::StockID stockid, string Label)
{
    this->set_orientation(Gtk::ORIENTATION_HORIZONTAL);

    this->pack_start(*Gtk::manage(new Gtk::Image(stockid, Gtk::ICON_SIZE_BUTTON)), Gtk::PACK_SHRINK, 2);
    this->pack_start(*Gtk::manage(new Gtk::Label(Label)), Gtk::PACK_EXPAND_WIDGET, 2);

    this->show_all();
}

Box_TabImageLabel::~Box_TabImageLabel()
{
    //dtor
}
