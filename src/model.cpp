#include "model.h"

Model::Model(std::string obj, Color color):
    mesh(obj, color),
    position(0, 0, 0),
    rotation(0, 0, 0),
    scale(1, 1, 1)
{
    return;
}