#include "palet.h"
// Constructeur
Palet::Palet(float positionX)
{
    posx_=positionX;
}


void Palet::Display(){
    glPushMatrix();
    glTranslatef(posx_,0,0);
    glTranslatef(0,-28.5,0);//Set position Verticale

    glBegin(GL_QUADS);

    glVertex3f(7.0f, 1.0f, 2.5f);
    glVertex3f(-7.0f, 1.0f, 2.5f);
    glVertex3f(-7.0f, -1.0f, 2.5f);
    glVertex3f(7.0f, -1.0f, 2.5f);


    glVertex3f(7.0f, 1.0f, -2.5f);
    glVertex3f(7.0f, -1.0f, -2.5f);
    glVertex3f(-7.0f, -1.0f, -2.5f);
    glVertex3f(-7.0f, 1.0f, -2.5f);

    glVertex3f(7.0f, -1.0f, -2.5f);
    glVertex3f(7.0f, -1.0f, 2.5f);
    glVertex3f(-7.0f,-1.0f, 2.5f);
    glVertex3f(-7.0f, -1.0f, -2.5f);

    glVertex3f(7.0f, 1.0f, -2.5f);
    glVertex3f(-7.0f, 1.0f, -2.5f);
    glVertex3f(-7.0f, 1.0f, 2.5f);
    glVertex3f(7.0f, 1.0f, 2.5f);

    glVertex3f(-7.0f, 1.0f, -2.5f);
    glVertex3f(-7.0f, -1.0f, -2.5f);
    glVertex3f(-7.0f, -1.0f, 2.5f);
    glVertex3f(-7.0f, 1.0f, 2.5f);


    glVertex3f(7.0f, 1.0f, -2.5f);
    glVertex3f(7.0f, 1.0f, 2.5f);
    glVertex3f(7.0f, -1.0f, 2.5f);
    glVertex3f(7.0f, -1.0f, -2.5f);
    glEnd();

    glPopMatrix();
}

void Palet::UpdatePos(float position){
    posx_=position;
}
