#include "brique.h"

brique::brique(float x,float y)
{
    posx_=x;
    posy_=y;
}

void brique::Display(){
    glPushMatrix();
    glTranslatef(posx_,0,0);
    glTranslatef(0,posy_,0);

    glBegin(GL_QUADS);

    glVertex3f(9.0f, 4.0f, -5.0f);
    glVertex3f( 0.0f, 4.0f, -5.0f);
    glVertex3f( 0.0f, 0.0f, -5.0f);
    glVertex3f(9.0f, 0.0f, -5.0f);


    glVertex3f(9.0f, 4.0f, -7.0f);
    glVertex3f(9.0f, 0.0f, -7.0f);
    glVertex3f( 0.0f, 0.0f, -7.0f);
    glVertex3f( 0.0f, 4.0f, -7.0f);

    glVertex3f(9.0f, 4.0f, -7.0f);
    glVertex3f(9.0f, 4.0f, -5.0f);
    glVertex3f( 0.0f, 4.0f, -5.0f);
    glVertex3f( 0.0f, 4.0f, -7.0f);

    glVertex3f(9.0f, 4.0f, -7.0f);
    glVertex3f( 0.0f, 4.0f, -7.0f);
    glVertex3f( 0.0f, 4.0f, -5.0f);
    glVertex3f(9.0f, 4.0f, -5.0f);

    glVertex3f( 0.0f, 4.0f, -7.0f);
    glVertex3f( 0.0f, 0.0f, -7.0f);
    glVertex3f( 0.0f, 0.0f, -5.0f);
    glVertex3f( 0.0f, 4.0f, - 5.0f);


    glVertex3f(9.0f, 4.0f, -7.0f);
    glVertex3f(9.0f, 4.0f, -5.0f);
    glVertex3f(9.0f, 0.0f, -5.0f);
    glVertex3f(9.0f, 0.0f, -7.0f);
    glEnd();

    glPopMatrix();
}
