#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.h"

    bool   cannon_keyboard_input = true;
    bool   drag_pan = false, old_cki;
    double drag_oldx = -1, drag_oldy = -1,xpos=0,cursor_xpos=0;

using namespace std;

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods) {
    // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {
        // switch (key) {
        // case GLFW_KEY_C:
        // rectangle_rot_status = !rectangle_rot_status;
        // break;
        // case GLFW_KEY_P:
        // triangle_rot_status = !triangle_rot_status;
        // break;
        // case GLFW_KEY_X:
        //// do something ..
        // break;
        // default:
        // break;
        // }
    } else if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_ESCAPE:
            quit(window);
            break;
        default:
            break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar(GLFWwindow *window, unsigned int key) {
    switch (key) {
    case 'Q':
    case 'q':
        quit(window);
        break;
    default:
        break;
    }
}

/* Executed when a mouse button is pressed/released */
// void mouseButton(GLFWwindow *window, int button, int action, int mods) {
//     switch (button) {
//     case GLFW_MOUSE_BUTTON_LEFT:
//         if (action == GLFW_PRESS) {
//             // fire=1;

//             // old_cki = cannon_keyboard_input;
//             // drag_pan = true;
//             // cannon_keyboard_input = true;

//             // Do something
//             return;
//         } else if (action == GLFW_RELEASE) {
//             // Do something
//         }
//         break;
//     // case GLFW_MOUSE_BUTTON_RIGHT:
//     // if (action == GLFW_RELEASE) {
//     // rectangle_rot_dir *= -1;
//     // }
//     // break;
//     default:
//         break;
//     }
// }
void mouseButton(GLFWwindow *window, int button, int action, int mods) {
    switch (button) {
    case GLFW_MOUSE_BUTTON_LEFT:
        if (action == GLFW_PRESS) {
            old_cki = cannon_keyboard_input;
            drag_pan = true;
            cannon_keyboard_input = true;
        } else if (action == GLFW_RELEASE) {
            cannon_keyboard_input = old_cki;
            drag_pan = false;
            drag_oldx = drag_oldy = -1;      
        }
        break;
    // case GLFW_MOUSE_BUTTON_RIGHT:
    // if (action == GLFW_RELEASE) {
    // rectangle_rot_dir *= -1;
    // }
    // break;
    default:
        break;
    }
}
// void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
//             // double x;
//             // double y;
//             // glfwGetCursorPos(window, &x, &y);
//             // cout<<x<<endl;
//             // cout<<y<<endl;
//     // if(left_pressed){
//     //     if(xpos > cursor_xpos) ;
//     //     else if(xpos < cursor_xpos) ;
//     //     cursor_xpos = xpos;
//     // // }
//     // // else{
//     //     if(abs(xpos - cursor_xpos) > 1){
//     //         if(xpos > cursor_xpos) ;
//     //         else if(xpos < cursor_xpos)     ;
//     //         cursor_xpos = xpos;
//     //     }
//     // }
//     cout<<"curser hello"<<endl;
//  }

// void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
//     // Do something
//     cout<<yoffset<<endl;
//     if(yoffset)
//     cout<<xoffset<<endl;
// }

