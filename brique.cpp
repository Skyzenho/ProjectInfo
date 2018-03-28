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
    disp_=TRUE;
}


void Brique::Display(){
    if (disp_){
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
}

float Brique::InteractBrique(float x,float y,float angle){
    if(disp_){
        if((y+1>=(posy_-2))&&(y+1<=(posy_+2))&&(x>=posx_-4.5)&&(x<=posx_+4.5)) {
            disp_=FALSE;
            return -angle;//VerifieBas
        }
        else if((y-1>=(posy_+2))&&(y-1<=(posy_-2))&&(x>=posx_-4.5)&&(x<=posx_+4.5)){
            disp_=FALSE;
            return -angle;//VerifieHaut
        }
        else if((x+1>=(posx_-4.5))&&(x+1<=(posx_+4.5))&&(y>=posy_-2)&&(y<=posy_+2)){
            disp_=FALSE;
            return (180-angle*180/3.1415)*(3.1415/180);//VerifieGauche
        }
        else if((x-1>=(posx_+4.5))&&(x-1<=(posx_-4.5))&&(y>=posy_-2)&&(y<=posy_+2)){
            disp_=FALSE;
            return (180-angle*180/3.1415)*(3.1415/180);//VerifieDroite
        }
        else  return angle;
    }
    else return angle;
}
