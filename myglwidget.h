#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
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

    Palet *Palet_;
    Boule *Boule_;
    Mur *Mur_;
    // Liste des planetes
    std::vector<Brique *> v_Brique;
};

#endif // MYGLWIDGET_H
