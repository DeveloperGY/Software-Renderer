#ifndef RENDERER_H
#define RENDERER_H

#include "model.h"
#include "camera.h"

#include <td.h>
#include <math3d.h>

#include <string>

class Renderer
{
    private:
        int width;
        int height;

        bool initialized;

    public:
        Renderer(int width, int height);
        ~Renderer();

    public:
        void display();
        void render(Model m, Camera c, bool rasterize);

        bool is_initialized();
};

#endif