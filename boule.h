#ifndef BOULE_H
#define BOULE_H
#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>
#include <math.h>

class Boule
{
public:
    // Constructeur de la boule
    Boule(float x,float y,float angle); //Prend en paramètres d’entrée l’angle, et les positions en X et en Y de la boule dans la fenêtre d’affichage

    // Destructeur de la boule
    virtual ~Boule();

    void Display(); // Affichage de la boule

    float GetX(); // Permet de récupérer la position en X de la boule, retourne un float

    float GetY(); // Permet de récupérer la position en Y de la boule, retourne un float

    float GetAngle(); // Permet de récupérer l’angle de déplacement de la boule, retourne un float

    void SetAngle(float angle); // Set de l’angle de la boule

    void SetVitesse(float vitesse); // Set de la vitesse en fonction du niveau choisi par l’utilisateur

    void Update(); // Met à jour les positions en X et en Y de la boule

private:
    // Corps de l'objet
    GLUquadric * m_Body = nullptr;
    float posx_; // Position X de la boule
    float posy_; // Position Y de la boule
    float angle_; // Angle de déplacement de la boule
    float Vitesse_; // Vitesse de la boule

    GLuint Texture_;// ID Texture

};

#endif // BOULE_H

