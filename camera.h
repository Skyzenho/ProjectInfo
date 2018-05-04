#ifndef CAMERA_H
#define CAMERA_H

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <cstdio>
#include <iostream>
#include <QImage>


using namespace cv;
using namespace std;


class Camera
{
public:
    Camera();

    void Update();
    QImage GetImage();
private:
    VideoCapture cap;
    Rect *workingRect,*workingRect1,*workingRect2;
    Rect *templateRect,*templateRect1,*templateRect2;
    Point *workingCenter,*workingCenter1,*workingCenter2;

    Mat frame1,frame2,frame3,frame5;
    Mat frameRect1,frameRect2;
    Mat frameRect3,frameRect4;
    Mat frameRect5,frameRect6;
    Mat resultImage,resultImage1,resultImage2;

};

#endif // CAMERA_H
