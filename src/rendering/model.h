#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"
#include "color.h"

#include <math3d.h>

#include <string>

class Model
{
    private:
        m3::vec3 position;
        m3::vec3 rotation;
        m3::vec3 scl;

        Mesh mesh;

    public:
        Model(std::string obj, Color color);

    public:
        m3::mat4 get_matrix();
        Mesh get_mesh();

        void translate(float x, float y, float z);
        void rotate(float x, float y, float z);
        void scale(float x, float y, float z);
};

#endif