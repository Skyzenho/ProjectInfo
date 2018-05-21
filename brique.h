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
    Brique(float x,float y); // Prend en paramètre la position en X et en Y de chaque brique, permet de créer chaque brique

    void Display(); // Affichage des briques, avec des GL_QUADS

    float InteractBrique(float x,float y,float angle); // Définit les interactions entre la boule et les briques, prend en paramètres d’entrée les positions en X et en Y de la boule et son angle de déplacement, et renvoie un float correspondant au nouvel angle de déplacement de la boule

    bool GetEtat(); // Retourne Vrai si la brique n’a pas encore été détruite, faux sinon

private:

    float posx_; // Position en X de la brique
    float posy_; // Position en Y de la brique
    float Taille_; // Largeur de la brique
    float Hauteur_; // Hauteur de la brique
    bool disp_; // Etat de la brique (détruite ou non)
    GLuint Texture_;// ID Texture
};

#endif // BRIQUE_H

