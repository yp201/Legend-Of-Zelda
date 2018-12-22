#include "ball.h"
#include "main.h"
// #include "fireball.h"
#include <bits/stdc++.h>
using namespace std;


Ball::Ball(float x, float y,float speed, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->speed=0;
    this->time=0;
    this->initial=0;
    this->visible=true;
    this->canon_position = glm::vec3(this->position.x,this->position.y+0.3,this->position.z);
    this->canonrotation=0;
    this->rotation =0 ;
    this->theta=0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    // static const GLfloat vertex_buffer_data[] = {
    //     -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    //     -1.0f,-1.0f, 1.0f,
    //     -1.0f, 1.0f, 1.0f, // triangle 1 : end
    //     1.0f, 1.0f,-1.0f, // triangle 2 : begin
    //     -1.0f,-1.0f,-1.0f,
    //     -1.0f, 1.0f,-1.0f, // triangle 2 : end
    //     1.0f,-1.0f, 1.0f,
    //     -1.0f,-1.0f,-1.0f,
    //     1.0f,-1.0f,-1.0f,
    //     1.0f, 1.0f,-1.0f,
    //     1.0f,-1.0f,-1.0f,
    //     -1.0f,-1.0f,-1.0f,
    //     -1.0f,-1.0f,-1.0f,
    //     -1.0f, 1.0f, 1.0f,
    //     -1.0f, 1.0f,-1.0f,
    //     1.0f,-1.0f, 1.0f,
    //     -1.0f,-1.0f, 1.0f,
    //     -1.0f,-1.0f,-1.0f,
    //     -1.0f, 1.0f, 1.0f,
    //     -1.0f,-1.0f, 1.0f,
    //     1.0f,-1.0f, 1.0f,
    //     1.0f, 1.0f, 1.0f,
    //     1.0f,-1.0f,-1.0f,
    //     1.0f, 1.0f,-1.0f,
    //     1.0f,-1.0f,-1.0f,
    //     1.0f, 1.0f, 1.0f,
    //     1.0f,-1.0f, 1.0f,
    //     1.0f, 1.0f, 1.0f,
    //     1.0f, 1.0f,-1.0f,
    //     -1.0f, 1.0f,-1.0f,
    //     1.0f, 1.0f, 1.0f,
    //     -1.0f, 1.0f,-1.0f,
    //     -1.0f, 1.0f, 1.0f,
    //     1.0f, 1.0f, 1.0f ,
    //     -1.0f, 1.0f, 1.0f,
    //     1.0f,-1.0f, 1.0f
    // };
     GLfloat vertex_buffer_data[] = {
        0.0f,0.0f,-1.0f, // triangle 1 : begin
        1.0f,0.0f, 0.0f,
        1.0f, 1.0f, 0.0f, // triangle 1 : end
        0.0f,0.0f,-1.0f, // triangle 1 : begin
        1.0f, 1.0f, 0.0f, // triangle 1 : end
        0.0f, 1.0f,-1.0f, // triangle 2 : end
        
        0.0f,0.0f,-1.0f, // triangle 1 : begin
        -1.0f,0.0f, 0.0f,
        -1.0f, 1.0f, 0.0f, // triangle 1 : end
        0.0f,0.0f,-1.0f, // triangle 1 : begin
        -1.0f, 1.0f, 0.0f, // triangle 1 : end
        0.0f, 1.0f,-1.0f, // triangle 2 : end
        


        0.7f,0.5f,3.0f, // triangle 1 : begin
        1.0f,1.0f, 0.0f,
        0.7f,0.5f,3.0f, // triangle 1 : begin
        1.0f,1.0f, 0.0f,
        0.7f,0.5f,3.0f, // triangle 1 : begin
        1.0f, 0.5f, 0.0f,

        0.7f,0.0f,3.0f, // triangle 1 : begin
        1.0f,0.0f, 0.0f,
        0.7f,0.5f,3.0f, // triangle 1 : begin
        1.0f,0.0f, 0.0f,
        0.7f,0.5f,3.0f, // triangle 1 : begin
        1.0f, 0.5f, 0.0f, // triangle 1 : end
        
        -0.7f,0.5f,3.0f, // triangle 1 : begin
        -1.0f,1.0f, 0.0f,
        -0.7f,0.5f,3.0f, // triangle 1 : begin
        -1.0f,1.0f, 0.0f,
        -0.7f,0.5f,3.0f, // triangle 1 : begin
        -1.0f, 0.5f, 0.0f,
        
        -0.7f,0.0f,3.0f, // triangle 1 : begin
        -1.0f,0.0f, 0.0f,
        -0.7f,0.5f,3.0f, // triangle 1 : begin
        -1.0f,0.0f,0.0f, // triangle 1 : begin
        -0.7f,0.5f,3.0f,
        -1.0f, 0.5f,0.0f, // triangle 1 : end

        0.7f,0.5f,3.0f, // triangle 1 : begin
        0.7f,0.0f,3.0f, // triangle 1 : begin
        -0.7f,0.5f,3.0f,
        0.7f,0.0f,3.0f, // triangle 1 : begin
        -0.7f,0.5f,3.0f,
        -0.7f,0.0f,3.0f, // triangle 1 : begin

        0.0f,0.0f,-1.0f, // triangle 1 : begin
        1.0f,1.0f, 0.0f,
        -1.0f,1.0f, 0.0f,

         1.0f,1.0f, 0.0f,
        -1.0f,1.0f, 0.0f,
         0.7f,0.0f, 3.0f,
         -1.0f,1.0f, 0.0f,
         -0.7f,0.0f, 3.0f,
        0.7f,0.0f, 3.0f,

        // -1.0f,-1.0f,-1.0f,
        // -1.0f, 1.0f, 1.0f,
        // -1.0f,-1.0f, 1.0f,
        // 1.0f,-1.0f, 1.0f,
        // 1.0f, 1.0f, 1.0f,
        // 1.0f,-1.0f,-1.0f,
        // 1.0f, 1.0f,-1.0f,
        // 1.0f,-1.0f,-1.0f,
        // 1.0f, 1.0f, 1.0f,
        // 1.0f,-1.0f, 1.0f,
        // 1.0f, 1.0f, 1.0f,
        // 1.0f, 1.0f,-1.0f,
        // -1.0f, 1.0f,-1.0f,
        // 1.0f, 1.0f, 1.0f,
        // -1.0f, 1.0f,-1.0f,
        // -1.0f, 1.0f, 1.0f,
        // 1.0f, 1.0f, 1.0f ,
        // -1.0f, 1.0f, 1.0f,
        // 1.0f,-1.0f, 1.0f
    };
     GLfloat boatbase[] = {
        0.0f,0.3f,-1.0f, // triangle 1 : begin
        1.0f,0.3f, 0.0f,
        -1.0f,0.3f, 0.0f,

         1.0f,0.3f, 0.0f,
        -1.0f,0.3f, 0.0f,
         0.7f,0.3f, 3.0f,
         -1.0f,0.3f, 0.0f,
         -0.7f,0.3f, 3.0f,
        0.7f,0.3f, 3.0f,



    };
    GLfloat sail[] = {
        -0.1f,0.0f,-0.1f, // triangle 1 : begin
        0.1f,0.0f, -0.1f,
        -0.1f,0.0f, 0.1f,
        0.1f,0.0f, -0.1f,
        -0.1f,0.0f, 0.1f,
        0.1f,0.0f,0.1f,

        0.1f,4.0f,-0.1f, // triangle 1 : begin
        0.1f,4.0f, 0.1f,
        0.1f,0.0f, -0.1f,
        0.1f,4.0f, 0.1f,
        0.1f,0.0f, -0.1f,
        0.1f,0.0f, 0.1f,

        -0.1f,4.0f,-0.1f, // triangle 1 : begin
        -0.1f,4.0f, 0.1f,
        -0.1f,0.0f, -0.1f,
        -0.1f,4.0f, 0.1f,
        -0.1f,0.0f, -0.1f,
        -0.1f,0.0f, 0.1f,

        -0.1f,0.0f,0.1f,
        -0.1f,4.0f,0.1f,
        0.1f,0.0f,0.1f,
        0.1f,0.0f,0.1f,
        0.1f,4.0f,0.1f,        
        -0.1f,4.0f,0.1f,

        -0.1f,0.0f,-0.1f,
        -0.1f,4.0f,0.1f,
        0.1f,0.0f,-0.1f,
        0.1f,0.0f,-0.1f,
        0.1f,4.0f,-0.1f,        
        -0.1f,4.0f,-0.1f,

         -0.1f,4.0f,-0.1f, // triangle 1 : begin
        0.1f,4.0f, -0.1f,
        -0.1f,4.0f, 0.1f,
        0.1f,4.0f, -0.1f,
        -0.1f,4.0f, 0.1f,
        0.1f,4.0f,0.1f,

        -0.1f,1.4f,-0.0f,
        -0.1f,4.0f,-0.0f,
        -4.0f,1.4f,-0.0f,





        //  1.0f,0.0f, 0.0f,
        // -1.0f,0.0f, 0.0f,
        //  0.7f,0.0f, 2.0f,
        //  -1.0f,0.0f, 0.0f,
        //  -0.7f,0.0f, 2.0f,
        // 0.7f,0.0f, 2.0f,



    };
    float X=0.0f,Y=0.1;
    int j=0;
    GLfloat canon[361*18];
            for(int i=0;i<360;i++)
            {
                canon[j++]=X;canon[j++]=Y; canon[j++]=this->position.z-1.0f;
                float x1=X,y1=Y;
                X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
                Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
                canon[j++]=X; canon[j++]=Y; canon[j++]=0.0f;
                canon[j++]=x1;canon[j++]=y1; canon[j++]=this->position.z-1.0f-2.0f;
                canon[j++]=x1;canon[j++]=y1; canon[j++]=this->position.z-1.0f-2.0f;
                canon[j++]=X; canon[j++]=Y; canon[j++]=this->position.z-1.0f-2.0f;
                canon[j++]=X; canon[j++]=Y; canon[j++]=0.0f;

            }


    this->object = create3DObject(GL_TRIANGLES, 42, vertex_buffer_data, color, GL_FILL);
    this->base = create3DObject(GL_TRIANGLES, 9,  boatbase, {255,255,0}, GL_FILL);
    this->sail = create3DObject(GL_TRIANGLES, 39,  sail, {123,146,24}, GL_FILL);
    this->canon = create3DObject(GL_TRIANGLES, 6*360, canon, {165,42,42}, GL_FILL);

}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    draw3DObject(this->object);
    draw3DObject(this->base);
    draw3DObject(this->sail);
    glDisable(GL_BLEND);

    // translate = glm::translate (glm::vec3(this->position.x,this->position.y+=0.5f,this->position.z-0.8f));    // glTranslatef
    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // draw3DObject(this->canon);
    // translate = glm::translate (this->position); 
    // Canon(0,-0.8,COLOR_GREEN).draw(VP);

}
void Ball::canondraw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->canon_position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate1    = glm::rotate((float) (this->canonrotation * M_PI / 180.0f), glm::vec3(1, 0, 0));

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * rotate1);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 1);

    // Matrices.model *= (translate * rotate);
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    draw3DObject(this->canon);
    glDisable(GL_BLEND);

    // translate = glm::translate (this->position); 
    // Canon(0,-0.8,COLOR_GREEN).draw(VP);

}


