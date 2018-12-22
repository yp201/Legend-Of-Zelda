#include "score.h"
#include "main.h"
#include <bits/stdc++.h>
using namespace std;

Score::Score(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation=rotation;
    // static  GLfloat vertex_buffer_data[181*9];
    //     float X=-1.0f,Y=0.0f;
    //     int j=0;
    //     for(int i=0;i<=180;i++)
    //     {
    //         vertex_buffer_data[j++]=X;vertex_buffer_data[j++]=Y; vertex_buffer_data[j++]=0.0f;
    //         float x1=X,y1=Y;

    //         X=x1*cos(3.14/180.0) - y1*sin(3.14/180.0);
    //         Y=x1*sin(3.14/180.0) + y1*cos(3.14/180.0);
    //         vertex_buffer_data[j++]=X; vertex_buffer_data[j++]=Y; vertex_buffer_data[j++]=0.0f;
    //         vertex_buffer_data[j++]=0.0f; vertex_buffer_data[j++]=0.0f;vertex_buffer_data[j++]=0.0f;

    //     }
       static const GLfloat a[] = {
        -0.2, 0.0, 0.0, // vertex 1
        0.2,  0.0, 0.0, // vertex 2
   };
          static const GLfloat b[] = {
        0.2, 0.0, 0.0, // vertex 1
        0.2,  -0.2, 0.0, // vertex 2
   };
       static const GLfloat c[] = {
        0.2,  -0.2, 0.0, // vertex 2
        -0.2,  -0.2, 0.0, // vertex 2
   };
       static const GLfloat d[] = {
        -0.2,  -0.2, 0.0, // vertex 2
        -0.2, 0.0, 0.0, // vertex 1
   };
       static const GLfloat e[] = {
        -0.2,  -0.2, 0.0, // vertex 2
        -0.2,  -0.4, 0.0, // vertex 2
   };
       static const GLfloat f[] = {
        -0.2,  -0.4, 0.0, // vertex 2
        0.2,  -0.4, 0.0, // vertex 2
   };
       static const GLfloat g[] = {
        0.2,  -0.4, 0.0, // vertex 2
        0.2,  -0.2, 0.0, // vertex 2
   };



    this->digit[1] = create3DObject(GL_LINES, 2, a, {0,0,0}, GL_FILL);
    this->digit[2] = create3DObject(GL_LINES, 2, b, {0,0,0}, GL_FILL);
    this->digit[3] = create3DObject(GL_LINES, 2, c, {0,0,0}, GL_FILL);
    this->digit[4] = create3DObject(GL_LINES, 2, d, {0,0,0}, GL_FILL);
    this->digit[5] = create3DObject(GL_LINES, 2, e, {0,0,0}, GL_FILL);
    this->digit[6] = create3DObject(GL_LINES, 2, f, {0,0,0}, GL_FILL);
    this->digit[7] = create3DObject(GL_LINES, 2, g, {0,0,0}, GL_FILL);

}

void Score::draw(glm::mat4 VP,int no) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0,0, 0));
    Matrices.model *= (translate );
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    int digits[8]={0};
    switch (no)
    {
        case 0:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[1]=digits[2]=digits[4]=digits[5]=digits[6]=digits[7]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 1:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[2]=digits[7]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 2:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[1]=digits[2]=digits[3]=digits[5]=digits[6]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 3:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[1]=digits[2]=digits[3]=digits[6]=digits[7]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 4:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[4]=digits[2]=digits[3]=digits[7]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 5:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[1]=digits[3]=digits[4]=digits[6]=digits[7]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 6:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[1]=digits[4]=digits[5]=digits[6]=digits[7]=digits[3]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 7:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[1]=digits[2]=digits[7]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 8:
        {
            for(int i=1;i<=7;i++)digits[i]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 9:
        {
            for(int i=1;i<=7;i++)digits[i]=1;
            digits[5]=digits[6]=0;;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }
        case 10:
        {
            for(int i=1;i<=7;i++)digits[i]=0;
            digits[3]=1;
            for(int i=1;i<=7;i++)
            {
                if(digits[i])
                {
                    draw3DObject(this->digit[i]);
                }
            }
            break;    
        }



    }
}

