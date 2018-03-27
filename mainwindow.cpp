#include "mainwindow.h"
#include "ui_mainwindow.h"
// Constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Pospalet_=0.0f;
    Jeu_.Init();
    ui->widget->SetJeu(&Jeu_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Sortie de l'application
        case Qt::Key_Escape:
        {
            close();//Ferme la fenêtre
            break;
        }

    /*case Qt::Key_P:
        {
        // Activation / Désactivation de l'animation
               if(m_AnimationTimer.isActive())
                  m_AnimationTimer.stop();
               else
                  m_AnimationTimer.start();
               break;
        }*/

        case Qt::Key_Left:
        {
            if (Pospalet_>-43.0f){//Il ne peut pas travesser le mur
                Pospalet_-=1.0f;
                Jeu_.MovePalet(Pospalet_);
            }
            break;
        }
        case Qt::Key_Right:
        {
            if (Pospalet_<43.0f){//Il ne peut pas travesser le mur
              Pospalet_+=1.0f;
              Jeu_.MovePalet(Pospalet_);
            }
            break;
        }
        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    ui->widget->updateGL();
}