void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick(Fireball* fireball, Man* man) {

    this->time+=1;
    if(this->initial)
    {
        this->speed=this->initial-0.07*this->time;
    }

    if(this->position.y + this->initial*this->time -0.5*0.07*this->time*this->time > -0.1f)
    {
        this->position.y  = this->position.y + this->initial*this->time -0.5*0.07*this->time*this->time;
        this->canon_position.y  = this->canon_position.y + this->initial*this->time -0.5*0.07*this->time*this->time;
        this->position.z-=0.6*cos(this->rotation*((3.14)/180.0));
        this->position.x+=0.6*sin(-this->rotation*((3.14)/180.0));
        this->canon_position.z-=0.6*cos(this->rotation*((3.14)/180.0));
        this->canon_position.x+=0.6*sin(-this->rotation*((3.14)/180.0));
        (*man).position.z-=0.6*cos(this->rotation*((3.14)/180.0));
        (*man).position.x+=0.6*sin(-this->rotation*((3.14)/180.0));
        (*man).position.y+=this->initial*this->time -0.5*0.07*this->time*this->time;
        (*fireball).position.x=this->canon_position.x+3.0f*sin(-this->rotation*((3.14)/180.0));
        (*fireball).position.z=this->canon_position.z-3.0f*cos(this->rotation*((3.14)/180.0));

    }
    else
    {
        this->speed=0;
        this->initial=0;
        this->time=0;
    }
    // this->rotation += speed;
    // cout<<this->rotation<<endl;
    // speed=-speed;
    // theta+=0.01;
    // this->position.z -= 0.01;
}

