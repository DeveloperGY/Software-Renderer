#include "model.h"

Model::Model(std::string obj, Color color):
    position(0, 0, 0),
    rotation(0, 0, 0),
    scl(1, 1, 1),
    mesh(Mesh(obj, color))
{
    return;
}

m3::mat4 Model::get_matrix()
{
    m3::mat4 translation = m3::mat4::translation_matrix(this->position.x(), this->position.y(), this->position.z());
    m3::quat rx(this->rotation.x(), m3::vec3(1, 0, 0));
    m3::quat ry(this->rotation.y(), m3::vec3(0, 1, 0));
    m3::quat rz(this->rotation.z(), m3::vec3(0, 0, 1));    
    m3::quat rotation = rx * ry * rz;
    m3::mat4 scale = m3::mat4::scale_matrix(this->scl.x(), this->scl.y(), this->scl.z());

    return translation * rotation * scale;
}

Mesh Model::get_mesh()
{
    return this->mesh;
}


void Model::translate(float x, float y, float z)
{
    this->position += m3::vec3(x, y, z);
    return;
}

void Model::rotate(float x, float y, float z)
{
    this->rotation += m3::vec3(x, y, z);
    return;
}

void Model::scale(float x, float y, float z)
{
    this->scl += m3::vec3(x, y ,z);
    return;
}