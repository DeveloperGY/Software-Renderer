#include "mesh.h"

Mesh::Mesh(std::string filename, Color color)
{
    std::ifstream obj;

    obj.open(filename);

    if (!obj.is_open())
    {
        return;
    }

    std::vector<m3::vec3> vertices;
    std::vector<int> vertex_indices;

    std::string line;
    std::string word;

    while(std::getline(obj, line))
    {
        std::istringstream ss(line);

        ss >> word;

        if (word == "v")
        {
            // vertex
            float x, y, z;
            
            ss >> x >> y >> z;
            vertices.push_back(m3::vec3(x, y, z));
        }
        else if(word == "f")
        {
            // face
            int indices[3];

            for (int i=0; i<3; i++)
            {
                std::string vertex_index;

                ss >> word;

                std::istringstream set(word);
                std::getline(set, vertex_index, '/');
                vertex_indices.push_back(std::atoi(vertex_index.c_str()) - 1);
            }
        }
    }

    obj.close();

    for (int i=0; i<vertex_indices.size(); i+=3)
    {
        int vi0 = vertex_indices.at(i);
        int vi1 = vertex_indices.at(i+1);
        int vi2 = vertex_indices.at(i+2);

        m3::vec3 _v0 = vertices.at(vi0);
        m3::vec3 _v1 = vertices.at(vi1);
        m3::vec3 _v2 = vertices.at(vi2);

        Vertex v0(_v0, color);
        Vertex v1(_v1, color);
        Vertex v2(_v2, color);

        this->triangles.push_back(Triangle(v0, v1, v2));
    }

    return;
}


std::vector<Triangle> &Mesh::get_triangles()
{
    return this->triangles;
}