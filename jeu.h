#ifndef JEU_H
#define JEU_H

#include <QTimer>
#include <GL/glu.h>
#include "brique.h"
#include "palet.h"
#include "boule.h"
#include "mur.h"



class Jeu
{
public:
    // Constructeur
    Jeu();

    void Init();
    void MovePalet(float Pos);
    void Display();

private:
    //Les objets du jeux
    Palet *Palet_;
    Boule *Boule_;
    Mur *Mur_;
    // Liste des Briques
    std::vector<Brique *> v_Brique;

};

#endif // JEU_H
