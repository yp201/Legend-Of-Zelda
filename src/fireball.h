#include "main.h"

#ifndef FIREBALL_H
#define FIREBALL_H


class Fireball {
public:
    Fireball() {}
    Fireball(float x,float y, float z,float canonx,float canony, float canonz,float radius, color_t color);
    glm::vec3 position;
    float rotation;
    float radius;
    float initial;
    int time;
    bool visible;
    float canonx,canony,canonz;
    bool fired;
    float speedy;
    float speedx;
    void draw(glm::mat4 VP);
    bool fire(float theta);
    bool collision(float x,float y, float z, float a, float b , float c);
private:
    VAO *fireball;
    VAO *cap1;
    VAO *cap2;
};

#endif // FIREBALL_H
