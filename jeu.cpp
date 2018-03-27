#include "jeu.h"

Jeu::Jeu()
{

}

void Jeu::Init(){

    // Ajouter les briques
    for (int i=1;i<=10;i++){
        for(int j=1;j<=5;j++){
            v_Brique.push_back(new Brique(-55+10*i,32-5*j));
        }
    }
    // Ajouter le palet
    Palet_=new Palet(0);
    // Ajouter le boule
    Boule_=new Boule(0,0,30);

    Mur_=new Mur(50,30);

}


void Jeu::MovePalet(float Pos){
    Palet_->UpdatePos(Pos);
}

void Jeu::Display(){
    Palet_->Display();
    Boule_->Display();
    Mur_->Display();
    for(Brique * it : v_Brique) it->Display();
}

void Jeu::Joue(){
    Boule_->SetAngle(Mur_->InteractMur(Boule_->GetX(),Boule_->GetY(),Boule_->GetAngle()));
    Boule_->Update();
}
