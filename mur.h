#ifndef MUR_H
#define MUR_H

#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>
#include <math.h>

class Mur
{
public:
    // Constructeur
    Mur(float H,float V);

    // Affichage du brique
    void Display();
    bool VerifieBas(float y);
    float InteractMur(float x,float y,float angle);

private:
    float BordH;
    float BordV;
    GLuint Texture_;// ID Texture
};

#endif // MUR_H
