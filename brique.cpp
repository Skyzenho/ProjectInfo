#include "brique.h"
// Constructeur
Brique::Brique(float x,float y)
{
    posx_=x;
    posy_=y;
    Taille_=4.5;
    Hauteur_=1.5;
    int aleatoire = (rand() % 3) + 1;
    if(aleatoire == 1){
        QImage imagetex=QGLWidget::convertToGLFormat(QImage(QString(":/images/Briques.jpg")));
        glGenTextures(1,&Texture_);
        glBindTexture(GL_TEXTURE_2D,Texture_);
        glTexImage2D(GL_TEXTURE_2D,0,3,imagetex.width(),imagetex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,imagetex.bits());
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        disp_=TRUE;
    }
    if(aleatoire == 2){
        QImage imagetex=QGLWidget::convertToGLFormat(QImage(QString(":/images/Briques1.jpg")));
        glGenTextures(1,&Texture_);
        glBindTexture(GL_TEXTURE_2D,Texture_);
        glTexImage2D(GL_TEXTURE_2D,0,3,imagetex.width(),imagetex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,imagetex.bits());
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        disp_=TRUE;
    }
    if(aleatoire == 3){
        QImage imagetex=QGLWidget::convertToGLFormat(QImage(QString(":/images/Briques2.jpg")));
        glGenTextures(1,&Texture_);
        glBindTexture(GL_TEXTURE_2D,Texture_);
        glTexImage2D(GL_TEXTURE_2D,0,3,imagetex.width(),imagetex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,imagetex.bits());
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        disp_=TRUE;
    }

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

    glTexCoord2f(0, 0);glVertex3f(Taille_, Hauteur_, 2.5f);
    glTexCoord2f(1, 0);glVertex3f(-Taille_, Hauteur_, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(-Taille_,-Hauteur_, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(Taille_,-Hauteur_, 2.5f);


    glTexCoord2f(0, 0);glVertex3f(Taille_, Hauteur_, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(Taille_,-Hauteur_, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-Taille_,-Hauteur_, -2.5f);
    glTexCoord2f(0, 1);glVertex3f(-Taille_, Hauteur_, -2.5f);

    glTexCoord2f(0, 0);glVertex3f(Taille_, Hauteur_, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(Taille_, Hauteur_, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(-Taille_, Hauteur_, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(-Taille_, Hauteur_, -2.5f);

    glTexCoord2f(0, 0);glVertex3f(Taille_, Hauteur_, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(-Taille_, Hauteur_, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-Taille_, Hauteur_, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(Taille_, Hauteur_, 2.5f);

    glTexCoord2f(0, 0);glVertex3f(-Taille_, Hauteur_, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(-Taille_,-Hauteur_, -2.5f);
    glTexCoord2f(1, 1);glVertex3f(-Taille_,-Hauteur_, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(-Taille_, Hauteur_, 2.5f);


    glTexCoord2f(0, 0);glVertex3f(Taille_, Hauteur_, -2.5f);
    glTexCoord2f(1, 0);glVertex3f(Taille_, Hauteur_, 2.5f);
    glTexCoord2f(1, 1);glVertex3f(Taille_,-Hauteur_, 2.5f);
    glTexCoord2f(0, 1);glVertex3f(Taille_,-Hauteur_, -2.5f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    }
}

float Brique::InteractBrique(float x,float y,float angle){
    if(disp_){
        if(((y+0.707>=(posy_-Hauteur_))&&(y+0.707<=(posy_+Hauteur_))&&(x-0.707>=posx_-Taille_)&&(x-0.707<=posx_+Taille_))||((y+1>=(posy_-Hauteur_))&&(y+1<=(posy_+Hauteur_))&&(x>=posx_-Taille_)&&(x<=posx_+Taille_))||((y+0.707>=(posy_-Hauteur_))&&(y+0.707<=(posy_+Hauteur_))&&(x+0.707>=posx_-Taille_)&&(x+0.707<=posx_+Taille_))) {
            disp_=FALSE;
            return -angle;//VerifieBas brique
        }
        else if(((y-0.707>=(posy_-Hauteur_))&&(y-0.707<=(posy_+Hauteur_))&&(x-0.707>=posx_-Taille_)&&(x-0.707<=posx_+Taille_))||((y-1>=(posy_+Hauteur_))&&(y-1<=(posy_-Hauteur_))&&(x>=posx_-Taille_)&&(x<=posx_+Taille_))||((y-0.707>=(posy_-Hauteur_))&&(y-0.707<=(posy_+Hauteur_))&&(x+0.707>=posx_-Taille_)&&(x+0.707<=posx_+Taille_))){
            disp_=FALSE;
            return -angle;//VerifieHaut brique
        }
        else if(((x+0.707>=(posx_-Taille_))&&(x+0.707<=(posx_+Taille_))&&(y+0.707>=posy_-Hauteur_)&&(y+0.707<=posy_+Hauteur_))||((x+1>=(posx_-Taille_))&&(x+1<=(posx_+Taille_))&&(y>=posy_-Hauteur_)&&(y<=posy_+Hauteur_))||((x+0.707>=(posx_-Taille_))&&(x+0.707<=(posx_+Taille_))&&(y-0.707>=posy_-Hauteur_)&&(y-0.707<=posy_+Hauteur_))){
            disp_=FALSE;
            return (180-angle*180/3.1415)*(3.1415/180);//VerifieGauche brique
        }
        else if(((x-0.707>=(posx_-Taille_))&&(x-0.707<=(posx_+Taille_))&&(y+0.707>=posy_-Hauteur_)&&(y+0.707<=posy_+Hauteur_))||((x-1>=(posx_+Taille_))&&(x-1<=(posx_-Taille_))&&(y>=posy_-Hauteur_)&&(y<=posy_+Hauteur_))||((x-0.707>=(posx_-Taille_))&&(x-0.707<=(posx_+Taille_))&&(y-0.707>=posy_-Hauteur_)&&(y-0.707<=posy_+Hauteur_))){
            disp_=FALSE;
            return (180-angle*180/3.1415)*(3.1415/180);//VerifieDroite brique
        }
        else  return angle;
    }
    else return angle;
}


bool Brique::GetEtat(){
    return disp_;
}
