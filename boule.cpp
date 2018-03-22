#include "boule.h"

Boule::Boule(float x,float y)
{
    posx_=x;
    posy_=y;
}

void Boule::Display(){
    glPushMatrix();

    //Positionne le boule
    glTranslatef(posx_,0,0);
    glTranslatef(0,posy_,0);
    //Affiche le boule
    GLUquadric* sphere = gluNewQuadric();
    gluSphere(sphere, 1.0f, 20, 20);
    gluDeleteQuadric(sphere);

    glPopMatrix();
}
