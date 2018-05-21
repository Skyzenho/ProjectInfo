#ifndef BOULE_H
#define BOULE_H

#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>
#include <math.h>
#include <QDebug>

class Boule
{
public:
    // Constructeur
    Boule(float x,float y,float angle);

    // Destructeur
    virtual ~Boule();


    void Display();
    float GetX();
    float GetY();
    float GetAngle();
    void SetAngle(float angle);
    void SetVitesse(float vitesse);
    void Update();

private:
    // Corps de l'objet
    GLUquadric * m_Body = nullptr;

    float posx_;
    float posy_;
    float angle_;
    float Vitesse_;

    GLuint Texture_;// ID Texture

};

#endif // BOULE_H
