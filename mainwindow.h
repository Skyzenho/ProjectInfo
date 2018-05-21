#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jeu.h"
#include "camera.h"
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); // Constructeur

    ~MainWindow(); // Destructeur

    void AfficheScore(); // Permet l’affichage du score du joueur sur la fenêtre

protected:

    void keyPressEvent(QKeyEvent * event); // Fonction de gestion d'interaction clavier

private slots:
    void on_Start_clicked(); // Slot permettant de gérer l’évènement de clic sur le bouton start

    void on_Level_clicked(); // Slot permettant de gérer l’évènement de clic sur le bouton niveau

private:

    Ui::MainWindow *ui; // ui de la classe MainWindow
    Jeu Jeu_; // Variable jeu, affiché dans cette fenêtre
    float m_TimeElapsed { 0.0f }; // Timer d'animation
    QTimer m_AnimationTimer;
    Camera *Camera_; // Variable Caméra, affiché dans cette fenêtre
};

#endif // MAINWINDOW_H

