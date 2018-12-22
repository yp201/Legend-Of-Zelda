#include "scene.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Scene::Scene(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0 ;
    // speed =   1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        // -4.0f,200.0f,0.0f, // triangle 1 : begin
        // -4.0f,-400.0f, 0.0f,
        // 4.0f, -400.0f, 0.0f, // triangle 1 : end
        // 4.0f,200.0f,0.0f, // triangle 1 : begin
        // -4.0f,200.0f, 0.0f,
        // 4.0f, -400.0f, 0.0f, // triangle 1 : end
        -800.0f,0.0f,1000.0f, // triangle 1 : begin
        -800.0f,0.0f,-1000.0f, 
        800.0f,0.0f, -1000.0f,  // triangle 1 : end
        800.0f,0.0f,1000.0f, // triangle 1 : begin
        -800.0f,0.0f,1000.0f, 
        800.0f,0.0f, -1000.0f,  // triangle 1 : end
        
        // 4.0f,3.0f, 0.0f,
        // 4.0f,4.0f, 0.0f,
        //  -4.0f,3.0f, 0.0f,
        //  -4.0f,4.0f, 0.0f,
        //  4.0f,4.0f, 0.0f,
        // -4.0f,3.0f, 0.0f,
        // 1.0f,-1.0f, 1.0f,
        // -1.0f,-1.0f,-1.0f,
        // 1.0f,-1.0f,-1.0f,
        // 1.0f, 1.0f,-1.0f,
        // 1.0f,-1.0f,-1.0f,
        // -1.0f,-1.0f,-1.0f,
        // -1.0f,-1.0f,-1.0f,
        // -1.0f, 1.0f, 1.0f,
        // -1.0f, 1.0f,-1.0f,
        // 1.0f,-1.0f, 1.0f,
        // -1.0f,-1.0f, 1.0f,
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
    static const GLfloat colorarray[] = {
        10/255.0f,150/255.0f,255/255.0f,
        20/255.0f,150/255.0f,255/255.0f,
        50/255.0f,150/255.0f,255/255.0f,
        80/255.0f,150/255.0f,255/255.0f,
        100/255.0f,150/255.0f,255/255.0f,
        130/255.0f,150/255.0f,255/255.0f
    };  
    // static const GLfloat vertex_buffer_data[] = {
    //     0.0f,0.0f,-1.0f, // triangle 1 : begin
    //     1.0f,0.0f, 0.0f,
    //     1.0f, 0.5f, 0.0f, // triangle 1 : end
    //     0.0f,0.0f,-1.0f, // triangle 1 : begin
    //     1.0f, 0.5f, 0.0f, // triangle 1 : end
    //     0.0f, 0.5f,-1.0f, // triangle 2 : end
        
    //     0.0f,0.0f,-1.0f, // triangle 1 : begin
    //     -1.0f,0.0f, 0.0f,
    //     -1.0f, 0.5f, 0.0f, // triangle 1 : end
    //     0.0f,0.0f,-1.0f, // triangle 1 : begin
    //     -1.0f, 0.5f, 0.0f, // triangle 1 : end
    //     0.0f, 0.5f,-1.0f, // triangle 2 : end
        

    //     1.0f,0.0f,2.0f, // triangle 1 : begin
    //     1.0f,0.0f, 0.0f,
    //     1.0f,0.5f,2.0f, // triangle 1 : begin
    //     1.0f,0.0f, 0.0f,
    //     1.0f,0.5f,2.0f, // triangle 1 : begin
    //     1.0f, 0.5f, 0.0f, // triangle 1 : end
        
    //     -1.0f,0.0f,2.0f, // triangle 1 : begin
    //     -1.0f,0.0f, 0.0f,
    //     -1.0f,0.5f,2.0f, // triangle 1 : begin
    //     -1.0f,0.0f,0.0f, // triangle 1 : begin
    //     -1.0f,0.5f,2.0f,
    //     -1.0f, 0.5f,0.0f, // triangle 1 : end

    //     1.0f,0.5f,2.0f, // triangle 1 : begin
    //     1.0f,0.0f,2.0f, // triangle 1 : begin
    //     -1.0f,0.5f,2.0f,
    //     1.0f,0.0f,2.0f, // triangle 1 : begin
    //     -1.0f,0.5f,2.0f,
    //     -1.0f,0.0f,2.0f, // triangle 1 : begin

    //     0.0f,0.0f,-1.0f, // triangle 1 : begin
    //     1.0f,0.0f, 0.0f,
    //     -1.0f,0.0f, 0.0f,

    //      1.0f,0.0f, 0.0f,
    //     -1.0f,0.0f, 0.0f,
    //      1.0f,0.0f, 2.0f,
    //      -1.0f,0.0f, 0.0f,
    //      -1.0f,0.0f, 2.0f,
    //     1.0f,0.0f, 2.0f,

    //     // -1.0f,-1.0f,-1.0f,
    //     // -1.0f, 1.0f, 1.0f,
    //     // -1.0f,-1.0f, 1.0f,
    //     // 1.0f,-1.0f, 1.0f,
    //     // 1.0f, 1.0f, 1.0f,
    //     // 1.0f,-1.0f,-1.0f,
    //     // 1.0f, 1.0f,-1.0f,
    //     // 1.0f,-1.0f,-1.0f,
    //     // 1.0f, 1.0f, 1.0f,
    //     // 1.0f,-1.0f, 1.0f,
    //     // 1.0f, 1.0f, 1.0f,
    //     // 1.0f, 1.0f,-1.0f,
    //     // -1.0f, 1.0f,-1.0f,
    //     // 1.0f, 1.0f, 1.0f,
    //     // -1.0f, 1.0f,-1.0f,
    //     // -1.0f, 1.0f, 1.0f,
    //     // 1.0f, 1.0f, 1.0f ,
    //     // -1.0f, 1.0f, 1.0f,
    //     // 1.0f,-1.0f, 1.0f
    // };


    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, {60,150,255}, GL_FILL);
    // this->base = create3DObject(GL_TRIANGLES, 6,  boatbase, {0,0,180}, GL_FILL);

}

void Scene::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(Matrices.Transparency, 0.5);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    draw3DObject(this->object);
    glDisable(GL_BLEND);


    // draw3DObject(this->base);

}


