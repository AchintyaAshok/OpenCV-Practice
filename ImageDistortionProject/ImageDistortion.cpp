#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
	IplImage* originalImage = cvLoadImage(argv[1]);
	cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Distorted", CV_WINDOW_AUTOSIZE);
	cvShowImage("Original", originalImage);
	IplImage* distortedImage = cvCreateImage( cvGetSize(originalImage), IPL_DEPTH_8U, 3);
	cvSmooth( originalImage, distortedImage, CV_GAUSSIAN, 3, 3 ); // distort the image
	cvShowImage("Distorted", distortedImage);
	while(char key = cvWaitKey(0)){
		if(key == 27){
			cvDestroyWindow("Original");
			cvDestroyWindow("Distorted");
			cvReleaseImage(&originalImage);
			cvReleaseImage(&distortedImage);
			break;
		}
	}
	return 0;
}
