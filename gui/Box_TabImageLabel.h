#ifndef BOX_TABIMAGELABEL_H
#define BOX_TABIMAGELABEL_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class Box_TabImageLabel : public Gtk::Box
{
    public:
        Box_TabImageLabel(Gtk::StockID stockid, string Label);
        virtual ~Box_TabImageLabel();
    protected:
    private:
};

#endif // BOX_TABIMAGELABEL_H
