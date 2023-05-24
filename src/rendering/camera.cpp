#include "camera.h"

Camera::Camera(m3::vec3 pos, m3::vec3 forward, m3::vec3 world_up, float vfov):
    position(pos),
    rotation(0, 0, 0),
    forward(forward),
    world_up(world_up),
    vfov(vfov)
{
    return;
}

m3::mat4 Camera::get_matrix()
{
    m3::mat4 translation = m3::mat4::translation_matrix(-this->position.x(), -this->position.y(), -this->position.z());

    m3::quat rot = this->rot_quat();
    m3::vec3 forward = rot * this->forward * m3::quat::inverse(rot);

    m3::vec3 target = this->position + this->forward;
    m3::vec3 direction = this->position - target;
    m3::vec3 right = this->world_up % direction;
    m3::vec3 up = direction % right;

    m3::mat4 cob = m3::mat4::change_of_basis_matrix(right, up, direction);

    return cob * translation;
}

m3::quat Camera::rot_quat()
{
    m3::quat rx(this->rotation.x(), m3::vec3(1, 0, 0));
    m3::quat ry(this->rotation.y(), m3::vec3(0, 1, 0));
    m3::quat rz(this->rotation.z(), m3::vec3(0, 0, 1));

    return rx * ry * rz;
}

void Camera::translate(float x, float y, float z)
{
    m3::quat rot = this->rot_quat();
    m3::vec3 forward = rot * this->forward * m3::quat::inverse(rot);

    m3::vec3 target = this->position + this->forward;
    m3::vec3 direction = this->position - target;
    m3::vec3 right = this->world_up % direction;
    m3::vec3 up = direction % right;

    this->position += right * x;
    this->position += up * y;
    this->position += direction * z;

    return;
}

void Camera::rotate(float x, float y, float z)
{
    this->rotation += m3::vec3(x, y, z);
    return;
}

float Camera::fov()
{
    return this->vfov;
}