#include "boule.h"
// Constructeur
Boule::Boule(float x,float y)
{
    posx_=x;
    posy_=y;

    // Creation de la quadrique
    m_Body = gluNewQuadric();
}


// Destructeur
Boule::~Boule()
{
    // Destruction de quadrique
    gluDeleteQuadric(m_Body);
}


void Boule::Display(){
    glPushMatrix();

    //Positionne le boule
    glTranslatef(posx_,0,0);
    glTranslatef(0,posy_,0);
    //Affiche le boule

    gluSphere(m_Body, 1.0f, 20, 20);

    glPopMatrix();
}
