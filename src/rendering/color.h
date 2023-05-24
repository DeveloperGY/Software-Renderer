#ifndef COLOR_H
#define COLOR_H

#include <td.h>

class Color
{
    private:
        td_color c_color;

    public:
        Color(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0);

    public:
        td_color value();
};

#endif