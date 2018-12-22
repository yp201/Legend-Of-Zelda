#include "main.h"

#ifndef MAN_H
#define MAN_H


class Man {
public:
    Man() {}
    Man(float x,float y, float z,double speed, color_t color);
    glm::vec3 position;
    double speed;
    float rotation;
    float handangle;
    float legangle;
    float bh,bw,bd;
    bool visible;
    bool onboat;
    void drawhead(glm::mat4 VP);
    void drawneck(glm::mat4 VP);
    void drawbody(glm::mat4 VP);
    void drawlarm(glm::mat4 VP);
    void drawrarm(glm::mat4 VP);
    void drawlleg(glm::mat4 VP);
    void drawrleg(glm::mat4 VP);
private:
    VAO *head;
	VAO *neck;
    VAO *body;
    VAO *larm;
	VAO *rarm;
    VAO *lleg;
    VAO *rleg;


};

#endif // MONSTER_H
