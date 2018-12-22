#include "main.h"

#ifndef ISLAND_H
#define ISLAND_H


class Island {
public:
    Island() {}
    Island(float x,float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    bool visible;
    bool visible1;
    void draw(glm::mat4 VP);
private:
    VAO *object;
    VAO *barrel;
    VAO *cap1;
    VAO *cap2;
    VAO *gift;

};

#endif // ISLAND_H
