#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"

class Triangle
{   
    private:
        Vertex vertices[3];

    public:
        Triangle(Vertex v0 = Vertex(), Vertex v1 = Vertex(), Vertex v2 = Vertex());

    public:
        Vertex v0();
        Vertex v1();
        Vertex v2();
};

#endif