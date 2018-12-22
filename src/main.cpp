#include "main.h"
#include "timer.h"
#include "ball.h"
#include "scene.h"
#include "barrel.h" 
#include "boss.h" 
#include "health.h"
#include "man.h"
#include "obstacles.h" 
#include "residue.h"
#include "fireball.h"
#include "monster.h"
#include "island.h"
#include "score.h"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1;
Boss boss;
Scene scene;
Fireball fireball;
Island island;
Health healths[5];
Fireball fireballs[5];
Barrel barrels[10];
Score score1,score2;

Residue residues[1000];
Man man;
int camera=0;
int boosttime=0;
int pid;
float windangle=60;
int windofftime=0;
int windtime=0;
Obstacle obstacles[50];
Monster monsters[5];
bool booster=false;
int pos=10;
bool perspective=true;
// int fire=0;
float currenty=0;
float currentz=0;
float helicoptery=20;
int score=0;
int direction=1;
int count1=0;
int prevcamera=0;
int health=99;
double xpos1,ypos1;
int left,right=0;
float r=10.0f;
int R=0;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
float theta=0;
Timer t60(1.0 / 60);
extern bool cannon_keyboard_input, drag_pan;
extern double drag_oldx, drag_oldy;



/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye1 (0,0,3);

    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target1 (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up1 (0, 1, 0);
    Matrices.view1 = glm::lookAt( eye1, target1, up1 ); // Rotating Camera for 3D
    glm::mat4 TVP=Matrices.projection1 * Matrices.view1;
    if(perspective)
    {

    switch (camera)
    {
        
        case 0:
        {
            glm::vec3 eye (ball1.position.x+ 8.0f*sin(ball1.rotation*((3.14)/180.0)), 4 , (ball1.position.z + 10*cos(ball1.rotation*((3.14)/180.0))));
            glm::vec3 target (ball1.position.x+ 4*sin(-ball1.rotation*((3.14)/180.0)), 0.5f , ball1.position.z-2.0f*cos(ball1.rotation*((3.14)/180.0)));
            glm::vec3 up (0, 1,  0 );
            Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
            break;
        }
        case 1:
        {
            glm::vec3 eye (0, 20 , 10);
            glm::vec3 target (ball1.position.x, ball1.position.y , ball1.position.z);
            glm::vec3 up (0, 1, 0);
            Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
            break;
        }
        case 2:
        {
            glm::vec3 eye (ball1.position.x+1*sin(-ball1.rotation*((3.14)/180.0)), ball1.position.y+1.0f, ball1.position.z-1.0f*cos(ball1.rotation*((3.14)/180.0)));
            glm::vec3 target (ball1.position.x+ 4*sin(-ball1.rotation*((3.14)/180.0)), 0.5f , ball1.position.z-3.0f*cos(ball1.rotation*((3.14)/180.0)));
            glm::vec3 up (0,1,0);
            Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
            break;
        }
        case 3: 
        {
            glm::vec3 eye (ball1.position.x, 20 , ball1.position.z);
            glm::vec3 target (ball1.position.x, 0.5f , ball1.position.z);
            glm::vec3 up (0, 0, -1);
            Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
            break;

        }
        case 4:
        {
            glm::vec3 eye (man.position.x+ 2.0f*sin(man.rotation*((3.14)/180.0)), 2 , (man.position.z + 2*cos(man.rotation*((3.14)/180.0))));
            glm::vec3 target (man.position.x+ 2*sin(-man.rotation*((3.14)/180.0)), 0.5f , man.position.z-1.0f*cos(man.rotation*((3.14)/180.0)));
            glm::vec3 up (0, 1,  0 );
            Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
            break;
  
        }
        case 5:
        {
           // float theta 
            glm::vec3 eye (r*sin(camera_rotation_angle), helicoptery , r*cos(camera_rotation_angle));
            glm::vec3 target (ball1.position.x, ball1.position.y , ball1.position.z);
            glm::vec3 up (0, 1, 0);
            Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
            break;
        }

    }
    }
    else
    {
        glm::vec3 eye1 (0,0,3);

    // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target1 (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up1 (0, 1, 0);
        Matrices.view1 = glm::lookAt( eye1, target1, up1 ); // Rotating Camera for 3D
        glm::mat4 VP=Matrices.projection1 * Matrices.view1;

    }
    // Compute Camera matrix (view)
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    man.drawbody(VP);
    for(int i=0;i<5;i++)
    {
        if(monsters[i].visible)
        {
            monsters[i].draw(VP);
            fireballs[i].draw(VP);
        }
        if(healths[i].visible)
            healths[i].draw(VP);
    }   
    for(int i=0;i<R;i++)
    {
        if(residues[i].visible)
            residues[i].draw(VP);
    }
    for(int i=0;i<50;i++)
    {
        if(obstacles[i].visible)
            obstacles[i].draw(VP);
    }
    for(int i=0;i<10;i++)
    {
        if(barrels[i].visible)
            barrels[i].draw(VP);
    }
    if(boss.visible)
        boss.draw(VP);
    
    island.draw(VP);
    if(ball1.visible)
    {
        ball1.draw( VP);
        ball1.canondraw(VP);
    }
    if(fireball.visible)
    {
        fireball.draw(VP);
    }
      score1.draw(TVP,health%10);
      score2.draw(TVP,(health/10)%10);

    scene.draw(VP);

}
    
