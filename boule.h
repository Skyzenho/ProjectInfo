#ifndef BOULE_H
#define BOULE_H

#include <GL/glu.h>

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
};

#endif // BOULE_H
