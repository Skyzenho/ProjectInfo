#include "mur.h"

Mur::Mur(float H,float V)
{
    BordH=H;
    BordV=V;
    QImage imagetex=QGLWidget::convertToGLFormat(QImage(QString(":/images/MurFond.jpg")));
    glGenTextures(1,&Texture_);
    glBindTexture(GL_TEXTURE_2D,Texture_);
    glTexImage2D(GL_TEXTURE_2D,0,3,imagetex.width(),imagetex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,imagetex.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void Mur::Display(){

    //faire le dessin avec texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,Texture_);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);glVertex3f(-BordH, -BordV, -30.0f);
    glTexCoord2f(1, 0);glVertex3f(BordH, -BordV, -30.0f);
    glTexCoord2f(1, 1);glVertex3f(BordH,BordV, -30.0f);
    glTexCoord2f(0, 1);glVertex3f(-BordH,BordV, -30.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

bool Mur::VerifieBas(float y){
    if (y<=-BordV-1)return TRUE;
    else return FALSE;
}

float Mur::InteractMur(float x,float y,float angle){

    if(x+1>=BordH) return (180-angle*180/3.1415)*(3.1415/180);//Vérifie Droite
    else if(x<=(-BordH+1)) return (180-angle*180/3.1415)*(3.1415/180);//Vérifie Gauche
    else if(y>=(BordV-1)) return -angle;//Vérifie Haut
    else  return angle;
}
