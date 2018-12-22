#include "main.h"

#ifndef SCENE_H
#define SCENE_H


class Scene {
public:
    Scene() {}
    Scene(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
private:
    VAO *object;
    VAO *base;

};

#endif // SCENE_H
