#include "fireball.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Fireball::Fireball(float x, float y,float z,float canonx,float canony, float canonz,float radius, color_t color) {
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->speedy=0;
    this->time=0;
    this->visible=false;
    this->speedx=0;
    this->fired=false;
    this->initial=0.0;
    int j=0;
    static GLfloat fireball[18*20*20+100];
    int k=0,idx=0;
    double x1,y1,z1,r=radius;
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=20;j++)
        {
            x1=r*sin(M_PI*j/10)*cos(M_PI*i/10);
            y1=r*sin(M_PI*j/10)*sin(M_PI*i/10);
            z1=r*cos(M_PI*j/10);
            fireball[idx++]=r*sin(M_PI*j/10)*cos(M_PI*(i+1)/10);
            fireball[idx++]=r*sin(M_PI*j/10)*sin(M_PI*(i+1)/10);
            fireball[idx++]=r*cos(M_PI*j/10);
            fireball[idx++]=x1;
            fireball[idx++]=y1;
            fireball[idx++]=z1;
            k=j+1;
            y1=r*sin(M_PI*k/10)*sin(M_PI*i/10);
            x1=r*sin(M_PI*k/10)*cos(M_PI*i/10);
            z1=r*cos(M_PI*k/10);
            fireball[idx++]=x1;
            fireball[idx++]=y1;
            fireball[idx++]=z1;
            x1=r*sin(M_PI*k/10)*cos(M_PI*i+1/10);
            z1=r*cos(M_PI*k/10);           
            y1=r*sin(M_PI*k/10)*sin(M_PI*i+1/10);
            fireball[idx++]=r*sin(M_PI*j/10)*cos(M_PI*(i+1)/10);
            fireball[idx++]=r*sin(M_PI*j/10)*sin(M_PI*(i+1)/10);
            fireball[idx++]=r*cos(M_PI*j/10);
            fireball[idx++]=x1;
            fireball[idx++]=y1;
            fireball[idx++]=z1;
            y1=r*sin(M_PI*k/10)*sin(M_PI*i/10);
            x1=r*sin(M_PI*k/10)*cos(M_PI*i/10);
            z1=r*cos(M_PI*k/10);
            fireball[idx++]=x1;
            fireball[idx++]=y1;
            fireball[idx++]=z1;
        }
    }

    this->fireball = create3DObject(GL_TRIANGLES, 18*20*20, fireball, { 255,0,0}, GL_FILL);

}

void Fireball::draw(glm::mat4 VP) {
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
    draw3DObject(this->fireball);
    // draw3DObject(this->cap1);
    // draw3DObject(this->cap2);

}

bool Fireball::fire(float theta)
{
    if(this->initial)
    {
        this->time++;
        this->fired=true;
        // cout<<this->position.y<<endl;
        // cout<<this->position.y <<cout<<" "<<cout<< this->speedy*this->time -0.5*0.1*this->time*this->time <<endl;
        if(this->position.y + this->speedy*this->time -0.05*0.1*this->time*this->time > -0.6f)
        {
            // cout<<"fire "<<this->initial<<endl;
            this->position.y=this->position.y + this->speedy*this->time -0.05*0.1*this->time*this->time;
            this->position.z=this->position.z-this->speedx*cos(theta*((3.14)/180.0));
            this->position.x=this->position.x+this->speedx*sin(-theta*((3.14)/180.0));
            return false;
        }
        else
        {
            this->initial=0;
            this->speedy=0;
            this->time=0;
            this->speedx=0;
            this->fired=false;
            return true;
        }
    }
    return false;
}


bool Fireball::collision(float x1, float y1, float z1,float a,float b, float c)
{
        // if(this->position.y<=y1)
        // {
        //     if(this->position.x>x1 && this->position.x>x2)
        //     {
        //         cout<<"collision"<<endl;
        //         cout<<z1<<" --- "<<this->position.z<<endl;
        //         cout<<this->position.z-z1<<endl;
        //         if(abs(this->position.z-z1)<5.0)
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;
    // cout<<"X-"<<this->position.x<<" Y-"<<this->position.y<<" Z- "<<this->position.z<<endl;
    // cout<<"X1-"<<x1<<" Y1-"<<y1<<" Z1- "<<z1<<endl;

    // cout<<"value-- "<<length(glm::vec3(x1,y1,z1)-glm::vec3(this->position.x,this->position.y,this->position.z))<<endl;
    float precision=3.0f;
    if(c==99.0f)
    {
        precision=1.0f;
    }
    if(length(glm::vec3(x1,y1,z1)-glm::vec3(this->position.x,this->position.y,this->position.z))<precision)
    {
        return true;
    }
    else 
        return false;
}


