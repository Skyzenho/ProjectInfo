#ifndef BRIQUE_H
#define BRIQUE_H

#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>
#include <random>
#include <QDebug>

class Brique
{
public:
    // Constructeur
    Brique(float x,float y);

    // Affichage du brique
    void Display();
    float InteractBrique(float x,float y,float angle);
    bool GetEtat();

private:

    float posx_;
    float posy_;
    float Taille_;
    float Hauteur_;
    bool disp_; // Etat du brique. casse ou pas
    GLuint Texture_;// ID Texture
};

#endif // BRIQUE_H
