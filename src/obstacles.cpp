#include "obstacles.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Obstacle::Obstacle(float x, float y,float z,float size,float height,float top,float deviation, color_t color) {
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->size=size;
    this->visible=true;
    GLfloat base[] = {
        -size,-size,-size, // triangle 1 : begin
        -size,-size, size,
        -size, size, size, // triangle 1 : end
        size, size,-size, // triangle 2 : begin
        -size,-size,-size,
        -size, size,-size, // triangle 2 : end
        size,-size, size,
        -size,-size,-size,
        size,-size,-size,
        size, size,-size,
        size,-size,-size,
        -size,-size,-size,
        -size,-size,-size,
        -size, size, size,
        -size, size,-size,
        size,-size, size,
        -size,-size, size,
        -size,-size,-size,
        -size, size, size,
        -size,-size, size,
        size,-size, size,
        size, size, size,
        size,-size,-size,
        size, size,-size,
        size,-size,-size,
        size, size, size,
        size,-size, size,
        size, size, size,
        size, size,-size,
        -size, size,-size,
        size, size, size,
        -size, size,-size,
        -size, size, size,
        size, size, size ,
        -size, size, size,
        size,-size, size
    };
    GLfloat toptriangle[] = {
        height,top,deviation,
        size,size,-size,
        size,size,size,
        height,top,deviation,
        size,size,size,
        -size,size,size,
        height,top,deviation,
        -size,size,-size,
        -size,size,size,
        height,top,deviation,
        size,size,-size,
        size,size,-size,
    };

    this->base = create3DObject(GL_TRIANGLES, 36, base, { 204, 204, 204 }, GL_FILL);
    this->topdraw = create3DObject(GL_TRIANGLES, 12,  toptriangle, { 204, 204, 204 }, GL_FILL);

}

void Obstacle::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, -1.0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);

    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    draw3DObject(this->base);
    draw3DObject(this->topdraw);
    glDisable(GL_BLEND);
    // draw3DObject(this->base);

}


