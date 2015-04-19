#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

IplImage* doPyrDown(IplImage* in, int filter = CV_GAUSSIAN_5x5); // pyramid down -- decrease image size by 2
IplImage* doCanny( IplImage* in, double lowThresh, double highThresh, double aperture);
void change_blue_channel_in_roi(IplImage* in, CvRect& roi);

int main(int argc, char** argv){
	// Part 1
	// IplImage* img = cvLoadImage(argv[1]);
	// cvNamedWindow("Before", CV_WINDOW_AUTOSIZE);
	// cvNamedWindow("After", CV_WINDOW_AUTOSIZE);
	// IplImage* imgTransformed = doPyrDown(img);
	// cvShowImage("Before", img);
	// cvShowImage("After", imgTransformed);
	// cvWaitKey(0); // wait for some button to be pressed
	// cvReleaseImage(&img);
	// cvReleaseImage(&imgTransformed);

	// Part 2
	// IplImage* imgPart2 = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	// IplImage* img1 = doPyrDown( imgPart2, CV_GAUSSIAN_5x5 ); 
	// IplImage* img3 = doCanny( img1, 10, 100, 3 );
	// cout << "did canny..." << endl;
	// cvNamedWindow("Before", CV_WINDOW_AUTOSIZE);
	// cvNamedWindow("After", CV_WINDOW_AUTOSIZE);
	// cvShowImage("Before", imgPart2);
	// cvShowImage("After", img3);
	// cvWaitKey(0);
	// cvReleaseImage(&imgPart2);
	// cvReleaseImage(&img1); 
	// cvReleaseImage(&img3);

	// Part 3
	IplImage* imgPart3 = cvLoadImage(argv[1]);
	CvRect roi = cvRect(0, 0, 150, 150);
	change_blue_channel_in_roi(imgPart3, roi); // x=0, y=0, width=150, height=150
	cvReleaseImage(&imgPart3);
	return 0;
}

/* Use Image ROI to increase the blue channel in all pixels in the region */
void change_blue_channel_in_roi(IplImage* in, CvRect& roi){
	cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Changed", CV_WINDOW_AUTOSIZE);
	cvSetImageROI(in, roi);
	IplImage* changedImg; // the output image that will be changeds
	int scalarInt = 150;
	cvAddS(in, cvScalar(scalarInt), changedImg); // change the blue channel
	cvResetImageROI(in); // reset the ROI so that changes aren't restricted to the roi anymore
	cout << "before showing the image..." << endl;
	cvShowImage("Original", in);
	cvShowImage("Changed", changedImg);
	cvWaitKey(0);
	cvReleaseImage(&changedImg); // release the memory allocated for the image
}

IplImage* doPyrDown(IplImage* in, int filter){
	// Best to make sure input image is divisible by two. //
	assert( in->width%2 == 0 && in->height%2 == 0 );
	IplImage* out = cvCreateImage(
		cvSize( in->width/2, in->height/2 ), 
		in->depth,
		in->nChannels
	);
	cvPyrDown( in, out ); 
	return out;
}

IplImage* doCanny( IplImage* in, double lowThresh, double highThresh, double aperture){
	if(in->nChannels != 1) return(0); //Canny only handles gray scale images
	CvSize dim = cvGetSize(in);
	IplImage* out = cvCreateImage( 
		cvSize(dim.width, dim.height), 
		IPL_DEPTH_8U,
		1
	);
	cvCanny( in, out, lowThresh, highThresh, aperture ); 
	return out;
};