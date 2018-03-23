#include "brique.h"
// Constructeur
Brique::Brique(float x,float y)
{
    posx_=x;
    posy_=y;
    QImage imagetex=QGLWidget::convertToGLFormat(QImage(QString(":/images/Briques.jpg")));
    glGenTextures(1,&Texture_);
    glBindTexture(GL_TEXTURE_2D,Texture_);
    glTexImage2D(GL_TEXTURE_2D,0,3,imagetex.width(),imagetex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,imagetex.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}


void Brique::Display(){
    glPushMatrix();
    glTranslatef(posx_,0,0);
    glTranslatef(0,posy_,0);
    //faire le dessin avec texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,Texture_);
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);glVertex3f(4.5f, 2.0f, 2.5f);
    glTexCoord2f(1, 0);glVertex3f(-4.5f, 2.0f, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(-4.5f,-2.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(4.5f,-2.0f, 2.5f);


    glTexCoord2f(0, 0);glVertex3f(4.5f, 2.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(4.5f,-2.0f, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-4.5f,-2.0f, -2.5f);
    glTexCoord2f(0, 1);glVertex3f(-4.5f, 2.0f, -2.5f);

    glTexCoord2f(0, 0);glVertex3f(4.5f, 2.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(4.5f, 2.0f, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(-4.5f, 2.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(-4.5f, 2.0f, -2.5f);

    glTexCoord2f(0, 0);glVertex3f(4.5f, 2.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(-4.5f, 2.0f, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-4.5f, 2.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(4.5f, 2.0f, 2.5f);

    glTexCoord2f(0, 0);glVertex3f(-4.5f, 2.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(-4.5f,-2.0f, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-4.5f,-2.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(-4.5f, 2.0f, 2.5f);


    glTexCoord2f(0, 0);glVertex3f(4.5f, 2.0f, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(4.5f, 2.0f, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(4.5f,-2.0f, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(4.5f,-2.0f, -2.5f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
