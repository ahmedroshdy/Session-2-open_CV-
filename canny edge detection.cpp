// here what i noticed when Threshold increase the edges decrease


#include "opencv2/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;



//global variables
Mat image, gray, detected_edges;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";
void CannyThreshold(int, void*)
{
	/// Reduce noise with a kernel 3x3
	blur(gray, detected_edges, Size(3, 3));

	/// Canny detector
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

	imshow(window_name, detected_edges);
}
int main()
{

	image = imread("image.jpg");
	if (!image.data)
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	cvtColor(image, gray, CV_BGR2GRAY);

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
	CannyThreshold(0, 0);

	/// Wait until user exit program by pressing a key
	waitKey(0);
	return 0;
}
