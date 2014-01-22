#ifndef BUTTON_LABELS_H
#define BUTTON_LABELS_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class Button_Labels : public Gtk::Button
{
    public:
        Button_Labels(string label, int margin_top, int margin_left, int margin_right, int margin_bottom);
        virtual ~Button_Labels();
    protected:
    private:
};

#endif // BUTTON_LABELS_H
