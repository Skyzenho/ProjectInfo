#include "mainwindow.h"
#include <QApplication>
#include <ctime>

int main(int argc, char *argv[])
{
    // Initialisation du generateur de nombres aleatoires
        srand(time(nullptr));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
