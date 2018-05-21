#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>
#include <QDebug>
class Palet
{
public:

    Palet(float positionX); // Constructeur du palet, prenant en entrée la position initiale du palet

    void Display(); // Dessine le palet en le définissant

    void UpdatePos(float position); // Permet de mettre à jour la position du palet, prenant en entrée la nouvelle position

    float InteractPalet(float x,float y,float angle); // Permet l’interaction entre la boule et le palet, prenant en entrée les positions en X et en Y de la boule, ainsi que son angle de déplacement, et retournant le nouvel angle de déplacement de celle-ci

private:

    float posx_; // Position en X du palet
    GLuint Texture_;// ID Texture
};

#endif // PALET_H
