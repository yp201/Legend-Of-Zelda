#include "main.h"

#ifndef SCORE_H
#define SCORE_H


class Score {
public:
    Score() {}
    Score(float x, float y);
    float rotation;
    glm::vec3 position;
    void draw(glm::mat4 VP,int no);
private:
    VAO *digit[8];
};

#endif // SCORE_H
