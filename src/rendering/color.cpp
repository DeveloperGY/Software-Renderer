#include "color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
{
    this->c_color = (td_color){red, green, blue};
    return;
}


td_color Color::value()
{
    return this->c_color;
}