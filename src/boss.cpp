#include "boss.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Boss::Boss(float x, float y,float z,double speed, color_t color) {
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->speed=speed;
    this->health=5;
    this->visible=false;
    int j=0;
    double x1,y1,z1,r=1.0f;
    int k=0,idx=0;
    GLfloat headman[18*10*10+100];
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
        {
            x1=r*sin(M_PI*j/5)*cos(M_PI*i/5);
            y1=r*sin(M_PI*j/5)*sin(M_PI*i/5);
            z1=r*cos(M_PI*j/5);
            headman[idx++]=r*sin(M_PI*j/5)*cos(M_PI*(i+1)/5);
            headman[idx++]=r*sin(M_PI*j/5)*sin(M_PI*(i+1)/5);
            headman[idx++]=r*cos(M_PI*j/5);
            headman[idx++]=x1;
            headman[idx++]=y1;
            headman[idx++]=z1;
            k=j+1;
            y1=r*sin(M_PI*k/5)*sin(M_PI*i/5);
            x1=r*sin(M_PI*k/5)*cos(M_PI*i/5);
            z1=r*cos(M_PI*k/5);
            headman[idx++]=x1;
            headman[idx++]=y1;
            headman[idx++]=z1;
            x1=r*sin(M_PI*k/5)*cos(M_PI*i+1/5);
            z1=r*cos(M_PI*k/5);           
            y1=r*sin(M_PI*k/5)*sin(M_PI*i+1/5);
            headman[idx++]=r*sin(M_PI*j/5)*cos(M_PI*(i+1)/5);
            headman[idx++]=r*sin(M_PI*j/5)*sin(M_PI*(i+1)/5);
            headman[idx++]=r*cos(M_PI*j/5);
            headman[idx++]=x1;
            headman[idx++]=y1;
            headman[idx++]=z1;
            y1=r*sin(M_PI*k/5)*sin(M_PI*i/5);
            x1=r*sin(M_PI*k/5)*cos(M_PI*i/5);
            z1=r*cos(M_PI*k/5);
            headman[idx++]=x1;
            headman[idx++]=y1;
            headman[idx++]=z1;
        }
    }
     GLfloat hand1[361*18];
     GLfloat hand2[361*18];
     GLfloat hand3[361*18];
     GLfloat hand4[361*18];
    j=0;
    float X=0.0,Y=0.2;
    for(int i=0;i<360;i++)
    {
        hand1[j++]=X;hand1[j++]=Y; hand1[j++]=0.0f+2*r;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        hand1[j++]=X; hand1[j++]=Y; hand1[j++]=0.0f+2*r;
        hand1[j++]=x1;hand1[j++]=y1; hand1[j++]=-3.0f+2*r;
        hand1[j++]=x1;hand1[j++]=y1; hand1[j++]=-3.0f+2*r;
        hand1[j++]=X; hand1[j++]=Y; hand1[j++]=-3.0f+2*r;
        hand1[j++]=X; hand1[j++]=Y; hand1[j++]=0.0f+2*r;
    }
    j=0;
    X=0.0,Y=0.2;
    for(int i=0;i<360;i++)
    {
        hand2[j++]=X;hand2[j++]=Y; hand2[j++]=0.0f-r;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        hand2[j++]=X; hand2[j++]=Y; hand2[j++]=0.0f-r;
        hand2[j++]=x1;hand2[j++]=y; hand2[j++]=-3.0f-r;
        hand2[j++]=x1;hand2[j++]=y; hand2[j++]=-3.0f-r;
        hand2[j++]=X; hand2[j++]=Y; hand2[j++]=-3.0f-r;
        hand2[j++]=X; hand2[j++]=Y; hand2[j++]=0.0f-r;
    }
    j=0;
    X=0.0,Y=0.2;
    for(int i=0;i<360;i++)
    {
        hand3[j++]=X+r;hand3[j++]=Y; hand3[j++]=0.0f;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        hand3[j++]=X+r; hand3[j++]=Y; hand3[j++]=0.0f;
        hand3[j++]=x1+r;hand3[j++]=y1; hand3[j++]=3.0f;
        hand3[j++]=x1+r;hand3[j++]=y1; hand3[j++]=3.0f;
        hand3[j++]=X+r; hand3[j++]=Y; hand3[j++]=3.0f;
        hand3[j++]=X+r; hand3[j++]=Y; hand3[j++]=0.0f;
    }
    j=0;
    X=0.0,Y=0.2;
    for(int i=0;i<360;i++)
    {
        hand4[j++]=X-r;hand4[j++]=Y; hand4[j++]=0.0f;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        hand4[j++]=X-r; hand4[j++]=Y; hand4[j++]=0.0f;
        hand4[j++]=x1-r;hand4[j++]=y1; hand4[j++]=3.0f;
        hand4[j++]=x1-r;hand4[j++]=y1; hand4[j++]=3.0f;
        hand4[j++]=X-r; hand4[j++]=Y; hand4[j++]=3.0f;
        hand4[j++]=X-r; hand4[j++]=Y; hand4[j++]=0.0f;
    }
            
    this->headman= create3DObject(GL_TRIANGLES, 18*10*10, headman, {51,105,30}, GL_FILL);
    this->hand1 = create3DObject(GL_TRIANGLES, 6*360, hand1, { 245, 289, 53}, GL_FILL);
    this->hand2 = create3DObject(GL_TRIANGLES, 6*360, hand2, { 245, 289, 53}, GL_FILL);
    this->hand3 = create3DObject(GL_TRIANGLES, 6*360, hand3, { 245, 289, 53}, GL_FILL);
    this->hand4 = create3DObject(GL_TRIANGLES, 6*360, hand4, { 245, 289, 53}, GL_FILL);

   

}

void Boss::draw(glm::mat4 VP) {
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
    draw3DObject(this->headman);
    draw3DObject(this->hand1);
    draw3DObject(this->hand2);
    draw3DObject(this->hand3);
    draw3DObject(this->hand4);


}

void Boss::tick()
{
    this->rotation+=2;
}


