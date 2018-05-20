#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jeu.h"
#include "camera.h"
#include "configwindow.h"
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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AfficheScore();

protected:
    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);
private slots:
    void on_Start_clicked();

    void on_Config_clicked();

    void openConfiguration();


private:
    Ui::MainWindow *ui;
    Jeu Jeu_;
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
    Camera *Camera_;
};

#endif // MAINWINDOW_H
