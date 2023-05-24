#ifndef MESH_H
#define MESH_H

#include "triangle.h"
#include "color.h"

#include <math3d.h>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Mesh
{
    private:
        std::vector<Triangle> triangles;

    public:
        Mesh(std::string filename, Color color);

    public:
        std::vector<Triangle> &get_triangles();
};

#endif