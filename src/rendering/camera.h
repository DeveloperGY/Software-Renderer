#ifndef CAMERA_H
#define CAMERA_H

#include <math3d.h>

class Camera
{
    private:
        m3::vec3 position;
        m3::vec3 rotation;

        m3::vec3 forward;
        m3::vec3 world_up;

        float vfov;

    public:
        Camera(m3::vec3 pos, m3::vec3 forward, m3::vec3 world_up, float vfov);

    private:
        m3::quat rot_quat();

    public:
        m3::mat4 get_matrix();

        void translate(float x, float y, float z);
        void rotate(float x, float y, float z);
        
        float fov();
};

#endif