#include "main.h"

#ifndef OBSTACLE_H
#define OBSTACLE_H


class Obstacle {
public:
    Obstacle() {}
    Obstacle(float x, float y,float z,float size,float height,float top,float deviation, color_t color);
    glm::vec3 position;
    float rotation;
    float size;
    float top;
    bool visible;
    float height;
    float deviation;
    void draw(glm::mat4 VP);
private:
    VAO *topdraw;
    VAO *base;
};

#endif // OBSTACLE_H
