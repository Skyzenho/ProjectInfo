#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>
#include <QDebug>
class Palet
{
public:
    // Constructeur
    Palet(float positionX);
    void Display();
    void UpdatePos(float position);
    float InteractPalet(float x,float y,float angle);
private:
    float posx_;
    GLuint Texture_;// ID Texture
};

#endif // PALET_H
