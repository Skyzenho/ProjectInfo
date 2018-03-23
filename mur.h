#ifndef MUR_H
#define MUR_H

#include <GL/glu.h>
#include <QImage>
#include <QGLWidget>

class Mur
{
public:
    // Constructeur
    Mur(float H,float V);

    // Affichage du brique
    void Display();
    bool VerifieGauche(float x);
    bool VerifieDroite(float x);
    bool VerifieHaut(float y);
    bool VerifieBas(float y);

private:
    float BordH;
    float BordV;
    GLuint Texture_;// ID Texture
};

#endif // MUR_H
