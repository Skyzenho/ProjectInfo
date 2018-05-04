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
    void Restart();
    int GetScore();
    int GetVie();
    int GetNivel();
    bool GetEtat();
    void NextLvl();
private:
    void VerifiEtat();


private:
    //Les objets du jeux
    Palet *Palet_;
    Boule *Boule_;
    Mur *Mur_;
    int unsigned Score_;
    int Vie_;
    int Nivel_;
    bool FinPartie;
    // Liste des Briques
    std::vector<Brique *> v_Brique;

};

#endif // JEU_H
