#include "residue.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Residue::Residue(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->visible=true;
    this->time=180;
    GLfloat data[]={
        0.1f,y,0.1f,
        -0.1f,y,-0.1f,
        0.1f,y,-0.1f,
        0.1f,y,0.1f,
        -0.1f,y,-0.1f,
        -0.1f,y,0.1f,
    };
    this->object = create3DObject(GL_TRIANGLES, 6, data, { 255,255,255}, GL_FILL);

}

void Residue::draw(glm::mat4 VP) {
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
    draw3DObject(this->object);
    // draw3DObject(this->cap1);
    // draw3DObject(this->cap2);

}

void Residue::tick()
{
    this->time--;
    if(this->time<=0)
    {
        this->visible=false;
    }
}


