#include "monster.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Monster::Monster(float x, float y,float z,double speed, color_t color) {
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->speed=speed;
    this->visible=true;
    float X=0.0f,Y=0.5f;
    int j=0;
    GLfloat head[361*18];
    GLfloat headcap1[361*9];
    GLfloat headcap2[361*9];
    X=0.0,Y=1.0;
    for(int i=0;i<360;i++)
    {
        head[j++]=X;head[j++]=Y; head[j++]=0.0f;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        head[j++]=X; head[j++]=Y; head[j++]=0.0f;
        head[j++]=x1;head[j++]=y1; head[j++]=-0.5f;
        head[j++]=x1;head[j++]=y1; head[j++]=-0.5f;
        head[j++]=X; head[j++]=Y; head[j++]=-0.5f;
        head[j++]=X; head[j++]=Y; head[j++]=0.0f;
    }
    j=0;
    int k=0;
    X=0.0,Y=1.0;
    for(int i=0;i<360;i++)
    {
        headcap1[j++]=X;headcap1[j++]=Y; headcap1[j++]=0.0f;
        headcap2[k++]=X; headcap2[k++]=Y; headcap2[k++]=-0.5f;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        headcap1[j++]=X; headcap1[j++]=Y; headcap1[j++]=0.0f;
        headcap2[k++]=X;headcap2[k++]=Y; headcap2[k++]=-0.5f;

        headcap1[j++]=0;headcap1[j++]=0; headcap1[j++]=0.0f;
        headcap2[k++]=0; headcap2[k++]=0; headcap2[k++]=-0.5f;
    }
    GLfloat body[]={
        0,-0.5f,0,
        -1.5f,-2.3f,0,
        1.5f,-2.3f,0,

        0,-0.5f,-0.5f,
        -1.5f,-2.3f,-0.5f,
        1.5f,-2.3f,-0.5f,

        0,-0.5f,0,
        0,-0.5f,-0.5f,
        1.5f,-2.3f,0,

        0,-0.5f,-0.5f,
        1.5f,-2.3f,0,
        1.5f,-2.3f,-0.5f,   

        0,-0.5f,0,
        0,-0.5f,-0.5f,
        -1.5f,-2.3f,0,

        0,-0.5f,-0.5f,
        -1.5f,-2.3f,0,
        -1.5f,-2.3f,-0.5f,
 

    };
    GLfloat canon[361*18];
    X=0.0f;
    Y=0.2f;
    j=0;
    for(int i=0;i<360;i++)
    {
        canon[j++]=X;canon[j++]=-1.5f+Y; canon[j++]=0;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0) ;
        canon[j++]=X; canon[j++]=-1.5f+Y; canon[j++]=0;
        canon[j++]=x1;canon[j++]=-1.5f+y1; canon[j++]=2.0f;
        canon[j++]=x1;canon[j++]=-1.5f+y1; canon[j++]=2.0f;
        canon[j++]=X; canon[j++]=-1.5f+Y; canon[j++]=2.0f;
        canon[j++]=X; canon[j++]=-1.5f+Y; canon[j++]=0;

    }
    this->canon=create3DObject(GL_TRIANGLES, 6*360, canon, {255,150,198}, GL_FILL);
    j=0;
    // for(int i=0;i<360;i++)
    // {
    //     canon[j++]=X-2.0f;canon[j++]=-1.5f+Y; canon[j++]=this->position.z;
    //     float x1=X,y1=Y;
    //     X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
    //     Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0) ;
    //     canon[j++]=X-2.0f; canon[j++]=-1.5f+Y; canon[j++]=this->position.z;
    //     canon[j++]=x1;canon[j++]=-1.5f+y1; canon[j++]=this->position.z;
    //     canon[j++]=x1;canon[j++]=-1.5f+y1; canon[j++]=this->position.z;
    //     canon[j++]=X-2.0f; canon[j++]=-1.5f+Y; canon[j++]=this->position.z;
    //     canon[j++]=X-2.0f; canon[j++]=-1.5f+Y; canon[j++]=this->position.z;

    // }
    // 


    this->head = create3DObject(GL_TRIANGLES, 6*360, head, {0,0,0}, GL_FILL);
    this->headcap1 = create3DObject(GL_TRIANGLES, 3*360,  headcap1, {0,0,0}, GL_FILL);
    this->headcap2 = create3DObject(GL_TRIANGLES, 3*360,  headcap2, {0,0,0}, GL_FILL);
    this->body = create3DObject(GL_TRIANGLES, 18,  body, {0,0,180}, GL_FILL);

}

void Monster::draw(glm::mat4 VP) {
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
    draw3DObject(this->head);
    draw3DObject(this->headcap1);
    draw3DObject(this->headcap2);
    draw3DObject(this->body);
    draw3DObject(this->canon);


}


