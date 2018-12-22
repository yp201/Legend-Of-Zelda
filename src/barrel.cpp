#include "barrel.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Barrel::Barrel(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->visible=true;
    float X=0.0f,Y=0.5f;
    int j=0;
    static GLfloat barrel[361*18];
    static GLfloat cap1[361*9];
    static GLfloat cap2[361*9];

            static GLfloat const sqr[]={
                0.0,2.9,-1.5,
                -1.0,2.5,-1.5,
                0.5*2,2.5,-1.5,
                0.5*2,2.5,-1.5,
                -0.5*2,2.9,-1.5,
                0.5*2,2.9,-1.5,
                1,2.9,-1.5,
                1,2.5,-1.5,
                1.4,2.7,-1.5,

            };


            X=0.0,Y=1.2;
            for(int i=0;i<360;i++)
            {
                barrel[j++]=X;barrel[j++]=Y; barrel[j++]=0.0f;
                float x1=X,y1=Y;
                X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
                Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
                barrel[j++]=X; barrel[j++]=Y; barrel[j++]=0.0f;
                barrel[j++]=x1;barrel[j++]=y1; barrel[j++]=-3.0f;
                barrel[j++]=x1;barrel[j++]=y1; barrel[j++]=-3.0f;
                barrel[j++]=X; barrel[j++]=Y; barrel[j++]=-3.0f;
                barrel[j++]=X; barrel[j++]=Y; barrel[j++]=0.0f;
            }
            j=0;
            int k=0;
            X=0.0,Y=1.2;
            for(int i=0;i<360;i++)
            {
                cap1[j++]=X;cap1[j++]=Y; cap1[j++]=0.0f;
                cap2[k++]=X; cap2[k++]=Y; cap2[k++]=-3.0f;
                float x1=X,y1=Y;
                X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
                Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
                cap1[j++]=X; cap1[j++]=Y; cap1[j++]=0.0f;
                cap2[k++]=X;cap2[k++]=Y; cap2[k++]=-3.0f;

                cap1[j++]=0;cap1[j++]=0; cap1[j++]=0.0f;
                cap2[k++]=0; cap2[k++]=0; cap2[k++]=-3.0f;
            }

    this->barrel = create3DObject(GL_TRIANGLES, 6*360, barrel, { 109, 69, 53}, GL_FILL);
    this->cap1 = create3DObject(GL_TRIANGLES, 3*360,  cap1, {109, 69, 53}, GL_FILL);
    this->cap2 = create3DObject(GL_TRIANGLES, 3*360,  cap2, {109, 69, 53}, GL_FILL);
    this->reward = create3DObject(GL_TRIANGLES, 9,  sqr, {220,135,29}, GL_FILL);


}

void Barrel::draw(glm::mat4 VP) {
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
    draw3DObject(this->barrel);
    draw3DObject(this->cap1);
    draw3DObject(this->cap2);
    draw3DObject(this->reward);


}


