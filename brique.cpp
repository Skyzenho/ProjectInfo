#include "brique.h"
// Constructeur
Brique::Brique(float x,float y)
{
    posx_=x;
    posy_=y;

}


void Brique::Display(){
    glPushMatrix();
    glTranslatef(posx_,0,0);
    glTranslatef(0,posy_,0);

    glBegin(GL_QUADS);

    glVertex3f(4.5f, 2.0f, 2.5f);
    glVertex3f(-4.5f, 2.0f, 2.5f);
    glVertex3f(-4.5f,-2.0f, 2.5f);
    glVertex3f(4.5f,-2.0f, 2.5f);


    glVertex3f(4.5f, 2.0f, -2.5f);
    glVertex3f(4.5f,-2.0f, -2.5f);
    glVertex3f(-4.5f,-2.0f, -2.5f);
    glVertex3f(-4.5f, 2.0f, -2.5f);

    glVertex3f(4.5f, 2.0f, -2.5f);
    glVertex3f(4.5f, 2.0f, 2.5f);
    glVertex3f(-4.5f, 2.0f, 2.5f);
    glVertex3f(-4.5f, 2.0f, -2.5f);

    glVertex3f(4.5f, 2.0f, -2.5f);
    glVertex3f(-4.5f, 2.0f, -2.5f);
    glVertex3f(-4.5f, 2.0f, 2.5f);
    glVertex3f(4.5f, 2.0f, 2.5f);

    glVertex3f(-4.5f, 2.0f, -2.5f);
    glVertex3f(-4.5f,-2.0f, -2.5f);
    glVertex3f(-4.5f,-2.0f, 2.5f);
    glVertex3f(-4.5f, 2.0f, 2.5f);


    glVertex3f(4.5f, 2.0f, -2.5f);
    glVertex3f(4.5f, 2.0f, 2.5f);
    glVertex3f(4.5f,-2.0f, 2.5f);
    glVertex3f(4.5f,-2.0f, -2.5f);
    glEnd();

    glPopMatrix();
}
