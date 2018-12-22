#include "island.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Island::Island(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->visible=true;
    this->visible1=false;
    int j=0;
    GLfloat object[361*9];
    float X=0.0f,Y=50.0f;
    for(int i=0;i<361;i++)
    {
        float x1=X,y1=Y;
        object[j++]=X;object[j++]=0.0f; object[j++]=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        object[j++]=X; object[j++]=0.0f; object[j++]=Y;
        object[j++]=0;object[j++]=0; object[j++]=0.0f;
    }
    this->object= create3DObject(GL_TRIANGLES, 361*3 , object, {225,218,180}, GL_FILL);

    static GLfloat barrel[181*18];
    static GLfloat cap1[181*9];
    static GLfloat cap2[181*9];

            

            j=0;
            X=1.2,Y=0.0;
            for(int i=0;i<180;i++)
            {
                barrel[j++]=0.0f;barrel[j++]=Y; barrel[j++]=X;
                float x1=X,y1=Y;
                X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
                Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
                barrel[j++]=0.0f; barrel[j++]=Y; barrel[j++]=X;
                barrel[j++]=-3.0f;barrel[j++]=y1; barrel[j++]=x1;
                barrel[j++]=-3.0f;barrel[j++]=y1; barrel[j++]=x1;
                barrel[j++]=-3.0f; barrel[j++]=Y; barrel[j++]=X;
                barrel[j++]=0.0f; barrel[j++]=Y; barrel[j++]=X;
            }
            j=0;
            int k=0;
            X=1.2,Y=0.0;
            for(int i=0;i<180;i++)
            {
                cap1[j++]=0.0f;cap1[j++]=Y; cap1[j++]=X;
                cap2[k++]=-3.0f; cap2[k++]=Y; cap2[k++]=X;
                float x1=X,y1=Y;
                X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
                Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
                cap1[j++]=0.0f; cap1[j++]=Y; cap1[j++]=X;
                cap2[k++]=-3.0f;cap2[k++]=Y; cap2[k++]=X;

                cap1[j++]=0;cap1[j++]=0; cap1[j++]=0.0f;
                cap2[k++]=-3.0f; cap2[k++]=0; cap2[k++]=0;
            }
    static const GLfloat gift[]={
        0.2,0.9,0.0,
        -0.2,0.6,0.0,
        0.2,0.6,0.0,
        -0.2,0.9,0.0,
        0.2,0.9,0.0,
        -0.2,0.6,0.0,
        
        // 0.45,0.7,0.0,
        // 0.25,-0.7,0.0,
        // 0.25,0.7,0.0,
        // 0.45,0.7,0.0,
        // -0.45,-0.7,0.0,
        // -0.25,-0.7,0.0,

    };
    this->barrel = create3DObject(GL_TRIANGLES, 6*180, barrel, { 109, 69, 53}, GL_FILL);
    this->cap1 = create3DObject(GL_TRIANGLES, 3*180,  cap1, {109, 69, 53}, GL_FILL);
    this->cap2 = create3DObject(GL_TRIANGLES, 3*180,  cap2, {109, 69, 53}, GL_FILL);
    this->gift = create3DObject(GL_TRIANGLES, 6,  gift, {255, 0, 0}, GL_FILL);

}


void Island::draw(glm::mat4 VP) {
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
    if(this->visible)
    {
        draw3DObject(this->barrel);
        draw3DObject(this->cap1);
        draw3DObject(this->cap2);
    }
    else if(this->visible1)
    {
        draw3DObject(this->gift);
    }


}


