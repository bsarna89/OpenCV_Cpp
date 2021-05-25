#include <iostream>
#include <string>
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main()
{
	string path = "Resources/testface.png";
	Mat img = imread(path);
	Mat imgRes;

	if (img.empty()) { cout << "NO IMAGE FILE LOADED " << endl;}
	else { cout << " IMAGE SUCCESS " << endl; }
	resize(img, imgRes, Size(), 0.7, 0.7);

	CascadeClassifier faceCas;
	faceCas.load("Resources/haarcascade_frontalface_default.xml");
	if (faceCas.empty()) { cout << " NO CASCADE FILE LOADED " << endl; }
	else{ cout << " CASCADE SUCCESS " << endl; }

	vector<Rect> faces_rect;
	faceCas.detectMultiScale(imgRes, faces_rect, 1.1, 10);

	for (unsigned long i = 0; i < faces_rect.size(); i++)
	{
		rectangle(imgRes, faces_rect[i].tl(), faces_rect[i].br(), Scalar(255, 0, 255), 3);
	}
	
	bool check = imwrite("Results/result_1.png", imgRes);
	if (check == false) { cout << " SAVING FILE FAILED " << endl; }
	else { cout << " SAVING SUCCESSFUL " << endl; }

	imshow("Image_resized", imgRes);

	waitKey();
	return 0;
}