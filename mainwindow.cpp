#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

        case Qt::Key_Left:
        {
            break;
        }
        case Qt::Key_Right:
        {
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
