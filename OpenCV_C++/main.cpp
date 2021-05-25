#include <iostream>
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgRes;

	resize(img, imgRes, Size(), 2, 2);
	imshow("Image_resized", imgRes);
	
	
	waitKey();
	return 0;
}