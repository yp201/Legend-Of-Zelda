#include "main.h"

#ifndef BOSS_H
#define BOSS_H


class Boss {
public:
    Boss() {}
    Boss(float x,float y, float z,double speed, color_t color);
    glm::vec3 position;
    double speed;
    float health;
    float rotation;
    bool visible;
    void tick();
    void draw(glm::mat4 VP);
private:
    VAO *headman;
    VAO *hand1;
    VAO *hand2;
    VAO *hand3;
    VAO *hand4;

};

#endif // BOSS_H
