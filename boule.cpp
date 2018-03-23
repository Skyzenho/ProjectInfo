#include "boule.h"
// Constructeur
Boule::Boule(float x,float y)
{
    posx_=x;
    posy_=y;

    // Creation de la quadrique
    m_Body = gluNewQuadric();
    QImage imagetex=QGLWidget::convertToGLFormat(QImage(QString(":/images/Boule.jpg")));
    glGenTextures(1,&Texture_);
    glBindTexture(GL_TEXTURE_2D,Texture_);
    glTexImage2D(GL_TEXTURE_2D,0,3,imagetex.width(),imagetex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,imagetex.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    gluQuadricTexture(m_Body, GL_TRUE);

}


// Destructeur
Boule::~Boule()
{
    // Destruction de quadrique
    gluDeleteQuadric(m_Body);
}


void Boule::Display(){
    glPushMatrix();

    //Positionne le boule
    glTranslatef(posx_,0,0);
    glTranslatef(0,posy_,0);
    //Affiche le boule
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Texture_);
    gluSphere(m_Body, 1.0f, 20, 20);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}
