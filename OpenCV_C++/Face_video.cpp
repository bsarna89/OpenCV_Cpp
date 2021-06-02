#include <iostream>
#include <string>
#include <vector>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main()
{
    // VideoCapture for playing video for face detection
    VideoCapture capture;
    Mat frame, image;

    //PreDefined trained XML classifiers with facial features
    CascadeClassifier faceCas;
    
    faceCas.load("Resources/haarcascade_frontalface_default.xml");
    if (faceCas.empty()) { cout << " NO CASCADE FILE LOADED " << endl; }
    else { cout << " CASCADE SUCCESS " << endl; }

   
    capture.open(0);
    if (capture.isOpened())
    {
        cout << "Face Detection Started...." << endl;
        while (1)
        {
            capture >> frame;
            if (frame.empty())
                break;

            vector<Rect> faces_rect;
            faceCas.detectMultiScale(frame, faces_rect, 1.2, 3, 0 | CASCADE_SCALE_IMAGE, Size(60, 60));

            for (unsigned long i = 0; i < faces_rect.size(); i++)
            {
                rectangle(frame, faces_rect[i].tl(), faces_rect[i].br(), Scalar(255, 0, 255), 3);
            }

            char c = (char)waitKey(10);
            imshow("FACE DETECTION", frame);
           
            if (c == 27 || c == 'q' || c == 'Q')
                break;
        }
    }
    else
        cout << "COULD NOT OPEN CAMERA" << endl;
    return 0;

}