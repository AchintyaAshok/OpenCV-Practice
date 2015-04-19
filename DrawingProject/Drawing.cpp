#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

void draw_centered_rectangle(IplImage* img, int width, int height);

int main(int argc, char** argv){
	IplImage* img = cvLoadImage(argv[1], 1);
	draw_centered_rectangle(img, 150, 150);
	cvReleaseImage(&img);
	return 0;
}

void draw_centered_rectangle(IplImage* img, int width, int height){
	int imgWidth = img->width;
	int imgHeight = img->height;
	if(width > imgWidth || height > imgHeight){
		return;
	}
	int widthOffset = 0;
	int heightOffset = 0;
	widthOffset = (imgWidth - width) / 2;
	heightOffset = (imgHeight - height) / 2; // 600 - 150 = 450 / 2 = 225
	cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);
	CvPoint corner1 = cvPoint(widthOffset, heightOffset);
	CvPoint corner2 = cvPoint(widthOffset + width, heightOffset - height); // the opposite corner
	CvScalar color = {256, 0, 0};
	int thickness = 2;
	cvRectangle(img, corner1, corner2, color, thickness);
	cvShowImage("Image", img);
	cvWaitKey(0);
}