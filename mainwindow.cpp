#include "mainwindow.h"
#include "ui_mainwindow.h"
// Constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Camera_=new Camera();
    ui->widget->SetJeu(&Jeu_);
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
            m_TimeElapsed += 0.025f;

            Camera_->Update();
            Jeu_.UpdatePalet(Camera_->GetVectX());
            Jeu_.Joue();
            AfficheScore();
            ui->widget->updateGL();
            if(Jeu_.GetEtat())m_AnimationTimer.stop();
        });
    m_AnimationTimer.setInterval(25);
    m_AnimationTimer.start();
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

        case Qt::Key_P:
        {
        // Activation / Désactivation de l'animation
               if(m_AnimationTimer.isActive())
                  m_AnimationTimer.stop();
               else
                  m_AnimationTimer.start();
               break;
        }

        case Qt::Key_A:
        {
            Jeu_.UpdatePalet(-1);
        break;
        }
        case Qt::Key_D:
        {
              Jeu_.UpdatePalet(1);
        break;
        }

        // Cas par défaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'évènement et mise à jour de la scène
    event->accept();
    ui->widget->updateGL();
}

void MainWindow::AfficheScore(){
    QString Text;
    Text="Time: "+QString::number(m_TimeElapsed,'f',2)+"s";
    ui->Time->setText(Text);
    Text="Score: "+QString::number(Jeu_.GetScore())+" Vies: "+QString::number(Jeu_.GetVie());
    ui->Stats->setText(Text);
    Text="Nivel: "+QString::number(Jeu_.GetNivel());
    ui->Nivel->setText(Text);
    ui->ImageLabel->setPixmap(QPixmap::fromImage(Camera_->GetImage()));
    ui->ImageLabel->resize(ui->ImageLabel->pixmap()->size());
}

void MainWindow::on_Start_clicked()
{
    Jeu_.Restart();
    m_TimeElapsed=0.0;
    m_AnimationTimer.start();
}


void MainWindow::on_Level_clicked()
{
    Jeu_.NextLvl();
}
