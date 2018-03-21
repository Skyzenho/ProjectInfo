#include "palet.h"

palet::palet(float x,float y)
{
    posx_=x;
    posy_=y;
}


void palet::Display(){
    glPushMatrix();
    glTranslatef(posx_,0,0);
    glTranslatef(0,posy_,0);

    glBegin(GL_QUADS);

    glVertex3f(15.0f, 3.0f, -5.0f);
    glVertex3f( 1.0f, 3.0f, -5.0f);
    glVertex3f( 1.0f, 1.0f, -5.0f);
    glVertex3f(15.0f, 1.0f, -5.0f);


    glVertex3f(15.0f, 3.0f, -7.0f);
    glVertex3f(15.0f, 1.0f, -7.0f);
    glVertex3f( 1.0f, 1.0f, -7.0f);
    glVertex3f( 1.0f, 3.0f, -7.0f);

    glVertex3f(15.0f, 1.0f, -7.0f);
    glVertex3f(15.0f, 1.0f, -5.0f);
    glVertex3f( 1.0f, 1.0f, -5.0f);
    glVertex3f( 1.0f, 1.0f, -7.0f);

    glVertex3f(15.0f, 3.0f, -7.0f);
    glVertex3f( 1.0f, 3.0f, -7.0f);
    glVertex3f( 1.0f, 3.0f, -5.0f);
    glVertex3f(15.0f, 3.0f, -5.0f);

    glVertex3f( 1.0f, 3.0f, -7.0f);
    glVertex3f( 1.0f, 1.0f, -7.0f);
    glVertex3f( 1.0f, 1.0f, -5.0f);
    glVertex3f( 1.0f, 3.0f, - 5.0f);


    glVertex3f(15.0f, 3.0f, -7.0f);
    glVertex3f(15.0f, 3.0f, -5.0f);
    glVertex3f(15.0f, 1.0f, -5.0f);
    glVertex3f(15.0f, 1.0f, -7.0f);
    glEnd();

    glPopMatrix();
}
