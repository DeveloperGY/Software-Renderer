#include "rendering/renderer.h"
#include "rendering/color.h"

#include "td.h"

int main(void)
{
    int view_scale = 2;

    const int width = 40 * view_scale;
    const int height = 24 * view_scale;

    Renderer renderer(width, height);

    if (!renderer.is_initialized())
    {
        return -1;
    }

    Model cube("res/cube.obj", Color(255, 0, 0));
    cube.translate(0, 0, -2);
    cube.rotate(0, 30, 5);
    Camera c(m3::vec3(0, 0, 1), m3::vec3(0, 0, -1), m3::vec3(0, 1, 0), 60.0f);

    while (getch(0) != 'p')
    {
        renderer.render(cube, c, false);
        renderer.display();
    }

    return 0;
}