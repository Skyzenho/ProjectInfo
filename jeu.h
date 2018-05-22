#ifndef JEU_H
#define JEU_H


#include "brique.h"
#include "palet.h"
#include "boule.h"
#include "mur.h"

class Jeu
{
public:
    Jeu(); // Constructeur

    void Init(); // Initialisation des variables du jeu, et ajoute les composants du casse-brique

    void Display(); // Affichage des composants du casse-brique

    void Joue(); // Gère les interactions de la boule, l’affichage des briques si elles sont détruites, et le score est mis à jour.
    void Restart(); // Supprime les composants du jeu, et réinitialise le jeu

    void UpdatePalet(float Pos); // Met à jour la position du palet en appelant la méthode de la classe Palet, et gère le déplacement sur les bords de la fenêtre

    int GetScore(); // Retourne un entier correspondant au score du joueur

    int GetVie(); // Retourne un entier correspondant au nombre de vies du joueur

    int GetNivel(); // Retourne un entier correspondant au niveau du joueur

    bool GetEtat(); // Retourne un booléen, si la partie est terminée ou non

    void NextLvl(); // Permet de définir la nouvelle vitesse de déplacement de la boule, si l’utilisateur augmente le niveau

private:
    void VerifieEtat(); // Gère la partie suivant le nombre de vies du joueur


private:

    //Les objets du jeux
    Palet *Palet_;
    Boule *Boule_;
    Mur *Mur_;
    float Pospalet_; // Position du palet dans la fenêtre
    int unsigned Score_; // Score du joueur
    int Vie_; // Vies du joueur
    int Nivel_; // Niveau du joueur
    bool FinPartie; // Vrai si fin de partie
    // Liste des Briques
    std::vector<Brique *> v_Brique;

};

#endif // JEU_H

