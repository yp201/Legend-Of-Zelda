#include "man.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Man::Man(float x, float y,float z,double speed, color_t color) {
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->speed=speed;
    this->visible=true;
    this->handangle=0.0f;
    this->onboat=true;
    this->legangle=0.0f;
    float X=0.0f,Y=0.5f;
    int j=0;
    this->bh=0.12f,this->bw=0.07f;
    this->bd=0.05f;
    static const GLfloat body[] = {
        -bw,bh,0.0,
        -bw,-bh,0.0,
        bw,-bh,0.0,
        -bw,bh,0.0,
        bw,bh,0.0,
        bw,-bh,0.0,

        -bw,bh,-bd,
        -bw,-bh,-bd,
        bw,-bh,-bd,
        -bw,bh,-bd,
        bw,bh,-bd,
        bw,-bh,-bd,

        bw,bh,0.0,
        bw,-bh,0.0,
        bw,-bh,-bd,
        bw,bh,0.0,
        bw,-bh,-bd,
        bw,bh,-bd,

        -bw,bh,0.0,
        -bw,-bh,0.0,
        -bw,-bh,-bd,
        -bw,bh,0.0,
        -bw,-bh,-bd,
        -bw,bh,-bd,

        bw,bh,0.0,
        -bw,bh,0.0,
        bw,bh,-bd,
        -bw,bh,0.0,
        bw,bh,-bd,
        -bw,bh,-bd,

        bw,-bh,0.0,
        -bw,-bh,0.0,
        bw,-bh,-bd,
        -bw,-bh,0.0,
        bw,-bh,-bd,
        -bw,-bh,-bd,

    };
    this->body = create3DObject(GL_TRIANGLES, 36,  body, {255,53,53} , GL_FILL);

    j=0;
    GLfloat neck1 [361*18];
    X=0.0,Y=0.03;
    for(int i=0;i<360;i++)
    {

      
        neck1[j++]=X;neck1[j++]=0.0f;neck1[j++]=Y;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        neck1[j++]=X;neck1[j++]=0.0f; neck1[j++]=Y;
        neck1[j++]=x1;neck1[j++]=bh/4.0f;neck1[j++]=y1;
        neck1[j++]=x1;neck1[j++]=bh/4.0f;neck1[j++]=y1;
        neck1[j++]=X; neck1[j++]=bh/4.0f;neck1[j++]=Y;
        neck1[j++]=X;neck1[j++]=0.0f; neck1[j++]=Y;

    }
    this->neck = create3DObject(GL_TRIANGLES, 6*360,  neck1, {227,167,115}, GL_FILL);
    j=0;
    GLfloat larm[360*18+1];
    X=0.0,Y=0.02;
    for(int i=0;i<360;i++)
    {

        larm[j++]=X;larm[j++]=0.0f;larm[j++]=Y;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        larm[j++]=X;larm[j++]=0.0f; larm[j++]=Y;
        larm[j++]=x1;larm[j++]=1.5*bh;larm[j++]=y1;
        larm[j++]=x1;larm[j++]=1.5*bh;larm[j++]=y1;
        larm[j++]=X; larm[j++]=1.5*bh;larm[j++]=Y;
        larm[j++]=X;larm[j++]=0.0f; larm[j++]=Y;

    }
    this->larm = create3DObject(GL_TRIANGLES, 6*360,  larm, {227,167,115}, GL_FILL);
    GLfloat rarm[360*18+1];
    j=0;
    X=0.0,Y=0.02;
    for(int i=0;i<360;i++)
    {

        rarm[j++]=X;rarm[j++]=0.0f;rarm[j++]=Y;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        rarm[j++]=X;rarm[j++]=0.0f; rarm[j++]=Y;
        rarm[j++]=x1;rarm[j++]=1.5*bh;rarm[j++]=y1;
        rarm[j++]=x1;rarm[j++]=1.5*bh;rarm[j++]=y1;
        rarm[j++]=X; rarm[j++]=1.5*bh;rarm[j++]=Y;
        rarm[j++]=X;rarm[j++]=0.0f; rarm[j++]=Y;

    }
    this->rarm = create3DObject(GL_TRIANGLES, 6*360,  rarm, {227,167,115}, GL_FILL);
    GLfloat lleg[360*18+1];
    X=0.0,Y=0.02;
    j=0;
    for(int i=0;i<360;i++)
    {
        lleg[j++]=X;lleg[j++]=0.0f;lleg[j++]=Y;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        lleg[j++]=X;lleg[j++]=0.0f; lleg[j++]=Y;
        lleg[j++]=x1;lleg[j++]=2*bh;lleg[j++]=y1;
        lleg[j++]=x1;lleg[j++]=2*bh;lleg[j++]=y1;
        lleg[j++]=X;lleg[j++]=2*bh;lleg[j++]=Y;
        lleg[j++]=X;lleg[j++]=0.0f; lleg[j++]=Y;

    }
    this->lleg = create3DObject(GL_TRIANGLES, 6*360,  lleg, {65,105,225}, GL_FILL);


    j=0;
    GLfloat rleg[360*18+1];
    X=0.0,Y=0.02;
    for(int i=0;i<360;i++)
    {

        rleg[j++]=X;rleg[j++]=0.0f;rleg[j++]=Y;
        float x1=X,y1=Y;
        X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
        Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
        rleg[j++]=X;rleg[j++]=0.0f; rleg[j++]=Y;
        rleg[j++]=x1;rleg[j++]=2.5*bh;rleg[j++]=y1;
        rleg[j++]=x1;rleg[j++]=2.5*bh;rleg[j++]=y1;
        rleg[j++]=X; rleg[j++]=2.5*bh;rleg[j++]=Y;
        rleg[j++]=X;rleg[j++]=0.0f; rleg[j++]=Y;

    }

    this->rleg = create3DObject(GL_TRIANGLES, 6*360,  rleg, {65,105,225}, GL_FILL);

    GLfloat head[18*10*10+1];
    // static GLfloat cap1[361*9];
    // static GLfloat cap2[361*9];
    double x1,y1,z1,r=bh/2;
    int k,idx=0;
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
        {
            x1=r*sin(M_PI*j/5)*cos(M_PI*i/5);
            y1=r*sin(M_PI*j/5)*sin(M_PI*i/5);
            z1=r*cos(M_PI*j/5);
            head[idx++]=r*sin(M_PI*j/5)*cos(M_PI*(i+1)/5);
            head[idx++]=r*sin(M_PI*j/5)*sin(M_PI*(i+1)/5);
            head[idx++]=r*cos(M_PI*j/5);
            head[idx++]=x1;
            head[idx++]=y1;
            head[idx++]=z1;
            k=j+1;
            y1=r*sin(M_PI*k/5)*sin(M_PI*i/5);
            x1=r*sin(M_PI*k/5)*cos(M_PI*i/5);
            z1=r*cos(M_PI*k/5);
            head[idx++]=x1;
            head[idx++]=y1;
            head[idx++]=z1;
            x1=r*sin(M_PI*k/5)*cos(M_PI*i+1/5);
            z1=r*cos(M_PI*k/5);
            y1=r*sin(M_PI*k/5)*sin(M_PI*i+1/5);
            head[idx++]=r*sin(M_PI*j/5)*cos(M_PI*(i+1)/5);
            head[idx++]=r*sin(M_PI*j/5)*sin(M_PI*(i+1)/5);
            head[idx++]=r*cos(M_PI*j/5);
            head[idx++]=x1;
            head[idx++]=y1;
            head[idx++]=z1;
            y1=r*sin(M_PI*k/5)*sin(M_PI*i/5);
            x1=r*sin(M_PI*k/5)*cos(M_PI*i/5);
            z1=r*cos(M_PI*k/5);
            head[idx++]=x1;
            head[idx++]=y1;
            head[idx++]=z1;
        }
    }

  


    this->head = create3DObject(GL_TRIANGLES, 18*10*10, head, {227,167,115}, GL_FILL);


}

