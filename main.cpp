#include "mainwindow.h"
#include <QApplication>
#include <ctime>

int main(int argc, char *argv[])
{
    // Initialisation du générateur de nombres aléatoires
       srand(time(nullptr));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
