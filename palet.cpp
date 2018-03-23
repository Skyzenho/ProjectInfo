#include "palet.h"
// Constructeur
Palet::Palet(float positionX)
{
    posx_=positionX;
    QImage imagetex=QGLWidget::convertToGLFormat(QImage(QString(":/images/Palet.jpg")));
    glGenTextures(1,&Texture_);
    glBindTexture(GL_TEXTURE_2D,Texture_);
    glTexImage2D(GL_TEXTURE_2D,0,3,imagetex.width(),imagetex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,imagetex.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}


void Palet::Display(){
    glPushMatrix();
    glTranslatef(posx_,0,0);
    glTranslatef(0,-28.5,0);//Set position Verticale

    //faire le dessin avec texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,Texture_);

    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);glVertex3f(7.0f, 1.0f, 2.5f);
    glTexCoord2f(1, 0);glVertex3f(-7.0f, 1.0f, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(-7.0f, -1.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(7.0f, -1.0f, 2.5f);


    glTexCoord2f(0, 0);glVertex3f(7.0f, 1.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(7.0f, -1.0f, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-7.0f, -1.0f, -2.5f);
    glTexCoord2f(0, 1);glVertex3f(-7.0f, 1.0f, -2.5f);

    glTexCoord2f(0, 0);glVertex3f(7.0f, -1.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(7.0f, -1.0f, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(-7.0f,-1.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(-7.0f, -1.0f, -2.5f);

    glTexCoord2f(0, 0);glVertex3f(7.0f, 1.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(-7.0f, 1.0f, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-7.0f, 1.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(7.0f, 1.0f, 2.5f);

    glTexCoord2f(0, 0);glVertex3f(-7.0f, 1.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(-7.0f, -1.0f, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-7.0f, -1.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(-7.0f, 1.0f, 2.5f);

    glTexCoord2f(0, 0);glVertex3f(7.0f, 1.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(7.0f, 1.0f, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(7.0f, -1.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(7.0f, -1.0f, -2.5f);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

void Palet::UpdatePos(float position){
    posx_=position;
}
