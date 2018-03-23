#ifndef BOULE_H
#define BOULE_H

#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>

class Boule
{
public:
    // Constructeur
    Boule(float x,float y);

    // Destructeur
    virtual ~Boule();


    void Display();

private:
    // Corps de l'objet
    GLUquadric * m_Body = nullptr;

    float posx_;
    float posy_;
    GLuint Texture_;// ID Texture
};

#endif // BOULE_H
