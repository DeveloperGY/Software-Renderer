#include "vertex.h"

Vertex::Vertex(m3::vec3 pos, Color color):
    pos(pos),
    _color(color)
{
    return;
}

m3::vec3 Vertex::position()
{
    return this->pos;
}

Color Vertex::color()
{
    return this->_color;
}