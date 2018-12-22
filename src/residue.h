#include "main.h"

#ifndef RESIDUE_H
#define RESIDUE_H


class Residue {
public:
    Residue() {}
    Residue(float x,float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    float visible;
    int time;
    void draw(glm::mat4 VP);
    void tick();
private:
    VAO *object;

};

#endif // RESIDUE_H
