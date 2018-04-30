#include "jeu.h"

Jeu::Jeu()
{

}

void Jeu::Init(){

    // Ajouter les briques
    for (int i=1;i<=20;i++){
        for(int j=1;j<=8;j++){
            v_Brique.push_back(new Brique(-52.5+5*i,32-2.5*j));
        }
    }
    // Ajouter le palet
    Palet_=new Palet(0);
    // Ajouter le boule
    Boule_=new Boule(0,0,-90);

    Mur_=new Mur(50,30);
    Score_=0;
    Vie_=3;

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
    int count=0;
    if(Mur_->VerifieBas(Boule_->GetY())) VerifiEtat();//qDebug()<<"Fin";
    Boule_->SetAngle(Palet_->InteractPalet(Boule_->GetX(),Boule_->GetY(),Boule_->GetAngle())); //Verifie si le boule hit palet
    for(Brique * it : v_Brique) Boule_->SetAngle(it->InteractBrique(Boule_->GetX(),Boule_->GetY(),Boule_->GetAngle()));
    Boule_->SetAngle(Mur_->InteractMur(Boule_->GetX(),Boule_->GetY(),Boule_->GetAngle())); //Verifie si le boule hit le mur
    Boule_->Update();
    for(Brique * it : v_Brique) if(!it->GetEtat())count++;
    Score_=count;
}

void Jeu::VerifiEtat(){
    if(Vie_>0){
        delete Boule_;
        Boule_=new Boule(0,0,-90);
        Vie_-=1;
    }
}


int Jeu::GetScore(){
    return Score_;
}
int Jeu::GetVie(){
    return Vie_;
}
