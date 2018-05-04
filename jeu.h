#ifndef JEU_H
#define JEU_H


#include "brique.h"
#include "palet.h"
#include "boule.h"
#include "mur.h"
#include <QDebug>

class Jeu
{
public:
    // Constructeur
    Jeu();

    void Init();
    void MovePalet(float Pos);
    void Display();
    void Joue();
    void VerifiEtat();
    int GetScore();
    int GetVie();
private:
    //Les objets du jeux
    Palet *Palet_;
    Boule *Boule_;
    Mur *Mur_;
    int Score_;
    int Vie_;
    // Liste des Briques
    std::vector<Brique *> v_Brique;

};

#endif // JEU_H
