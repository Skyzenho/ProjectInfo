#ifndef CAMERA_H
#define CAMERA_H

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <cstdio>
#include <iostream>
#include <QImage>
#include <QDebug>

using namespace cv;
using namespace std;


class Camera
{
public:
    Camera(); // Constructeur de la caméra

    void Update(); // Mis à jour de la caméra

    float GetVectX(); // Permet de retourner la valeur du vecteur de déplacement sur la caméra

    QImage GetImage(); // Récupère la caméra, pour l’afficher dans la fenêtre principale

private:
    VideoCapture cap; // Définit une nouvelle capture
    Rect *workingRect,*workingRect1,*workingRect2; // Zone de contrôle
    Rect *templateRect,*templateRect1,*templateRect2;
    Point *workingCenter,*workingCenter1,*workingCenter2; // Centres des zones de contrôle

    // Matrices permettant de calculer les déplacements sur chaque zone
    Mat frame1,frame2,frame3,frame5;
    Mat frameRect1,frameRect2;
    Mat frameRect3,frameRect4;
    Mat frameRect5,frameRect6;
    Mat resultImage,resultImage1,resultImage2;

    float VectX; // Valeur du déplacement sur la caméra
};

#endif // CAMERA_H

