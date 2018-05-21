#ifndef MUR_H
#define MUR_H

#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>
#include <math.h>

class Mur
{
public:

    Mur(float H,float V); // Constructeur mur, prenant en entrée si le mur est vertical ou horizontal

    void Display(); // Affichage des murs

    bool VerifieBas(float y); // Vérifie si la boule touche le mur du bas, retourne ainsi un booléen (vrai si touche), prenant en entrée la position en Y de la boule

    float InteractMur(float x,float y,float angle); // Gérant l’interaction entre la boule et les autres murs,, prenant en entrée les positions en X et en Y de la boule, et son angle de déplacement, retourne le nouvel angle de déplacement de la boule

private:

    float BordH; // bord horizontal du jeu
    float BordV; // bord vertical du jeu
    GLuint Texture_;// ID Texture
};

#endif // MUR_H
