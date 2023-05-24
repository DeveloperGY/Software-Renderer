#include "renderer.h"

Renderer::Renderer(int width, int height):
    initialized(false)
{
    if (!td_init(width, height))
    {
        return;
    }

    this->initialized = true;
    this->width = width;
    this->height = height;

    return;
}

Renderer::~Renderer()
{
    td_terminate(0);
    return;
}


void Renderer::display()
{
    td_display();
    return;
}

void Renderer::render(Model m, Camera c, bool rasterize)
{
    float aspect_ratio = ((float)this->width / (float)this->height) * (3.0/5.0);
    float near = 0.00001;
    float far = 100;

    m3::mat4 model_matrix = m.get_matrix();
    m3::mat4 view_matrix = c.get_matrix();
    m3::mat4 perspective_matrix = m3::mat4::projection_matrix(c.fov(), aspect_ratio, near, far);
    m3::mat4 mvp_matrix = perspective_matrix * view_matrix * model_matrix;

    for (Triangle &t: m.get_mesh().get_triangles())
    {
        m3::vec4 vertices[3];

        vertices[0] = m3::vec3::as_vec4(t.v0().position(), 1);
        vertices[1] = m3::vec3::as_vec4(t.v1().position(), 1);
        vertices[2] = m3::vec3::as_vec4(t.v2().position(), 1);

        for (int i=0; i<3; i++)
        {
            vertices[i] = mvp_matrix * vertices[i];
        }


        // perspective division;

        for (int i=0; i<3; i++)
        {
            vertices[i] /= ((vertices[i].w() != 0)? vertices[i].w() : 0.000001);
        }


        // normal calculation

        m3::vec3 v0 = m3::vec4::as_vec3(vertices[0]);
        m3::vec3 v1 = m3::vec4::as_vec3(vertices[1]);
        m3::vec3 v2 = m3::vec4::as_vec3(vertices[2]);

        m3::vec3 edge_0 = v1 - v0;
        m3::vec3 edge_1 = v2 - v1;
        m3::vec3 edge_2 = v0 - v2;

        m3::vec3 normal = m3::vec3::normalize(edge_0 % edge_1);


        // transform to screen coordinates

        float hw = this->width / 2;
        float hh = this->height / 2;

        for (int i=0; i<3; i++)
        {
            m3::vec4 v(hw + (vertices[i].x() * hw), hh - (vertices[i].y() * hh), vertices[i].z(), vertices[i].w());
            vertices[i] = v;
        }

        v0 = m3::vec4::as_vec3(vertices[0]);
        v1 = m3::vec4::as_vec3(vertices[1]);
        v2 = m3::vec4::as_vec3(vertices[2]);

        td_color v0_c = t.v0().color().value();
        td_color v1_c = t.v1().color().value();
        td_color v2_c = t.v2().color().value();

        if (rasterize)
        {
            int x_max = std::max(v0.x(), std::max(v1.x(), v2.x()));
            int x_min = std::min(v0.x(), std::min(v1.x(), v2.x()));
        }
        else
        {
            td_drawLine(v0.x(), v0.y(), v1.x(), v1.y(), ' ', v0_c, v0_c);
            td_drawLine(v1.x(), v1.y(), v2.x(), v2.y(), ' ', v1_c, v1_c);
            td_drawLine(v2.x(), v2.y(), v0.x(), v0.y(), ' ', v2_c, v2_c);
        }

        // td_drawPoint(v0.x(), v0.y(), ' ', v0_c, v0_c);
        // td_drawPoint(v1.x(), v1.y(), ' ', v1_c, v1_c);
        // td_drawPoint(v2.x(), v2.y(), ' ', v2_c, v2_c);
    }

    return;
}

bool Renderer::is_initialized()
{
    return this->initialized;
}