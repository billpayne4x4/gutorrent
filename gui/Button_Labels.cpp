#include "Button_Labels.h"

Button_Labels::Button_Labels(string label, int margin_top, int margin_left, int margin_right, int margin_bottom)
{
    this->set_label(label);
    this->set_hexpand(true);
    this->set_margin_top(margin_top);
    this->set_margin_left(margin_left);
    this->set_margin_right(margin_right);
    this->set_margin_bottom(margin_bottom);
}

Button_Labels::~Button_Labels()
{
    //dtor
}
