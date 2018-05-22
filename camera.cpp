#include "camera.h"

Camera::Camera(){
        int frameWidth=320;
        int frameHeight=240;
        int subImageWidth=100;
        int subImageHeight=100;
        int templateWidth=25;
        int templateHeight=25;

        workingRect=new Rect((frameWidth-subImageWidth)/4,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
        workingRect1=new Rect(((frameWidth-subImageWidth)/4)*3,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
        workingRect2=new Rect(((frameWidth-subImageWidth)/4)*2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);

        templateRect=new Rect((workingRect->width-templateWidth)/2,(workingRect->height-templateHeight)/2,templateWidth,templateHeight);
        templateRect1=new Rect((workingRect1->width-templateWidth)/2,(workingRect1->height-templateHeight)/2,templateWidth,templateHeight);
        templateRect2=new Rect((workingRect2->width-templateWidth)/2,(workingRect2->height-templateHeight)/2,templateWidth,templateHeight);

        workingCenter=new Point(workingRect->x+subImageWidth/2,workingRect->y+subImageHeight/2);
        workingCenter1=new Point(workingRect1->x+subImageWidth/2,workingRect1->y+subImageHeight/2);
        workingCenter2=new Point(workingRect2->x+subImageWidth/2,workingRect2->y+subImageHeight/2);

        cap.open(0); // open the default camera
        cout<<"width :"<<cap.get(CV_CAP_PROP_FRAME_WIDTH)<<endl;
        cout<<"height :"<<cap.get(CV_CAP_PROP_FRAME_HEIGHT)<<endl;
        cap.set(CV_CAP_PROP_FRAME_WIDTH,frameWidth);
        cap.set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight);
        if(!cap.isOpened())  // check if we succeeded
        {
            cerr<<"Error openning the default camera"<<endl;
        }

        // Get frame1
        cap >> frame1;
        // Get frame3
        cap >> frame3;
        // Get frame5
        cap >> frame5;

        // Mirror effect
        cv::flip(frame1,frame1,1);
        // Mirror effect
        cv::flip(frame3,frame3,1);
        // Mirror effect
        cv::flip(frame5,frame5,1);

        // Extract rect1 and convert to gray
        cv::cvtColor(Mat(frame1,*workingRect),frameRect1,COLOR_BGR2GRAY);
        cv::cvtColor(Mat(frame3,*workingRect1),frameRect3,COLOR_BGR2GRAY);
        cv::cvtColor(Mat(frame5,*workingRect2),frameRect5,COLOR_BGR2GRAY);

        // Create the matchTemplate image result
            // to store the matchTemplate result
        int result_cols =  frame1.cols-templateWidth  + 1;
        int result_rows = frame1.rows-templateHeight + 1;
        resultImage.create( result_cols, result_rows, CV_32FC1 );

          // to store the matchTemplate result
        int result_cols1 =  frame3.cols-templateWidth  + 1;
        int result_rows1 = frame3.rows-templateHeight + 1;
        resultImage1.create( result_cols1, result_rows1, CV_32FC1 );

          // to store the matchTemplate result
        int result_cols2 =  frame5.cols-templateWidth  + 1;
        int result_rows2 = frame5.rows-templateHeight + 1;
        resultImage2.create( result_cols2, result_rows2, CV_32FC1 );


        // the camera will be deinitialized automatically in VideoCapture destructor
}

void Camera::Update(){
    // Get frame2
    if(cap.read(frame2)){

    // Mirror effect
    cv::flip(frame2,frame2,1);

    // Extract working rect in frame2 and convert to gray
    cv::cvtColor(Mat(frame2,*workingRect),frameRect2,COLOR_BGR2GRAY);
    cv::cvtColor(Mat(frame2,*workingRect1),frameRect4,COLOR_BGR2GRAY);
    cv::cvtColor(Mat(frame2,*workingRect2),frameRect6,COLOR_BGR2GRAY);

    // Extract template image in frame1
    Mat templateImage(frameRect1,*templateRect);
    Mat templateImage1(frameRect3,*templateRect1);
    Mat templateImage2(frameRect5,*templateRect2);

    // Do the Matching between the working rect in frame2 and the templateImage in frame1
    matchTemplate( frameRect2, templateImage, resultImage, TM_CCORR_NORMED );
    matchTemplate( frameRect4, templateImage1, resultImage1, TM_CCORR_NORMED );
    matchTemplate( frameRect6, templateImage2, resultImage2, TM_CCORR_NORMED );

    // Localize the best match with minMaxLoc
    double minVal; double maxVal; Point minLoc; Point maxLoc;
    minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);

    double minVal1; double maxVal1; Point minLoc1; Point maxLoc1;
    minMaxLoc( resultImage1, &minVal1, &maxVal1, &minLoc1, &maxLoc1);

    double minVal2; double maxVal2; Point minLoc2; Point maxLoc2;
    minMaxLoc( resultImage2, &minVal2, &maxVal2, &minLoc2, &maxLoc2);

    // Compute the translation vector between the origin and the matching rect
    Point vect(maxLoc.x-templateRect->x,maxLoc.y-templateRect->y);
    Point vect1(maxLoc1.x-templateRect1->x,maxLoc1.y-templateRect1->y);
    Point vect2(maxLoc2.x-templateRect2->x,maxLoc2.y-templateRect2->y);

    // Draw rectangle and the translation vector
    rectangle(frame2,*workingRect,Scalar( 0, 255, 0),2);
    rectangle(frame2,*workingRect1,Scalar( 255, 0, 0),2);
    rectangle(frame2,*workingRect2,Scalar( 0, 0, 255),2);

    Point p(workingCenter->x+vect.x,workingCenter->y+vect.y);
    Point p1(workingCenter1->x+vect1.x,workingCenter1->y+vect1.y);
    Point p2(workingCenter2->x+vect2.x,workingCenter2->y+vect2.y);

    arrowedLine(frame2,*workingCenter,p,Scalar(255,255,255),2);
    arrowedLine(frame2,*workingCenter1,p1,Scalar(255,255,255),2);
    arrowedLine(frame2,*workingCenter2,p2,Scalar(255,255,255),2);

    // Swap matrixes
    swap(frameRect1,frameRect2);
    swap(frameRect3,frameRect4);
    swap(frameRect5,frameRect6);
    VectX=(vect.x+vect1.x+vect2.x)/6.0;//Pondération 50%
    }
    else {
        cout<<"Error capturing the frame"<<endl;
    }
}

QImage Camera::GetImage()
{
    return QImage((const unsigned char*)(frame2.data),frame2.cols,frame2.rows,QImage::Format_RGB888);
}


float Camera::GetVectX()
{
 return VectX;
}
