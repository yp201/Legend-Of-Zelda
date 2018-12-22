#include "main.h"
#include "fireball.h"
#include "man.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y,float speed, color_t color);
    glm::vec3 position;
    glm::vec3 canon_position;
    float rotation;
    float speed;
    int time;
    float initial;
    float canonrotation;
    bool visible;
    void draw(glm::mat4 VP);
    void canonrotate(glm::mat4 VP);
    void canondraw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(Fireball* Fireball,Man *man);
    double theta;
private:
    VAO *object;
    VAO *base;
    VAO *sail;
    VAO *canon;

};

#endif // BALL_H