void Man::drawbody(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, -1.0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;

    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);
    draw3DObject(this->body);
    this->drawhead(MVP);
    this->drawneck(MVP);
    this->drawrarm(MVP);
    this->drawlarm(MVP);
    this->drawrleg(MVP);
    this->drawlleg(MVP);
    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);


}
void Man::drawneck(glm::mat4 VP) {
    float a=0,b=bh;
    float c=-bd/2.0f;
    glm::vec3 temp=glm::vec3(a,b,c);

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (temp);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, -1.0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);

    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->neck);


}
void Man::drawlarm(glm::mat4 VP) {
    float a=bw,b=bh;
    float c=-bd/2.0f;
    glm::vec3 temp=glm::vec3(a,b,c);

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (temp);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) ((180-handangle) * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, -1.0));
    Matrices.model *= (translate * rotate );
    // Matrices.model *= (translate * rotate *rotate1);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);

    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->larm);


}
void Man::drawrarm(glm::mat4 VP) {
    float a=-bw,b=bh;
    float c=-bd/2.0f;
    glm::vec3 temp=glm::vec3(a,b,c);

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (temp);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) ((180+handangle)* M_PI / 180.0f), glm::vec3(1, 0, 0));
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, -1.0));
    Matrices.model *= (translate * rotate );
    // Matrices.model *= (translate * rotate * rotate1);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);

    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->rarm);


}
void Man::drawlleg(glm::mat4 VP) {
    float a=bw-bw/6.0f,b=-bh;
    float c=-bd/2.0f;
    glm::vec3 temp=glm::vec3(a,b,c);

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (temp);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) ((180-legangle) * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, -1.0));
    Matrices.model *= (translate * rotate );
    // Matrices.model *= (translate * rotate * rotate1);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);

    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->lleg);


}
void Man::drawrleg(glm::mat4 VP) {
    float a=-bw+bw/6.0f,b=-bh;
    float c=-bd/2.0f;
    glm::vec3 temp=glm::vec3(a,b,c);

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (temp);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) ((180+legangle) * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, -1.0));
    Matrices.model *= (translate * rotate );
    // Matrices.model *= (translate * rotate * rotate1);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);

    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->rleg);


}
void Man::drawhead(glm::mat4 VP) {
    float a=0,b=bh+bh/8.0f+0.05f;float c=-bd/2.0f;
    glm::vec3 temp=glm::vec3(a,b,c);

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (temp);    // glTranslatef
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


}




