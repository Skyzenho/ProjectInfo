#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include "brique.h"
#include "palet.h"
#include "boule.h"
#include "mur.h"

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);


    void MovePalet(float Pos);

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

private:
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
    //Les objets du jeux
    Palet *Palet_;
    Boule *Boule_;
    Mur *Mur_;
    // Liste des Briques
    std::vector<Brique *> v_Brique;
};

#endif // MYGLWIDGET_H
