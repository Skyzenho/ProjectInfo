#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jeu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);
private:
    Ui::MainWindow *ui;
    float Pospalet_;
    Jeu Jeu_;
};

#endif // MAINWINDOW_H