void tick_input(GLFWwindow *window) {
    
    int persp= glfwGetKey(window,GLFW_KEY_E);
    int ortho= glfwGetKey(window,GLFW_KEY_O);
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int up  = glfwGetKey(window, GLFW_KEY_I);
    int down  = glfwGetKey(window, GLFW_KEY_K);
    int manforward=glfwGetKey(window, GLFW_KEY_W);
    int manleft=glfwGetKey(window, GLFW_KEY_A);
    int manright=glfwGetKey(window, GLFW_KEY_D);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int fire = glfwGetKey(window, GLFW_KEY_F);
    int forward = glfwGetKey(window, GLFW_KEY_UP );
    int boat_view=glfwGetKey(window, GLFW_KEY_B );
    int heli_view=glfwGetKey(window, GLFW_KEY_H);
    int tower_view=glfwGetKey(window, GLFW_KEY_T);
    int follow_cam_view=glfwGetKey(window, GLFW_KEY_V);
    int top_view=glfwGetKey(window, GLFW_KEY_P);
    int man_view=glfwGetKey(window,GLFW_KEY_M);
    int island_view=glfwGetKey(window,GLFW_KEY_B);
    double x1;
    double y1;
    glfwGetCursorPos(window, &x1, &y1);
    if (drag_pan) {
        if (drag_oldx == -1 || drag_oldy == -1) {
            glfwGetCursorPos(window, &drag_oldx, &drag_oldy);
        } else {
            double newx, newy;
            glfwGetCursorPos(window, &newx, &newy);
            int width, height;
            glfwGetWindowSize(window, &width, &height);

            // ball.position.x += 8 * (newx - drag_oldx) / (width * screen_zoom);
            if(8 * (newx - drag_oldx) / (width * screen_zoom)<0)
              camera_rotation_angle-=0.1;
            else if(8 * (newx - drag_oldx) / (width * screen_zoom)>0)
                camera_rotation_angle+=0.1;
            if(8 * (newy - drag_oldy) / (height * screen_zoom)<0)
                r-=0.3;

            drag_oldx = newx;
            drag_oldy = newy;
            // reset_screen(0.0);
    }
}
    if(x1-xpos1>0)
    {
        xpos1=x1;
        right=1;
    }
    else if(x1-xpos1<0)
    {
        xpos1=x1;
        left=1;
    }
    if(y1-ypos1>0)
    {   
        ypos1=y1; 
        up=1;
    }
    else if(y1-ypos1<0)
    {
        ypos1=y1;
        down=1;
    }

    if (right) {
        ball1.rotation-=2;
        man.rotation-=2;
        if(!fireball.fired)
        {
            fireball.position.x=ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0));
            fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0));
        }
            man.position.x=ball1.position.x - 0.5*sin(-ball1.rotation*((3.14)/180.0));
            man.position.z=ball1.position.z + 0.5*cos(ball1.rotation*((3.14)/180.0));
        right=0;
        // Do something
    }
    if (left) {
        ball1.rotation+=2;
        man.rotation+=2;
        if(!fireball.fired)
        {

            fireball.position.x=ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0));
            fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0));
        }
            man.position.x=ball1.position.x - 0.5*sin(-ball1.rotation*((3.14)/180.0));
            man.position.z=ball1.position.z + 0.5*cos(ball1.rotation*((3.14)/180.0));
        left=0;
        // cout<<ball1.rotation<<endl;
        // Do something
    }
    if(persp)
    {
        perspective=true;
    }
    if(ortho)
    {
        perspective=false;
    }
    if (up && ball1.canonrotation<=8) {
        ball1.canonrotation+=2;
        if(!fireball.fired)
        {
            fireball.position.y=ball1.canon_position.y+3.0f*sin(ball1.canonrotation*((3.14)/180.0));
            fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.canonrotation*((3.14)/180.0));
        }
        up=0;
        // ball1.position.y+=0.1;
        // ball1.canon_position.y+=0.1;

        // Do something
    }
    if (down && ball1.canonrotation>0) {
        ball1.canonrotation-=2;
        if(!fireball.fired)
        {

            fireball.position.y=ball1.canon_position.y+3.0f*sin(ball1.canonrotation*((3.14)/180.0));
            fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.canonrotation*((3.14)/180.0));
        }
        down=0;
        // ball1.position.y+=0.1;
        // ball1.canon_position.y+=0.1;

        // Do something
    }
    if(boat_view)
    {
        camera=2;
        prevcamera=2;
    }
    if(tower_view)
    {
        camera=1;
        prevcamera=1;
    }
    if (follow_cam_view)
    {
        camera=0;
        prevcamera=0;
    }
    if(top_view)
    {
        camera=3;
        prevcamera=3;
    }
    if(man_view)
    {
        camera=4;
        prevcamera=4;
    }
    if(heli_view)
    {
        camera=5;
        prevcamera=5;
    }
    if(island_view && man.onboat==false)
    {
        fireball.visible=true;        
    }

    if (manforward)
    {
        float speedforward=0.04;
        man.handangle+=direction;
        man.legangle+=direction;
        if(man.handangle>30.f)
        {
            direction=-1;
        }
        if(man.handangle<-20.0f)
        {
            direction=1;
        }
        man.position.z-=speedforward*cos(man.rotation*((3.14)/180.0));
        man.position.x+=speedforward*sin(-man.rotation*((3.14)/180.0));
        if(!man.onboat)
        {
            ball1.position.z-=speedforward*cos(man.rotation*((3.14)/180.0));
            ball1.position.x+=speedforward*sin(-man.rotation*((3.14)/180.0));
            ball1.canon_position.z-=speedforward*cos(man.rotation*((3.14)/180.0));
            ball1.canon_position.x+=speedforward*sin(-man.rotation*((3.14)/180.0));
            if(!fireball.fired)
            {
                fireball.position.z=ball1.canon_position.z-3.0f*cos(man.rotation*((3.14)/180.0));
                fireball.position.x=ball1.canon_position.x+3.0f*sin(-man.rotation*((3.14)/180.0));
            }
            cout<<ball1.position.z<<endl;
        }
    }
    if (manleft)
    {
        man.rotation+=2;
        if(!man.onboat)
            ball1.rotation+=2;

    }
    if (manright)
    {
        man.rotation-=2;
        if(!man.onboat)
            ball1.rotation-=2;

    }

    if (forward && man.onboat){
        

        float speedforward=0.2;
        if(booster)
            speedforward=0.5f;

        ball1.position.z-=speedforward*cos(ball1.rotation*((3.14)/180.0));
        ball1.position.x+=speedforward*sin(-ball1.rotation*((3.14)/180.0));
        ball1.canon_position.z-=speedforward*cos(ball1.rotation*((3.14)/180.0));
        ball1.canon_position.x+=speedforward*sin(-ball1.rotation*((3.14)/180.0));
        if(!fireball.fired)
        {
            
            fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0));
            fireball.position.x=ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0));
        // canon.position.z-=0.1;
        }
        man.position.x=ball1.position.x - 0.5*sin(-ball1.rotation*((3.14)/180.0));  
        man.position.z=ball1.position.z + 0.5*cos(ball1.rotation*((3.14)/180.0));
    }
    if(fire)
    {
        fireball.initial=0.5;
        cout<<ball1.canonrotation<<endl;
        fireball.speedy=fireball.initial*sin(ball1.canonrotation*M_PI/180.0f);
        fireball.speedx=fireball.initial*cos(ball1.canonrotation*M_PI/180.0f);
        fireball.fired=true;
        fire=0;

    }
    if (space && ball1.position.y<=0.0f )
    {
        
        ball1.initial=0.3f;
        cout<<"jump"<<endl;

    }


}
void tick_elements() {
    // canon.position.x=ball1.position.x;
    // canon.position.z=ball1.position.z-1.0;
    // canon.position.y=ball1.position.y+0.5f;
    boosttime++;
    if(fireball.fired)
    {
        fireball.visible=true;
    }
    if(!man.onboat)
    {
        if(fireball.fired && fireball.collision(30,0.2,-200.0f,0,0,0))
        {
            island.visible=false;
            island.visible1=true;
        }
    }
    // cout<<"HEALTH = "<<health<<endl;
    if(currentz==ball1.position.z)
    {
        
        // residues[R]=Residue(ball1.position.x-3.0f*sin(ball1.rotation*((3.14)/180.0)),0,ball1.position.z-3.0f*cos(ball1.rotation*((3.14)/180.0)),COLOR_RED);
        residues[R]=Residue(ball1.position.x,0.1,ball1.position.z-4.0f,COLOR_RED);

        R=(R+1)%999;
        currenty=0;
    }
    else
    {
        currentz=ball1.position.z;
        currenty=0;
        // R=0;
    }
    for(int i=0;i<R;i++)
    {
        residues[i].tick();
    }
    if(!windofftime)
    {
        windtime++;
        if(windtime==480)
        {   
            windofftime=720;
            windangle=(rand()%121-60);
        }
    }   
    if(windtime==480)
    {
        if(ball1.rotation>windangle &&man.onboat)
        {
            ball1.rotation=ball1.rotation-0.1;
            man.rotation-=0.1;
        }  
        else if(ball1.rotation<windangle && man.onboat)
        {
            ball1.rotation+=0.1;
            man.rotation+=0.1;
        }        

        if(!fireball.fired)
        {
            fireball.position.x=ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0));
            fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0));
        }
            man.position.x=ball1.position.x - 0.5*sin(-ball1.rotation*((3.14)/180.0));
            man.position.z=ball1.position.z + 0.5*cos(ball1.rotation*((3.14)/180.0));
        windofftime--;
        if(windofftime==0)
            windtime=0;
    }
    if(boosttime==600)
    {
        booster=false;
        boosttime=0;
    }
    if(length(glm::vec3(ball1.position.x,ball1.position.y,ball1.position.z)-glm::vec3(30,0.2,-200.0f))<=50.5 )
    {
        ball1.visible=false;
        if (!fireball.fired)
            fireball.visible=false;
        if(man.onboat)
        {
            man.position.x=man.position.x + 2*sin(-ball1.rotation*((3.14)/180.0));  
            man.position.z=man.position.z - 2*cos(ball1.rotation*((3.14)/180.0));
            
        }
        if(length(glm::vec3(man.position.x,man.position.y,man.position.z)-island.position)<=1.5 )
        {
            health=99;
            island.visible1=false;
        }
        man.onboat=false;
        prevcamera=0;
        camera=4;
    }
    else
    {
        ball1.visible=true;
        fireball.visible=true;  
        man.onboat=true;
        camera=prevcamera;
    }
    ball1.tick(&fireball,&man);
    if(fireball.fired)
    {
        if(fireball.fire(ball1.rotation))
        {
            // cout<<"here"<<endl;
            fireball.position.x= ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0));
            fireball.position.y= ball1.canon_position.y;
            fireball.position.z= ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0));    
        }
        for(int i=0;i<50;i++)
        {
            if(obstacles[i].visible && fireball.collision(obstacles[i].position.x,obstacles[i].position.y,obstacles[i].position.z,0.0,0.0,0.0))
            {
                obstacles[i].visible=false;
            }
        
        }
        for(int i=0;i<5;i++)
        {
            if(monsters[i].visible && fireball.collision(monsters[i].position.x,monsters[i].position.y,monsters[i].position.z,ball1.position.x,ball1.position.y,ball1.position.z))
            {
                monsters[i].visible=false;
                count1++;
                cout<<count1<<endl;
                if(count1==5)
                {
                    boss.visible=true;
                }
            }
        }

    }
    else
        fireball.position.y=ball1.canon_position.y+3.0f*sin(ball1.canonrotation*((3.14)/180.0));
    
    if(boss.visible && fireball.collision(boss.position.x,boss.position.y,boss.position.z,0,0,0))
    {
        boss.health+=-1;
        if(boss.health==0)
        {
            boss.visible=false;
        }
    }
    boss.tick();

    theta+=0.1;
    if(ball1.position.y<=0.0f && ball1.speed==0)
    {
        ball1.position.y=-0.2f+0.05*sin(theta);
        ball1.canon_position.y=0.2+0.05*sin(theta);
        if(man.onboat)
            man.position.y=0.6f+0.05*sin(theta);
   
    }
    // cout<<ball1.position.z<<" "<<ball1.position.x<<endl;
    for(int i=0;i<5;i++)
    {       
        healths[i].tick();
        monsters[i].position.y=1.8f+0.05*sin(theta*2);
        // if(!fireballs[i].fired)
        //     fireballs[i].position.y=0.3f+0.05*sin(theta*2);
        if(!fireballs[i].fired)
        {
            fireballs[i].fired=true;
        }
        if(fireballs[i].fired)
        {
            fireballs[i].position.y-=0.005;
            fireballs[i].fired=true;
            if(fireballs[i].position.y<-0.2)
            {
                fireballs[i].fired=false;
                fireballs[i].position.y=0.3f;
                // x,0.3f,z+2.0f
                fireballs[i].position.x=monsters[i].position.x;
                fireballs[i].position.y=monsters[i].position.y-1.5f;
                fireballs[i].position.z=monsters[i].position.z+2.0f;
            }
            if(ball1.position.z>fireballs[i].position.z)
            {
                fireballs[i].position.z+=0.1;
            }   
            if(ball1.position.z<fireballs[i].position.z)
            {
                fireballs[i].position.z-=0.1;
            }   
            if(ball1.position.x<fireballs[i].position.x)
            {
                fireballs[i].position.x-=0.2;
            }   
             if(ball1.position.x>fireballs[i].position.x)
            {
                fireballs[i].position.x+=0.2;
            }  

            if(fireballs[i].fired && monsters[i].visible && fireballs[i].collision(ball1.position.x,ball1.position.y,ball1.position.z,0,0,99))
            {
                fireballs[i].fired=false;
                health-=5;
                fireballs[i].position.x=monsters[i].position.x;
                fireballs[i].position.y=monsters[i].position.y-1.5f;
                fireballs[i].position.z=monsters[i].position.z+2.0f;

            } 
        }
        if (ball1.position.z<monsters[i].position.z)
        {
            monsters[i].position.z-=monsters[i].speed;
            if(!fireballs[i].fired)
                fireballs[i].position.z-=monsters[i].speed;
        }
        if(ball1.position.z>monsters[i].position.z)
        {
            monsters[i].position.z+=monsters[i].speed;
            if(!fireballs[i].fired)
                fireballs[i].position.z+=monsters[i].speed;
        }
        if(fireballs[i].fired)
        {
            fireballs[i].visible=true;
        }   
        if(healths[i].visible)
        {
            detect_collision_healths(i);
        }

    }
        if(ball1.position.z>boss.position.z)
        {
            boss.position.z+=0.07;
        }   
        if(ball1.position.z<boss.position.z)
        {
            boss.position.z-=0.07;
        }   
        if(ball1.position.x<boss.position.x)
        {
            boss.position.x-=0.07;
        }   
        if(ball1.position.x>boss.position.x)
        {
            boss.position.x+=0.07;
        }   
    // fireball.position.y=0.5+0.05*sin(theta);
    for(int i=0;i<50;i++)
    {
        obstacles[i].position.y=-0.2f+0.05*sin(theta*1.2);
        if(obstacles[i].visible)
        {
            if(detect_collision_obstacles(i));
                // cout<<"collison "<<i<<endl;
        }
    }

    for(int i=0;i<10;i++)
    {
        barrels[i].position.y=0.4f+0.05*sin(theta*1.2);
        if(barrels[i].visible)
        {
            detect_collision_barrels(i);
        }
       
    }
    for(int i=0;i<5;i++)
    {
        if(monsters[i].visible)
        {
            (detect_collision_monsters(i));
        }
       
    }

    if(boss.visible && detect_collision_boss(0))
    {
        cout<<"------YOU DIED---------"<<endl;
        quit(window);
    }
    if(health<=0)
    {
        cout<<"------YOU DIED---------"<<endl;
        quit(window);
    }


    // cout<<health<<endl;
    // canon.position.y=0.2*sin(theta);
    // canon.rotation=-ball1.rotation;

    // this->position.z -= 0.01;
    // scene.pos-osition.z -=0.01;
    // pos-=0.001; camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    island= Island(30,0.2,-200.0f,COLOR_RED);
    ball1 = Ball(0,-0.2f,0.0f, COLOR_RED);
    score2=Score(-3.6,3.0);
    score1=Score(-3.0,3.0);
    fireball=Fireball(ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0)),ball1.canon_position.y,ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0)),ball1.canon_position.x,ball1.canon_position.y,ball1.canon_position.z, 0.2,COLOR_GREEN);
    man = Man(-0.0f,0.6f,0.5f,0.0f, COLOR_RED);
    scene= Scene(0,0,COLOR_GREEN);
    boss= Boss(2,0.5f,-10.0f,0.0f,COLOR_RED);
    for(int i=0;i<5;i++)
    {
        float x=(rand()%80)-40.0f;
        float z=-(rand() %100);
        double speed=(10+rand()%50)/1000.0;
        monsters[i]=Monster(x,1.8f,z,speed,COLOR_GREEN);
        fireballs[i]=Fireball(x,0.3f,z+2.0f,x,0.3f,z+2.0f,0.2,COLOR_GREEN);
    }
    for(int i=0;i<5;i++)
    {
        float x=(rand()%80)-40.0f;
        float z=-(rand() %100);
        healths[i]=Health(x,2.2f,z,COLOR_GREEN);
    }

    for(int i=0;i<50;i++)
    {
        float x=(rand()%80)-40.0f;
        float z=-(rand() %100);
        float size=(rand() %20)/10.0;
        float height=(rand() %1)/10.0;
        float top=(rand() %31)/10.0;
        float deviaiton=-(rand() %15)/10.0;
        obstacles[i]=Obstacle(x,-0.2f,z,size,height,top,deviaiton,COLOR_GREEN);
    }
    for(int i=0;i<10;i++)
    {
        float x=(rand()%80)-40.0f;
        float z=-(rand() %100);
        barrels[i]=Barrel(x,0.4f,z,COLOR_GREEN);
    }

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

    Matrices.Transparency = glGetUniformLocation(programID, "TRS");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 700;
    int height = 400;

    window = initGLFW(width, height);

    initGL (window, width, height);
    double x2;
    double y2;
    glfwGetCursorPos(window, &x2, &y2);
    xpos1=x2,ypos1=y2;

    /* Draw in loop */
    play_boy();
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision_obstacles(int i) {
    if(ball1.position.y<=(obstacles[i].size+obstacles[i].top))
    {
        if(obstacles[i].position.x+2.0f>=ball1.position.x && ball1.position.x>=obstacles[i].position.x-2.0f)
        {
            if(abs(ball1.position.z-obstacles[i].position.z)<2.5f)
            {
                // obstacles[i].visible=false;
                health=health-5;
                float speedforward=-6.0f;

                    ball1.position.z-=speedforward*cos(ball1.rotation*((3.14)/180.0));
                    ball1.position.x+=speedforward*sin(-ball1.rotation*((3.14)/180.0));
                    ball1.canon_position.z-=speedforward*cos(ball1.rotation*((3.14)/180.0));
                    ball1.canon_position.x+=speedforward*sin(-ball1.rotation*((3.14)/180.0));
                    if(!fireball.fired)
                    {
                        
                        fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0));
                        fireball.position.x=ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0));
                    // canon.position.z-=0.1;
                    }
                    man.position.x=ball1.position.x - 0.5*sin(-ball1.rotation*((3.14)/180.0));  
                    man.position.z=ball1.position.z + 0.5*cos(ball1.rotation*((3.14)/180.0));
                return true;
            }   

            else 
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
bool detect_collision_barrels(int i) {
    if(ball1.position.y<=(1.6f))
    {
        if(barrels[i].position.x+1.2f>=ball1.position.x && ball1.position.x>=barrels[i].position.x-1.2f)
        {
            if(abs(ball1.position.z-barrels[i].position.z)<2.0f)
            {
                cout<<ball1.speed<<endl;
                if(ball1.speed<0.4)
                {
                    barrels[i].visible=false;
                    booster=true;
                    float speedforward=-6.0f;
                    // cout<<"gift "<<i<<endl;
                }
                else
                {
                    // barrels[i].visible=false;
                    // health=health-5;

                    // ball1.position.z-=speedforward*cos(ball1.rotation*((3.14)/180.0));
                    // ball1.position.x+=speedforward*sin(-ball1.rotation*((3.14)/180.0));
                    // ball1.canon_position.z-=speedforward*cos(ball1.rotation*((3.14)/180.0));
                    // ball1.canon_position.x+=speedforward*sin(-ball1.rotation*((3.14)/180.0));
                    // if(!fireball.fired)
                    // {
                        
                    //     fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0));
                    //     fireball.position.x=ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0));
                    // // canon.position.z-=0.1;
                    // }
                    // man.position.x=ball1.position.x - 0.5*sin(-ball1.rotation*((3.14)/180.0));  
                    // man.position.z=ball1.position.z + 0.5*cos(ball1.rotation*((3.14)/180.0));
                    // cout<<"monsters  "<<i<<endl;

                }
                return true;
            }   

            else 
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
bool detect_collision_healths(int i) {
    if(ball1.position.y<=4.0f && ball1.position.y>=1.8f)
    {
        if(healths[i].position.x+1.0f>=ball1.position.x && ball1.position.x>=healths[i].position.x-1.0f)
        {
            if(abs(ball1.position.z-healths[i].position.z)<2.0f)
            {
                if(ball1.speed<0)
                {
                    healths[i].visible=false;
                    health+=5;
                    // cout<<"gift "<<i<<endl;
                }
                else
                {
                    healths[i].visible=false;
                }
                return true;
            }   

            else 
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
bool detect_collision_monsters(int i) {
    if(ball1.position.y<=2.5f && ball1.position.y>=-2.5f)
    {
        if(monsters[i].position.x+3.0f>=ball1.position.x && ball1.position.x>=monsters[i].position.x-3.0f)
        {
            if(abs(ball1.position.z-monsters[i].position.z)<2.0f)
            {
                    // monsters[i].visible=false;
                    health-=30;
                    // float speedforward=-4.0f;

                    // ball1.position.z-=speedforward*cos(ball1.rotation*((3.14)/180.0));
                    // ball1.position.x+=speedforward*sin(-ball1.rotation*((3.14)/180.0));
                    // ball1.canon_position.z-=speedforward*cos(ball1.rotation*((3.14)/180.0));
                    // ball1.canon_position.x+=speedforward*sin(-ball1.rotation*((3.14)/180.0));
                    // if(!fireball.fired)
                    // {
                        
                    //     fireball.position.z=ball1.canon_position.z-3.0f*cos(ball1.rotation*((3.14)/180.0));
                    //     fireball.position.x=ball1.canon_position.x+3.0f*sin(-ball1.rotation*((3.14)/180.0));
                    // // canon.position.z-=0.1;
                    // }
                    // man.position.x=ball1.position.x - 0.5*sin(-ball1.rotation*((3.14)/180.0));  
                    // man.position.z=ball1.position.z + 0.5*cos(ball1.rotation*((3.14)/180.0));
                    // cout<<"monsters  "<<i<<endl;
                return true;
            }   

            else 
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool detect_collision_boss(int i) {
    
    if(length(glm::vec3(ball1.position.x,ball1.position.y,ball1.position.z)-glm::vec3(boss.position.x,boss.position.y,boss.position.z))<3.0)
    {
        health=-100;
        // cout<<died<<endl;
        return true;
    }
    else 
        return false;

}

void play_boy()
{
    if((pid = fork()) == 0) {
        audio_play();
    }
}

// void mouseButton(GLFWwindow *window, int button, int action, int mods) {
//     switch (button) {
//     case GLFW_MOUSE_BUTTON_LEFT:
//         if (action == GLFW_PRESS) {
//             old_cki = cannon_keyboard_input;
//             drag_pan = true;
//             cannon_keyboard_input = true;
//             if (drag_pan) {
//             if (drag_oldx == -1 || drag_oldy == -1) {
//                 glfwGetCursorPos(window, &drag_oldx, &drag_oldy);
//             } 
//                 double newx, newy;
//                 glfwGetCursorPos(window, &newx, &newy);
//                 int width, height;
//                 glfwGetWindowSize(window, &width, &height);
//                 cout<<newx<<endl;
//                 cout<<drag_oldx<<endl;
//                 cout<<"--"<<endl;
//                 // ball.position.x += 8 * (newx - drag_oldx) / (width * screen_zoom);
//                 if(8 * (newx - drag_oldx) <0)
//                 {
//                     camera_rotation_angle+=0.5;
//                     cout<<"rotation"<<endl;
//                 }  
//                 else if(8 * (newx - drag_oldx)>0)
//                 {  
//                     camera_rotation_angle-=0.5;
//                     cout<<"tation"<<endl;
//                 }
//                 if(8 * (newy - drag_oldy) / (height * screen_zoom)<0)
//                   r--;

//                 // reset_screen(0.0);
//         }
//             cout<<"hello"<<endl;
//         } else if (action == GLFW_RELEASE) {
//             cannon_keyboard_input = old_cki;
//             drag_pan = false;
//             drag_oldx = drag_oldy = -1;      
//         }
//         break;

//     default:
//         break;
//     }



// }
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    // Do something
    cout<<yoffset<<endl;
    if(yoffset>0)
    {
        r-=1;
        if(helicoptery-0.4>0.2)
            helicoptery-=0.4;

    }
    else if(yoffset<0)
    {
        r+=1;
        helicoptery+=0.4;

    }
    // cout<<xoffset<<endl;
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(1.0f,1366.0f/768.0f, 0.1f, 400.0f);
    Matrices.projection1 = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
    cout<<left<<" "<<right<<" "<<bottom<<" "<<top<<endl;    

}
