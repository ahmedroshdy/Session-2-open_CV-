#include "opencv2/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


void main(){

	//first method  edge detection  by implmentation convolution
	Mat image,kernel;
// Mat gray ;
	 image = imread("image.jpg");
	// cvtColor(image, gray, CV_BGR2GRAY); if we want edge detection after conversion to grey
		 if(! image.data )
		 {
						cout <<  "Could not open or find the image" << std::endl ;
						return -1;
		 }
	// kernel = (Mat_<double>(3, 3) << 0, 1, 0, 1, -4, 1, 0, 1, 0); // it is found on internet but not sharp edges
	 kernel = (Mat_<double>(3, 3) << 1, 1, 1, 1, -8, 1, 1, 1, 1); // it is on session , more sharpness
 //filter2D(gray, gray, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	 filter2D(image, image, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	 namedWindow("myimg", CV_WINDOW_AUTOSIZE);
	// imshow("myimg", gray);
	 imshow("myimg", image);
	 cvWaitKey(0);
	 
   }
