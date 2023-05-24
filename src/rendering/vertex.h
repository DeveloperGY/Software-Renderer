#ifndef VERTEX_H
#define VERTEX_H

#include "color.h"

#include <math3d.h>

class Vertex
{
    private:
        m3::vec3 position;
        Color color;

    public:
        Vertex(m3::vec3 pos = m3::vec3(), Color color = Color(255, 255, 255));
};

#endif