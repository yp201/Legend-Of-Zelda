#include "main.h"

#ifndef BARREL_H
#define BARREL_H


class Barrel {
public:
    Barrel() {}
    Barrel(float x,float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    float visible;
    void draw(glm::mat4 VP);
private:
    VAO *barrel;
    VAO *cap1;
    VAO *cap2;
    VAO *reward;

};

#endif // BARREL_H
