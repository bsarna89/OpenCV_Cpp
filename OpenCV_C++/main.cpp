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
	imshow("Image", img);
	waitKey();
	return 0;



}