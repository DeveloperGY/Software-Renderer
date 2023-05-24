#ifndef VERTEX_H
#define VERTEX_H

#include "color.h"

#include <math3d.h>

class Vertex
{
    private:
        m3::vec3 pos;
        Color _color;

    public:
        Vertex(m3::vec3 pos = m3::vec3(), Color color = Color(255, 255, 255));
    
    public:
        m3::vec3 position();
        Color color();
};

#endif