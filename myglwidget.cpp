#define _USE_MATH_DEFINES

#include "myglwidget.h"


// Déclarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 50.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Réglage de la taille/position
    //setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Réglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    Jeu_->Init();

}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Définition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Définition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Réinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Définition de la matrice modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    Jeu_->Display();
    if(Jeu_->GetEtat())renderText(450,400,"Game Over",QFont("Helvetica [Cronyx]", 35));
}

void MyGLWidget::SetJeu(Jeu* JeuPtr){
    Jeu_=JeuPtr;
}

