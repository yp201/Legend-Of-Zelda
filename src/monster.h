#include "main.h"

#ifndef MONSTER_H
#define MONSTER_H


class Monster {
public:
    Monster() {}
    Monster(float x,float y, float z,double speed, color_t color);
    glm::vec3 position;
    double speed;
    float rotation;
    bool visible;
    void draw(glm::mat4 VP);
private:
    VAO *head;
	VAO *headcap1;
    VAO *headcap2;
    VAO *body;
	VAO *canon;




};

#endif // MONSTER_H
